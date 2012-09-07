////////////////////////////////////////////////////////
/// Extracts the Nhit histograms and Time histograms, into
/// a SNOMAN independent version.
///
/// 06/12/10 - New File
////////////////////////////////////////////////////////

#include <TH1D.h>
#include <TFile.h>
#include <TTree.h>
using namespace ROOT;

#include <iostream>
using namespace std;

#include <QEvent.h>
#include <QMCEvent.h>
#include <QTree.h>
#include <QMCVX.h>
#include <QPMT.h>
#include <QFit.h>

// Must do this first
//gSystem->AddIncludePath("-I$QSNO_ROOT/include");

void
FillHistograms(
	       QEvent* qEV,
	       QMCEvent* qMCEvent,
	       TH1D* timeMC,
	       TH1D* nHitsMC,
	       TH1D* timeEV,
	       TH1D* nHitsEV,
	       bool residual );

void
ExtractTimeNhit(
		char* lpInFile,
		char* lpOutFile,
		bool residual = false )
{
  // Load the root file first
  TFile *file = new TFile( lpInFile );
  QTree *tree = (QTree*)file->Get( "T" );
  QEvent *qEV = new QEvent();
  tree->SetEventAddress( qEV );
  TTree* mcTree = (TTree*)file->Get( "MCEvents" );
  QMCEvent* qMCEvent = new QMCEvent();
  mcTree->SetBranchAddress( "MCEvents", &qMCEvent );
 
  int mcOffset = -1;
  mcTree->GetEntry(0);

  time_t codeStart = time( NULL );

  // Loop over the events
  int iLoop;
  int numMCEvents = tree->GetEntries();

  TH1D* timeMC = new TH1D( "timeMC", "timeMC", 500, 0.0, 500.0 );
  TH1D* nHitsMC = new TH1D( "nHitsMC", "nHitsMC", 4000, 0.0, 4000.0 );
  TH1D* timeEV = new TH1D( "timeEV", "timeEV", 500, 0.0, 500.0 );
  TH1D* nHitsEV = new TH1D( "nHitsEV", "nHitsEV", 4000, 0.0, 4000.0 );

  for( iLoop = 0; iLoop < numMCEvents; iLoop++ )
  {
    if( iLoop % 100 == 0 )
      cout << iLoop << " finished at " << time( NULL ) - codeStart << endl;

    tree->GetEntry( iLoop );
    mcTree->GetEntry( qEV->GetMCEventNumber() + mcOffset );
    while( qMCEvent->GetEventNumber() != qEV->GetMCEventNumber() )
      {
	if( qMCEvent->GetEventNumber() > qEV->GetMCEventNumber() )
	  mcOffset -= 1;
	else
	  mcOffset += 1;
	mcTree->GetEntry( qEV->GetMCEventNumber() + mcOffset );
      }
    if( qMCEvent->GetEventNumber() != qEV->GetMCEventNumber() )
      cout << qEV->GetMCEventNumber() << " " << qMCEvent->GetEventNumber() << " " << mcOffset << endl;

    FillHistograms( qEV, qMCEvent, timeMC, nHitsMC, timeEV, nHitsEV, residual );
  }

  TFile outFile( lpOutFile, "RECREATE" );
  outFile.cd();
  timeMC->Write();
  nHitsMC->Write();
  timeEV->Write();
  nHitsEV->Write();
  outFile.Close();
}

void
FillHistograms(
	       QEvent* qEV,
	       QMCEvent* qMCEvent,
	       TH1D* timeMC,
	       TH1D* nHitsMC,
	       TH1D* timeEV,
	       TH1D* nHitsEV,
	       bool residual )
{
  //MC
  {
    int numPMTHits = qEV->GetnMCPMs();
    nHitsMC->Fill( numPMTHits );
    
    int iLoop;
    
    for( iLoop = 0; iLoop < numPMTHits; iLoop++ )
      {
	QPMT* qPMT = qEV->GetMCPM( iLoop );
	timeMC->Fill( qPMT->Gett() );
      }
  }
  //EV
  {
    int numPMTHits = qEV->GetnPMTs();
    nHitsEV->Fill( qEV->GetNhits() );

    QFit* qFit = qEV->GetFitByIndex(9);
    double fitTime = 0.0;
    if( qFit != NULL )
      fitTime = qFit->GetTime();

    for( int iLoop = 0; iLoop < numPMTHits; iLoop++ )
      {
        QPMT* qPMT = qEV->GetPMT( iLoop );
	if( residual )
	  timeEV->Fill( qPMT->TimeResidual( 0.0, 0.0, 0.0, fitTime ) + 220.0 );
	else
	  timeEV->Fill( qPMT->Gett() - fitTime + 220.0 );
      }
  }
}

