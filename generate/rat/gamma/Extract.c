{ 
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractNhit.cc+" );

  ExtractNhit( "test.root", "testN.root" );
  
  exit;
}
