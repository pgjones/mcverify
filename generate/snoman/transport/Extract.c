{
gROOT->ProcessLine( ".X $MCVERIFY/extract/snoman/Load.c");
gROOT->ProcessLine( ".L $MCVERIFY/extract/snoman/ExtractAngOccupancy.cc+" );

ExtractAngOccupancy( "X0.root", "XA0.root", 0.0, 0.0, 0.0 );
ExtractAngOccupancy( "X1.root", "XA1.root", 100.0, 0.0, 0.0 );
ExtractAngOccupancy( "X2.root", "XA2.root", 200.0, 0.0, 0.0 );
ExtractAngOccupancy( "X3.root", "XA3.root", 300.0, 0.0, 0.0 );
ExtractAngOccupancy( "X4.root", "XA4.root", 400.0, 0.0, 0.0 );
ExtractAngOccupancy( "X5.root", "XA5.root", 500.0, 0.0, 0.0 );

ExtractAngOccupancy( "Y0.root", "YA0.root", 0.0, 0.0, 0.0 );
ExtractAngOccupancy( "Y1.root", "YA1.root", 0.0, 100.0, 0.0 );
ExtractAngOccupancy( "Y2.root", "YA2.root", 0.0, 200.0, 0.0 );
ExtractAngOccupancy( "Y3.root", "YA3.root", 0.0, 300.0, 0.0 );
ExtractAngOccupancy( "Y4.root", "YA4.root", 0.0, 400.0, 0.0 );
ExtractAngOccupancy( "Y5.root", "YA5.root", 0.0, 500.0, 0.0 );

ExtractAngOccupancy( "Z-5.root", "ZA-5.root", 0.0, 0.0, -500.0 );
ExtractAngOccupancy( "Z-4.root", "ZA-4.root", 0.0, 0.0, -400.0 );
ExtractAngOccupancy( "Z-3.root", "ZA-3.root", 0.0, 0.0, -300.0 );
ExtractAngOccupancy( "Z-2.root", "ZA-2.root", 0.0, 0.0, -200.0 );
ExtractAngOccupancy( "Z-1.root", "ZA-1.root", 0.0, 0.0, -100.0 );
ExtractAngOccupancy( "Z0.root", "ZA0.root", 0.0, 0.0, 0.0 );
ExtractAngOccupancy( "Z1.root", "ZA1.root", 0.0, 0.0, 100.0 );
ExtractAngOccupancy( "Z2.root", "ZA2.root", 0.0, 0.0, 200.0 );
ExtractAngOccupancy( "Z3.root", "ZA3.root", 0.0, 0.0, 300.0 );
ExtractAngOccupancy( "Z4.root", "ZA4.root", 0.0, 0.0, 400.0 );
ExtractAngOccupancy( "Z5.root", "ZA5.root", 0.0, 0.0, 500.0 );

gSystem->Unload( "$MCVERIFY/extract/snoman/ExtractAngOccupancy_cc.so" );

gROOT->ProcessLine( ".L $MCVERIFY/extract/snoman/ExtractNhit.cc+" );

ExtractNhit( "X0.root", "XN0.root" );
ExtractNhit( "X1.root", "XN1.root" );
ExtractNhit( "X2.root", "XN2.root" );
ExtractNhit( "X3.root", "XN3.root" );
ExtractNhit( "X4.root", "XN4.root" );
ExtractNhit( "X5.root", "XN5.root" );
ExtractNhit( "Y0.root", "YN0.root" );
ExtractNhit( "Y1.root", "YN1.root" );
ExtractNhit( "Y2.root", "YN2.root" );
ExtractNhit( "Y3.root", "YN3.root" );
ExtractNhit( "Y4.root", "YN4.root" );
ExtractNhit( "Y5.root", "YN5.root" );
ExtractNhit( "Z-5.root", "ZN-5.root" );
ExtractNhit( "Z-4.root", "ZN-4.root" );
ExtractNhit( "Z-3.root", "ZN-3.root" );
ExtractNhit( "Z-2.root", "ZN-2.root" );
ExtractNhit( "Z-1.root", "ZN-1.root" );
ExtractNhit( "Z0.root", "ZN0.root" );
ExtractNhit( "Z1.root", "ZN1.root" );
ExtractNhit( "Z2.root", "ZN2.root" );
ExtractNhit( "Z3.root", "ZN3.root" );
ExtractNhit( "Z4.root", "ZN4.root" );
ExtractNhit( "Z5.root", "ZN5.root" );

exit; 
}
