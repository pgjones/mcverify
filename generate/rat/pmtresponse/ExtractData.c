{
  gROOT->ProcessLine( ".X $RATTOOLS/PMTResponseExtraction/ExtractionCode/Delete.c" );
  gROOT->ProcessLine( ".X $RATTOOLS/PMTResponseExtraction/ExtractionCode/LoadRAT.c" );

  ExtractData( "PR300.root", true );
  ExtractData( "PR350.root", true );
  ExtractData( "PR400.root", true );
  ExtractData( "PR450.root", true );
  ExtractData( "PR500.root", true );
  ExtractData( "PR550.root", true );
  ExtractData( "PRGamma.root", true );  

  vector<string> files1;
  files1.push_back( "PR300.dat" );
  files1.push_back( "PR350.dat" );
  files1.push_back( "PR400.dat" );
  files1.push_back( "PR450.dat" );
  files1.push_back( "PR500.dat" );
  files1.push_back( "PR550.dat" );

  MergeFiles( files1, "PRAll.dat" );
  exit;
}
