////////////////////////////////////////////////////////
/// Extracts the ev side nhit per event and saves into a 
/// histogram
/// P G Jones <p.g.jones@qmul.ac.uk>
///
/// 12/07/2012 : New File
////////////////////////////////////////////////////////

#include <RAT/DS/Root.hh>
#include <RAT/DS/EV.hh>
#include <RAT/DS/Run.hh>

#include <TH1D.h>
#include <TTree.h>
#include <TFile.h>

#include <time.h>
using namespace std;

void
FillHistogram( RAT::DS::EV* rMC,
               TH1D* nHits );

void
LoadRootFile( const char* lpFile,
              TTree **tree,
              RAT::DS::Root **rDS,
              RAT::DS::Run **rRun );

void 
ExtractNhit( const char* inFile,
             const char* outFile )
{
  // Load the root file first
  RAT::DS::Root* rDS;
  RAT::DS::Run* rRun;
  TTree *tree;
  LoadRootFile( inFile, &tree, &rDS, &rRun );
  
  time_t codeStart = time( NULL );
  TH1D* nHits = new TH1D( "nHits", "nHits", 10000, 0.0, 10000.0 );

  for( int iEvent = 0; iEvent < tree->GetEntries(); iEvent++ )
    {
      if( iEvent % 100 == 0 )
        cout << iEvent << " finished at " << time( NULL ) - codeStart << endl;
      tree->GetEntry( iEvent );
      for( int iEV = 0; iEV < rDS->GetEVCount(); iEV++ )
        FillHistogram( rDS->GetEV( iEV ), nHits );
    }

  TFile outputFile( outFile, "RECREATE" );
  outputFile.cd();
  nHits->Write();
  outputFile.Close();
}

void
FillHistogram( RAT::DS::EV* rEV,
               TH1D* nHits )
{
  nHits->Fill( rEV->GetPMTCalCount() );
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
