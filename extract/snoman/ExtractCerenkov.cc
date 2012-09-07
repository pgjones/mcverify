////////////////////////////////////////////////////////
/// Extracts the Number of Cerenkov photons histogram
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
FillHistograms( QEvent* qEV,
				TH1D* nCer );

void
ExtractCerenkov( char* lpInFile,
				 char* lpOutFile )
{
  // Load the root file first
  TFile *file = new TFile( lpInFile );
  QTree *tree = (QTree*)file->Get( "T" );
  QEvent *qEV = new QEvent();
  tree->SetEventAddress( qEV );
 
  time_t codeStart = time( NULL );
  TH1D* nCer = new TH1D( "numCer", "numCer", 3000, 0.0, 3000.0 );

  // Loop over the events
  int iLoop;
  int numMCEvents = tree->GetEntries();

  for( iLoop = 0; iLoop < numMCEvents; iLoop++ )
  {
    if( iLoop % 100 == 0 )
      cout << iLoop << " finished at " << time( NULL ) - codeStart << endl;

    tree->GetEntry( iLoop );

    FillHistograms( qEV, nCer );
  }

  TFile outFile( lpOutFile, "RECREATE" );
  outFile.cd();
  nCer->Write();
  outFile.Close();
}

void
FillHistograms( QEvent* qEV,
				TH1D* nCer )
{
  const int lastMCVX = qEV->GetnMCVXs() - 1;
  nCer->Fill( qEV->GetMCVX( lastMCVX )->GetNCerD2O() );
}

