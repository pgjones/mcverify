{
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractNhit.cc+" );

  ExtractNhit( "L300.root", "LN300.root" );
  ExtractNhit( "L350.root", "LN350.root" );
  ExtractNhit( "L400.root", "LN400.root" );
  ExtractNhit( "L450.root", "LN450.root" );
  ExtractNhit( "L500.root", "LN500.root" );
  ExtractNhit( "L550.root", "LN550.root" );
  ExtractNhit( "H300.root", "HN300.root" );
  ExtractNhit( "H350.root", "HN350.root" );
  ExtractNhit( "H400.root", "HN400.root" );
  ExtractNhit( "H450.root", "HN450.root" );
  ExtractNhit( "H500.root", "HN500.root" );
  ExtractNhit( "H550.root", "HN550.root" );

  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractAveOccupancy.cc+" );

  ExtractAveOccupancy( "L300.root", "LX300.root" );
  ExtractAveOccupancy( "L350.root", "LX350.root" );
  ExtractAveOccupancy( "L400.root", "LX400.root" );
  ExtractAveOccupancy( "L450.root", "LX450.root" );
  ExtractAveOccupancy( "L500.root", "LX500.root" );
  ExtractAveOccupancy( "L550.root", "LX550.root" );
  ExtractAveOccupancy( "H300.root", "HX300.root" );
  ExtractAveOccupancy( "H350.root", "HX350.root" );
  ExtractAveOccupancy( "H400.root", "HX400.root" );
  ExtractAveOccupancy( "H450.root", "HX450.root" );
  ExtractAveOccupancy( "H500.root", "HX500.root" );
  ExtractAveOccupancy( "H550.root", "HX550.root" );

  exit;
}
