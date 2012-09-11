{
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractCerenkov.cc+" );

  ExtractCerenkov( "TE1.root", "TEC1.root" );
  ExtractCerenkov( "TE2.root", "TEC2.root" );
  ExtractCerenkov( "TE3.root", "TEC3.root" );
  ExtractCerenkov( "TE4.root", "TEC4.root" );
  ExtractCerenkov( "TE5.root", "TEC5.root" );
  ExtractCerenkov( "TE6.root", "TEC6.root" );
  ExtractCerenkov( "TE7.root", "TEC7.root" );
  ExtractCerenkov( "TE8.root", "TEC8.root" );
  ExtractCerenkov( "TE9.root", "TEC9.root" );
  ExtractCerenkov( "TE10.root", "TEC10.root" );
  ExtractCerenkov( "TE11.root", "TEC11.root" );
  ExtractCerenkov( "TE12.root", "TEC12.root" );
  ExtractCerenkov( "TE13.root", "TEC13.root" );

  exit; 
}
