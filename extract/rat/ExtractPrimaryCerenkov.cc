////////////////////////////////////////////////////////
/// Extracts the Cerenkov photons produced for the primary
/// electron
/// P G Jones <p.g.jones@qmul.ac.uk>
///
/// 18/09/2012 : New File
////////////////////////////////////////////////////////

#include <RAT/DS/Root.hh>
#include <RAT/DS/MC.hh>
#include <RAT/DS/Run.hh>

#include <TH1D.h>
#include <TTree.h>
#include <TFile.h>

#include <time.h>
using namespace std;

void
FillHistogram( RAT::DS::MC* rMC,
               TH1D* nCer );

void
LoadRootFile( const char* lpFile,
              TTree **tree,
              RAT::DS::Root **rDS,
              RAT::DS::Run **rRun );

void 
ExtractPrimaryCerenkov( const char* inFile,
                        const char* outFile )
{
  // Load the root file first
  RAT::DS::Root* rDS;
  RAT::DS::Run* rRun;
  TTree *tree;
  LoadRootFile( inFile, &tree, &rDS, &rRun );
  
  time_t codeStart = time( NULL );
  TH1D* nCer = new TH1D( "numCer", "numCer", 4000, 0.0, 4000.0 );

  for( int iEvent = 0; iEvent < tree->GetEntries(); iEvent++ )
    {
      if( iEvent % 100 == 0 )
        cout << iEvent << " finished at " << time( NULL ) - codeStart << endl;
      tree->GetEntry( iEvent );
      FillHistogram( rDS->GetMC(), nCer );
    }

  TFile outputFile( outFile, "RECREATE" );
  outputFile.cd();
  nCer->Write();
  outputFile.Close();
}

void
FillHistogram( RAT::DS::MC* rMC,
               TH1D* nCer )
{
  int eTracks = 0;
  int cerCount = 0;
  for( int iTrack = 0; iTrack < rMC->GetMCTrackCount(); iTrack++ )
    {
      if( rMC->GetMCTrack( iTrack )->GetPDGCode() == 11 )
        eTracks++;
      if( rMC->GetMCTrack( iTrack )->GetPDGCode() == 0 && rMC->GetMCTrack( iTrack )->GetParentID() == 1 ) 
        // Primary electron has track ID 1 photons are PDG 0
        cerCount++;
    }
  cout << eTracks << endl;
  nCer->Fill( cerCount );
}

void
LoadRootFile( const char* lpFile,
              TTree **tree,
              RAT::DS::Root **rDS,
              RAT::DS::Run **rRun )
{
  TFile *file = new TFile( lpFile );
  (*tree) = (TTree*)file->Get( "T" );
  TTree *runTree = (TTree*)file->Get( "runT" );

  *rDS = new RAT::DS::Root();

  (*tree)->SetBranchAddress( "ds", &(*rDS) );

  *rRun = new RAT::DS::Run();

  runTree->SetBranchAddress( "run", &(*rRun) );
  runTree->GetEntry();
}
