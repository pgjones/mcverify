{
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractNhit.cc+" );

  ExtractNhit( "empty.root", "emptyN.root" );
  ExtractNhit( "av.root", "avN.root" );
  ExtractNhit( "av_tile.root", "av_tileN.root" );
  ExtractNhit( "av_neck.root", "av_neckN.root" );
  ExtractNhit( "av_belly.root", "av_bellyN.root" );
  ExtractNhit( "ropes.root", "ropesN.root" );
  ExtractNhit( "full.root", "fullN.root" );
  
  exit;
}
