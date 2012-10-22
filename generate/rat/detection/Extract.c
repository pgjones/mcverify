{
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractAveOccupancy.cc+" );

  ExtractAveOccupancy( "PB337.root", "PBX337.root" );
  ExtractAveOccupancy( "PB365.root", "PBX365.root" );
  ExtractAveOccupancy( "PB386.root", "PBX386.root" );
  ExtractAveOccupancy( "PB420.root", "PBX420.root" );
  ExtractAveOccupancy( "PB500.root", "PBX500.root" );
  ExtractAveOccupancy( "PB620.root", "PBX620.root" );

  gSystem->Unload( "$MCVERIFY/extract/rat/ExtractAveOccupancy_cc.so" );
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractNhit.cc+" );

  ExtractNhit( "PB337.root", "PBN337.root" );
  ExtractNhit( "PB365.root", "PBN365.root" );
  ExtractNhit( "PB386.root", "PBN386.root" );
  ExtractNhit( "PB420.root", "PBN420.root" );
  ExtractNhit( "PB500.root", "PBN500.root" );
  ExtractNhit( "PB620.root", "PBN620.root" );        

  exit;
}
