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
			   TH1D* aveOccupy );

void
ExtractAveOccupancy(
					char* lpInFile,
					char* lpOutFile )
{
  // Load the root file first
  TFile *file = new TFile( lpInFile );
  QTree *tree = (QTree*)file->Get( "T" );
  QEvent *qEV = new QEvent();
  tree->SetEventAddress( qEV );

  time_t codeStart = time( NULL );

  // Loop over the events
  int iLoop;
  int numMCEvents = tree->GetEntries();

  TH1D* aveOccupy = new TH1D( "aveOccupy", "aveOccupy", 10000, 0.0, 10000.0 );

  for( iLoop = 0; iLoop < numMCEvents; iLoop++ )
  {
    if( iLoop % 100 == 0 )
      cout << iLoop << " finished at " << time( NULL ) - codeStart << endl;

    tree->GetEntry( iLoop );
	
    FillHistograms( qEV, aveOccupy );
  }
  aveOccupy->Sumw2();
  aveOccupy->Scale( 1.0 / (double) numMCEvents );
  TFile outFile( lpOutFile, "RECREATE" );
  outFile.cd();
  aveOccupy->Write();
  outFile.Close();
}

void
FillHistograms(
			   QEvent* qEV,
			   TH1D* aveOccupy )
{
  int numPMTHits = qEV->GetnPMTs();
  for( int iLoop = 0; iLoop < numPMTHits; iLoop++ )
	{
	  QPMT* qPMT = qEV->GetPMT( iLoop );
	  aveOccupy->Fill( qPMT->Getn() );
	}
}

