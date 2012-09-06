////////////////////////////////////////////////////////
/// Extracts the average occupancy of each lcn channel.
/// P G Jones <p.g.jones@qmul.ac.uk>
///
/// 31/05/2012 : New File
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
FillHistogram( RAT::DS::EV* rEV,
               TH1D* aveOccupy );

void
LoadRootFile( const char* lpFile,
              TTree **tree,
              RAT::DS::Root **rDS,
              RAT::DS::Run **rRun );

void 
ExtractAveOccupancy( const char* inFile,
                     const char* outFile )
{
  // Load the root file first
  RAT::DS::Root* rDS;
  RAT::DS::Run* rRun;
  TTree *tree;
  LoadRootFile( inFile, &tree, &rDS, &rRun );
  
  time_t codeStart = time( NULL );
  TH1D* aveOccupy = new TH1D( "aveOccupy", "aveOccupy", 10000, 0.0, 10000.0 );

  for( int iEvent = 0; iEvent < tree->GetEntries(); iEvent++ )
    {
      if( iEvent % 100 == 0 )
        cout << iEvent << " finished at " << time( NULL ) - codeStart << endl;
      tree->GetEntry( iEvent );
      for( int iEV = 0; iEV < rDS->GetEVCount(); iEV++ )
        FillHistogram( rDS->GetEV( iEV ), aveOccupy );
    }
  aveOccupy->Sumw2();
  aveOccupy->Scale( 1.0 / (double) tree->GetEntries() );
  TFile outputFile( outFile, "RECREATE" );
  outputFile.cd();
  aveOccupy->Write();
  outputFile.Close();
}

void
FillHistogram( RAT::DS::EV* rEV,
               TH1D* aveOccupy )
{
  for( int iPMT = 0; iPMT < rEV->GetPMTAllCalCount(); iPMT++ )
    {
      aveOccupy->Fill( rEV->GetPMTAllCal( iPMT )->GetID() );
    }
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
