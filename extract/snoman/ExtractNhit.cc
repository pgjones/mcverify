////////////////////////////////////////////////////////
/// Extracts the Nhit per event histogram
///
/// 12/07/12 - New File
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
FillHistograms( QEvent* qEV,
				TH1D* nHits );

void
ExtractNhit( char* lpInFile,
			 char* lpOutFile )
{
  // Load the root file first
  TFile *file = new TFile( lpInFile );
  QTree *tree = (QTree*)file->Get( "T" );
  QEvent *qEV = new QEvent();
  tree->SetEventAddress( qEV );
 
  time_t codeStart = time( NULL );
  TH1D* nHits = new TH1D( "nHits", "nHits", 10000, 0.0, 10000.0 );

  // Loop over the events
  int iLoop;
  int numMCEvents = tree->GetEntries();

  for( iLoop = 0; iLoop < numMCEvents; iLoop++ )
  {
    if( iLoop % 100 == 0 )
      cout << iLoop << " finished at " << time( NULL ) - codeStart << endl;

    tree->GetEntry( iLoop );

    FillHistograms( qEV, nHits );
  }

  TFile outFile( lpOutFile, "RECREATE" );
  outFile.cd();
  nHits->Write();
  outFile.Close();
}

void
FillHistograms( QEvent* qEV,
				TH1D* nHits )
{
  nHits->Fill( qEV->GetNhits() );
}

