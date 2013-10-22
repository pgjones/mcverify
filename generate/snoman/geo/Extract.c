{
gROOT->ProcessLine( ".X $MCVERIFY/extract/snoman/Load.c");
gROOT->ProcessLine( ".L $MCVERIFY/extract/snoman/ExtractNhit.cc+" );

ExtractNhit( "empty.root", "emptyN.root" );
ExtractNhit( "ropes.root", "ropesN.root" );
ExtractNhit( "av.root", "avN.root" );
ExtractNhit( "av_tile.root", "av_tileN.root" );
ExtractNhit( "av_belly.root", "av_bellyN.root" );
ExtractNhit( "full.root", "fullN.root" );

exit; 
}
