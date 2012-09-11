{
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractAngOccupancy.cc+" );

  ExtractAngOccupancy( "X0.root", "XA0.root", 0.0, 0.0, 0.0 );
  ExtractAngOccupancy( "X1.root", "XA1.root", 1000.0, 0.0, 0.0 );
  ExtractAngOccupancy( "X2.root", "XA2.root", 2000.0, 0.0, 0.0 );
  ExtractAngOccupancy( "X3.root", "XA3.root", 3000.0, 0.0, 0.0 );
  ExtractAngOccupancy( "X4.root", "XA4.root", 4000.0, 0.0, 0.0 );
  ExtractAngOccupancy( "X5.root", "XA5.root", 5000.0, 0.0, 0.0 );
  
  ExtractAngOccupancy( "Y0.root", "YA0.root", 0.0, 0.0, 0.0 );
  ExtractAngOccupancy( "Y1.root", "YA1.root", 0.0, 1000.0, 0.0 );
  ExtractAngOccupancy( "Y2.root", "YA2.root", 0.0, 2000.0, 0.0 );
  ExtractAngOccupancy( "Y3.root", "YA3.root", 0.0, 3000.0, 0.0 );
  ExtractAngOccupancy( "Y4.root", "YA4.root", 0.0, 4000.0, 0.0 );
  ExtractAngOccupancy( "Y5.root", "YA5.root", 0.0, 5000.0, 0.0 );
  
  ExtractAngOccupancy( "Z-5.root", "ZA-5.root", 0.0, 0.0, -5000.0 );
  ExtractAngOccupancy( "Z-4.root", "ZA-4.root", 0.0, 0.0, -4000.0 );
  ExtractAngOccupancy( "Z-3.root", "ZA-3.root", 0.0, 0.0, -3000.0 );
  ExtractAngOccupancy( "Z-2.root", "ZA-2.root", 0.0, 0.0, -2000.0 );
  ExtractAngOccupancy( "Z-1.root", "ZA-1.root", 0.0, 0.0, -1000.0 );
  ExtractAngOccupancy( "Z0.root", "ZA0.root", 0.0, 0.0, 0.0 );
  ExtractAngOccupancy( "Z1.root", "ZA1.root", 0.0, 0.0, 1000.0 );
  ExtractAngOccupancy( "Z2.root", "ZA2.root", 0.0, 0.0, 2000.0 );
  ExtractAngOccupancy( "Z3.root", "ZA3.root", 0.0, 0.0, 3000.0 );
  ExtractAngOccupancy( "Z4.root", "ZA4.root", 0.0, 0.0, 4000.0 );
  ExtractAngOccupancy( "Z5.root", "ZA5.root", 0.0, 0.0, 5000.0 );
  
  exit;
}
