{
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractCerenkov.cc+" );

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

  exit; 
}
