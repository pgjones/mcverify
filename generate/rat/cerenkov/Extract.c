{
  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractPrimaryCerenkov.cc+" );

  ExtractPrimaryCerenkov( "C1.root", "CP1.root" );
  ExtractPrimaryCerenkov( "C2.root", "CP2.root" );
  ExtractPrimaryCerenkov( "C3.root", "CP3.root" );
  ExtractPrimaryCerenkov( "C4.root", "CP4.root" );
  ExtractPrimaryCerenkov( "C5.root", "CP5.root" );
  ExtractPrimaryCerenkov( "C6.root", "CP6.root" );
  ExtractPrimaryCerenkov( "C7.root", "CP7.root" );
  ExtractPrimaryCerenkov( "C8.root", "CP8.root" );
  ExtractPrimaryCerenkov( "C9.root", "CP9.root" );
  ExtractPrimaryCerenkov( "C10.root", "CP10.root" );
  ExtractPrimaryCerenkov( "C11.root", "CP11.root" );
  ExtractPrimaryCerenkov( "C12.root", "CP12.root" );
  ExtractPrimaryCerenkov( "C13.root", "CP13.root" );
  ExtractPrimaryCerenkov( "C14.root", "CP14.root" );

  ExtractPrimaryCerenkov( "C15.root", "CP15.root" );
  ExtractPrimaryCerenkov( "C16.root", "CP16.root" );
  ExtractPrimaryCerenkov( "C17.root", "CP17.root" );
  ExtractPrimaryCerenkov( "C18.root", "CP18.root" );
  ExtractPrimaryCerenkov( "C19.root", "CP19.root" );
  ExtractPrimaryCerenkov( "C20.root", "CP20.root" );

  gSystem->Unload( "$MCVERIFY/extract/rat/ExtractPrimaryCerenkov_cc.so" );

  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractCerenkov.cc+" );

  ExtractCerenkov( "C1.root", "CC1.root" );
  ExtractCerenkov( "C2.root", "CC2.root" );
  ExtractCerenkov( "C3.root", "CC3.root" );
  ExtractCerenkov( "C4.root", "CC4.root" );
  ExtractCerenkov( "C5.root", "CC5.root" );
  ExtractCerenkov( "C6.root", "CC6.root" );
  ExtractCerenkov( "C7.root", "CC7.root" );
  ExtractCerenkov( "C8.root", "CC8.root" );
  ExtractCerenkov( "C9.root", "CC9.root" );
  ExtractCerenkov( "C10.root", "CC10.root" );
  ExtractCerenkov( "C11.root", "CC11.root" );
  ExtractCerenkov( "C12.root", "CC12.root" );
  ExtractCerenkov( "C13.root", "CC13.root" );
  ExtractCerenkov( "C14.root", "CC14.root" );

  ExtractCerenkov( "C15.root", "CC15.root" );
  ExtractCerenkov( "C16.root", "CC16.root" );
  ExtractCerenkov( "C17.root", "CC17.root" );
  ExtractCerenkov( "C18.root", "CC18.root" );
  ExtractCerenkov( "C19.root", "CC19.root" );
  ExtractCerenkov( "C20.root", "CC20.root" );

  gSystem->Unload( "$MCVERIFY/extract/rat/ExtractCerenkov_cc.so" );

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

  gROOT->ProcessLine( ".L $MCVERIFY/extract/rat/ExtractNhit.cc+" );

  ExtractNhit( "C1.root", "CN1.root" );
  ExtractNhit( "C2.root", "CN2.root" );
  ExtractNhit( "C3.root", "CN3.root" );
  ExtractNhit( "C4.root", "CN4.root" );
  ExtractNhit( "C5.root", "CN5.root" );
  ExtractNhit( "C6.root", "CN6.root" );
  ExtractNhit( "C7.root", "CN7.root" );
  ExtractNhit( "C8.root", "CN8.root" );
  ExtractNhit( "C9.root", "CN9.root" );
  ExtractNhit( "C10.root", "CN10.root" );
  ExtractNhit( "C11.root", "CN11.root" );
  ExtractNhit( "C12.root", "CN12.root" );
  ExtractNhit( "C13.root", "CN13.root" );
  ExtractNhit( "C14.root", "CN14.root" );
  ExtractNhit( "C15.root", "CN15.root" );
  ExtractNhit( "C16.root", "CN16.root" );
  ExtractNhit( "C17.root", "CN17.root" );
  ExtractNhit( "C18.root", "CN18.root" );
  ExtractNhit( "C19.root", "CN19.root" );
  ExtractNhit( "C20.root", "CN20.root" );

  exit; 
}
