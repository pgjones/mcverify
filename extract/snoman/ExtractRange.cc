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
  const int newINC = 100; //100 for new electron
  map< int, vector<TVector3> > trackVPositions; // Track positions by track ID
  int trackID = 0;
  
  for( int iMCVX = 0; iMCVX < qEV->GetnMCVXs(); iMCVX++ )
    {
      QMCVX* qMCVX = qEV->GetMCVX( iMCVX );
      if( static_cast<int>( qMCVX->GetINC() / 1000.0 ) == 381 ||
          static_cast<int>( qMCVX->GetINC() / 1000.0 ) == 382 ||
          static_cast<int>( qMCVX->GetINC() / 1000.0 ) == 383 ||
          static_cast<int>( qMCVX->GetINC() / 1000.0 ) == 384 ) // Track has ended
        trackID++;
      if( qMCVX->GetIDP() == 20 ) // Check track is electron
        trackVPositions[trackID].push_back( TVector3( qMCVX->GetX(), qMCVX->GetY(), qMCVX->GetZ() ) );
    }
  // Now run over tracks, calculate range and fill histogram
  double trackRange = 0.0;
  for( unsigned int iStep = 1; iStep < trackVPositions[0].size(); iStep++ )
	trackRange += ( trackVPositions[0][iStep - 1] - trackVPositions[0][iStep] ).Mag();
  range->Fill( trackRange );
}

