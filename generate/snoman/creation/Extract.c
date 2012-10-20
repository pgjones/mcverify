{
  gROOT->ProcessLine( ".X $MCVERIFY/extract/snoman/Load.c");
  gROOT->ProcessLine( ".L $MCVERIFY/extract/snoman/ExtractCerenkov.cc+" );
  
  ExtractCerenkov( "E1.root", "EC1.root" );
  ExtractCerenkov( "E2.root", "EC2.root" );
  ExtractCerenkov( "E3.root", "EC3.root" );
  ExtractCerenkov( "E4.root", "EC4.root" );
  ExtractCerenkov( "E5.root", "EC5.root" );
  ExtractCerenkov( "E6.root", "EC6.root" );
  
  ExtractCerenkov( "G1.root", "GC1.root" );
  ExtractCerenkov( "G2.root", "GC2.root" );
  ExtractCerenkov( "G3.root", "GC3.root" );
  ExtractCerenkov( "G4.root", "GC4.root" );
  ExtractCerenkov( "G5.root", "GC5.root" );
  ExtractCerenkov( "G6.root", "GC6.root" );

  gSystem->Unload( "$MCVERIFY/extract/snoman/ExtractCerenkov_cc.so" );
  gROOT->ProcessLine( ".L $MCVERIFY/extract/snoman/ExtractNhit.cc+" );
 
  ExtractNhit( "E1.root", "EN1.root" );
  ExtractNhit( "E2.root", "EN2.root" );
  ExtractNhit( "E3.root", "EN3.root" );
  ExtractNhit( "E4.root", "EN4.root" );
  ExtractNhit( "E5.root", "EN5.root" );
  ExtractNhit( "E6.root", "EN6.root" );

  ExtractNhit( "G1.root", "GN1.root" );
  ExtractNhit( "G2.root", "GN2.root" );
  ExtractNhit( "G3.root", "GN3.root" );
  ExtractNhit( "G4.root", "GN4.root" );
  ExtractNhit( "G5.root", "GN5.root" );
  ExtractNhit( "G6.root", "GN6.root" );
  
  exit; 
}
