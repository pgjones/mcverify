{
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractPrimaryCerenkov.cc+" );

  ExtractPrimaryCerenkov( "C1.root", "CC1.root" );
  ExtractPrimaryCerenkov( "C2.root", "CC2.root" );
  ExtractPrimaryCerenkov( "C3.root", "CC3.root" );
  ExtractPrimaryCerenkov( "C4.root", "CC4.root" );
  ExtractPrimaryCerenkov( "C5.root", "CC5.root" );
  ExtractPrimaryCerenkov( "C6.root", "CC6.root" );
  ExtractPrimaryCerenkov( "C7.root", "CC7.root" );
  ExtractPrimaryCerenkov( "C8.root", "CC8.root" );
  ExtractPrimaryCerenkov( "C9.root", "CC9.root" );
  ExtractPrimaryCerenkov( "C10.root", "CC10.root" );
  ExtractPrimaryCerenkov( "C11.root", "CC11.root" );
  ExtractPrimaryCerenkov( "C12.root", "CC12.root" );
  ExtractPrimaryCerenkov( "C13.root", "CC13.root" );
  ExtractPrimaryCerenkov( "C14.root", "CC14.root" );

  ExtractPrimaryCerenkov( "C15.root", "CC15.root" );
  ExtractPrimaryCerenkov( "C16.root", "CC16.root" );
  ExtractPrimaryCerenkov( "C17.root", "CC17.root" );
  ExtractPrimaryCerenkov( "C18.root", "CC18.root" );
  ExtractPrimaryCerenkov( "C19.root", "CC19.root" );
  ExtractPrimaryCerenkov( "C20.root", "CC20.root" );

  gSystem->Unload( "$MCVERIFY/extract/rat/ExtractPrimaryCerenkov_cc.so" );

  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractPrimaryRange.cc+" );

  ExtractPrimaryRange( "C1.root", "CR1.root" );
  ExtractPrimaryRange( "C2.root", "CR2.root" );
  ExtractPrimaryRange( "C3.root", "CR3.root" );
  ExtractPrimaryRange( "C4.root", "CR4.root" );
  ExtractPrimaryRange( "C5.root", "CR5.root" );
  ExtractPrimaryRange( "C6.root", "CR6.root" );
  ExtractPrimaryRange( "C7.root", "CR7.root" );
  ExtractPrimaryRange( "C8.root", "CR8.root" );
  ExtractPrimaryRange( "C9.root", "CR9.root" );
  ExtractPrimaryRange( "C10.root", "CR10.root" );
  ExtractPrimaryRange( "C11.root", "CR11.root" );
  ExtractPrimaryRange( "C12.root", "CR12.root" );
  ExtractPrimaryRange( "C13.root", "CR13.root" );
  ExtractPrimaryRange( "C14.root", "CR14.root" );

  ExtractPrimaryRange( "C15.root", "CR15.root" );
  ExtractPrimaryRange( "C16.root", "CR16.root" );
  ExtractPrimaryRange( "C17.root", "CR17.root" );
  ExtractPrimaryRange( "C18.root", "CR18.root" );
  ExtractPrimaryRange( "C19.root", "CR19.root" );
  ExtractPrimaryRange( "C20.root", "CR20.root" );

  gSystem->Unload( "$MCVERIFY/extract/rat/ExtractPrimaryRange_cc.so" );

  exit; 
}
