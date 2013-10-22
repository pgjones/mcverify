////////////////////////////////////////////////////////
/// Extracts the range of the primary electron in the event.
/// Data is converted into cm!
/// P G Jones <p.g.jones@qmul.ac.uk>
///
/// 17/09/2012 : New File
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
ExtractPrimaryRange( const char* inFile,
                     const char* outFile )
{
  // Load the root file first
  RAT::DS::Root* rDS;
  RAT::DS::Run* rRun;
  TTree *tree;
  LoadRootFile( inFile, &tree, &rDS, &rRun );
  
  time_t codeStart = time( NULL );
  TH1D* range = new TH1D( "range", "range", 10000, 0.0, 1000.0 ); //mm range [0,10]cm

  for( int iEvent = 0; iEvent < tree->GetEntries(); iEvent++ )
    {
      if( iEvent % 100 == 0 )
        cout << iEvent << " finished at " << time( NULL ) - codeStart << endl;
      tree->GetEntry( iEvent );
      FillHistogram( rDS->GetMC(), range );
    }

  TFile outputFile( outFile, "RECREATE" );
  outputFile.cd();
  range->Write();
  outputFile.Close();
}

void
FillHistogram( RAT::DS::MC* rMC,
               TH1D* range )
{
  for( int iTrack = 0; iTrack < rMC->GetMCTrackCount(); iTrack++ )
    if( rMC->GetMCTrack( iTrack )->GetParentID() == 0 ) // Primary electron has parent ID 0
      range->Fill( rMC->GetMCTrack( iTrack )->GetLength() / 10.0 ); // Convert to cm
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
