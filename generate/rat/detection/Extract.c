{
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractAveOccupancy.cc+" );

  ExtractAveOccupancy( "PB337.root", "PBX337.root" );
  ExtractAveOccupancy( "PB365.root", "PBX365.root" );
  ExtractAveOccupancy( "PB386.root", "PBX386.root" );
  ExtractAveOccupancy( "PB420.root", "PBX420.root" );
  ExtractAveOccupancy( "PB500.root", "PBX500.root" );
  ExtractAveOccupancy( "PB620.root", "PBX620.root" );

  exit;
}
