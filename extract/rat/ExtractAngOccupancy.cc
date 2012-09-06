////////////////////////////////////////////////////////
/// Extracts the average occupancy of each lcn channel.
/// P G Jones <p.g.jones@qmul.ac.uk>
///
/// 31/05/2012 : New File
////////////////////////////////////////////////////////

#include <RAT/DS/Root.hh>
#include <RAT/DS/EV.hh>
#include <RAT/DS/Run.hh>
#include <RAT/DS/PMTProperties.hh>

#include <TH1D.h>
#include <TTree.h>
#include <TFile.h>

#include <time.h>
using namespace std;

void
FillHistogram( RAT::DS::EV* rEV,
               RAT::DS::PMTProperties* rPMTList,
               TH1D* angOccupy,
               double xPos,
               double yPos,
               double zPos );

void
LoadRootFile( const char* lpFile,
              TTree **tree,
              RAT::DS::Root **rDS,
              RAT::DS::Run **rRun );

void 
ExtractAngOccupancy( const char* inFile,
                     const char* outFile,
                     double xPos,
                     double yPos,
                     double zPos )
{
  // Load the root file first
  RAT::DS::Root* rDS;
  RAT::DS::Run* rRun;
  TTree *tree;
  LoadRootFile( inFile, &tree, &rDS, &rRun );
  
  time_t codeStart = time( NULL );
  TH1D* angOccupy = new TH1D( "angOccupy", "angOccupy", 360, 0.0, 360.0 );

  for( int iEvent = 0; iEvent < tree->GetEntries(); iEvent++ )
    {
      if( iEvent % 100 == 0 )
        cout << iEvent << " finished at " << time( NULL ) - codeStart << endl;
      tree->GetEntry( iEvent );
      for( int iEV = 0; iEV < rDS->GetEVCount(); iEV++ )
        FillHistogram( rDS->GetEV( iEV ), rRun->GetPMTProp(), angOccupy, xPos, yPos, zPos );
    }
  angOccupy->Sumw2();
  angOccupy->Scale( 1.0 / (double) tree->GetEntries() );
  TFile outputFile( outFile, "RECREATE" );
  outputFile.cd();
  angOccupy->Write();
  outputFile.Close();
}

void
FillHistogram( RAT::DS::EV* rEV,
               RAT::DS::PMTProperties* rPMTList,
               TH1D* angOccupy,
               double xPos,
               double yPos,
               double zPos )
{
  TVector3 eventPos( xPos, yPos, zPos );
  eventPos = eventPos.Unit();

  for( int iPMT = 0; iPMT < rEV->GetPMTAllCalCount(); iPMT++ )
    {
      TVector3 pmtPos = rPMTList->GetPos( rEV->GetPMTAllCal( iPMT )->GetID() );
      pmtPos = pmtPos.Unit();
      double angle = acos( pmtPos.Dot( eventPos ) ) * 180.0 / 3.14;
      angOccupy->Fill( angle );
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
