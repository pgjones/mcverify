{
gROOT->ProcessLine( ".X $MCVERIFY/extract/snoman/Load.c");
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
