{
gROOT->ProcessLine( ".L $MCVERIFY/extract/snoman/ExtractNhit.cc+" );

ExtractNhit( "test.root", "testN.root" );

exit; 
}
