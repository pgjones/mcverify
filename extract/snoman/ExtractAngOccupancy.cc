////////////////////////////////////////////////////////
/// Extracts the Nhit histograms and Time histograms, into
/// a SNOMAN independent version.
///
/// 06/12/10 - New File
////////////////////////////////////////////////////////

#include <TH1D.h>
#include <TFile.h>
#include <TTree.h>
#include <TVector3.h>
using namespace ROOT;

#include <iostream>
#include <math.h>
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
				TH1D* angOccupy,
				float xPos,
				float yPos,
				float zPos );

void
ExtractAngOccupancy( char* lpInFile,
					 char* lpOutFile,
					 float xPos,
					 float yPos,
					 float zPos )
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

  TH1D* angOccupy = new TH1D( "angOccupy", "angOccupy", 360, 0.0, 360.0 );

  for( iLoop = 0; iLoop < numMCEvents; iLoop++ )
  {
    if( iLoop % 100 == 0 )
      cout << iLoop << " finished at " << time( NULL ) - codeStart << endl;

    tree->GetEntry( iLoop );
	
    FillHistograms( qEV, angOccupy, xPos, yPos, zPos );
  }
  angOccupy->Sumw2();
  angOccupy->Scale( 1.0 / (double) numMCEvents );
  TFile outFile( lpOutFile, "RECREATE" );
  outFile.cd();
  angOccupy->Write();
  outFile.Close();
}

void
FillHistograms( QEvent* qEV,
				TH1D* angOccupy,
				float xPos,
				float yPos, 
				float zPos )
{
  int numPMTHits = qEV->GetnPMTs();
  TVector3 eventPos( xPos, yPos, zPos );
  eventPos = eventPos.Unit();

  for( int iLoop = 0; iLoop < numPMTHits; iLoop++ )
	{
	  QPMT* qPMT = qEV->GetPMT( iLoop );
	  TVector3 pmtPos( qPMT->GetX(), qPMT->GetY(), qPMT->GetZ() );
	  pmtPos = pmtPos.Unit();
	  double angle = acos( pmtPos.Dot( eventPos ) ) * 180.0 / 3.14;
	  angOccupy->Fill( angle );
	}
}

