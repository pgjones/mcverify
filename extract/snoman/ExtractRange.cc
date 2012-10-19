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
				TH1D* range );

void
ExtractRange( char* lpInFile,
              char* lpOutFile )
{
  // Load the root file first
  TFile *file = new TFile( lpInFile );
  QTree *tree = (QTree*)file->Get( "T" );
  QEvent *qEV = new QEvent();
  tree->SetEventAddress( qEV );
 
  time_t codeStart = time( NULL );
  TH1D* range = new TH1D( "range", "range", 10000, 0.0, 1000.0 ); // mm in [0,10]m

  // Loop over the events
  int iLoop;
  int numMCEvents = tree->GetEntries();

  for( iLoop = 0; iLoop < numMCEvents; iLoop++ )
  {
    if( iLoop % 100 == 0 )
      cout << iLoop << " finished at " << time( NULL ) - codeStart << endl;

    tree->GetEntry( iLoop );

    FillHistograms( qEV, range );
  }

  TFile outFile( lpOutFile, "RECREATE" );
  outFile.cd();
  range->Write();
  outFile.Close();
}

void
FillHistograms( QEvent* qEV,
				TH1D* range )
{
  const int newPhotonINC = 301000; //301 for new photon
  map< int, vector<TVector3> > trackVPositions; // Track positions by track ID
  int trackID = -1;
  
  cout << qEV->GetnMCVXs() << endl;
  for( int iMCVX = 0; iMCVX < qEV->GetnMCVXs(); iMCVX++ )
    {
      QMCVX* vertex = qEV->GetMCVX( iMCVX );
      if( vertex->GetINC() == newPhotonINC ) // New Track
        trackID++;
	  cout << vertex->GetIDP() << endl;
      if( vertex->GetIDP() == 11 ) // Check track is electron
        trackVPositions[trackID].push_back( TVector3( vertex->GetX(), vertex->GetY(), vertex->GetZ() ) );
    }
  // Now run over tracks, calculate range and fill histogram
  for( map< int, vector<TVector3> >::iterator iTer = trackVPositions.begin(); iTer != trackVPositions.end(); iTer ++ )
    {
      double trackRange = 0.0;
      for( unsigned int iStep = 1; iStep < iTer->second.size(); iStep++ )
        trackRange += ( iTer->second[iStep] - iTer->second[iStep] ).Mag();
      range->Fill( trackRange );
    }
}

