{
gROOT->ProcessLine( ".X $RATTOOLS/PMTResponseExtraction/ExtractionCode/Delete.c" );
gROOT->ProcessLine( ".X $RATTOOLS/PMTResponseExtraction/ExtractionCode/Load.c" );

int numFolders = 0;
stringstream folder;
folder << "Run" << 1;
while( gSystem->AccessPathName( folder.str().c_str() ) == 0 )
{
  numFolders++;
  folder.str("");
  folder << "Run" << numFolders;
}
 vector<string> filesGD300, filesGD350, filesGD400, filesGD450, filesGD500, filesGD550, filesGamma, filesGDAll;

int iLoop;
for( iLoop = 1; iLoop < numFolders; iLoop++ )
{
  // Merge them here
  folder.str("");
  folder << "Run" << iLoop;

  stringstream file;
  file.str(""); file << folder.str() << "/PR300.dat";
  filesGD300.push_back( string( file.str().c_str() ) );
  file.str(""); file << folder.str() << "/PR350.dat";
  filesGD350.push_back( string( file.str().c_str() ) );
  file.str(""); file << folder.str() << "/PR400.dat";
  filesGD400.push_back( string( file.str().c_str() ) );
  file.str(""); file << folder.str() << "/PR450.dat";
  filesGD450.push_back( string( file.str().c_str() ) );
  file.str(""); file << folder.str() << "/PR500.dat";
  filesGD500.push_back( string( file.str().c_str() ) );
  file.str(""); file << folder.str() << "/PR550.dat";
  filesGD550.push_back( string( file.str().c_str() ) );
  file.str(""); file << folder.str() << "/PRGamma.dat";
  filesGamma.push_back( string( file.str().c_str() ) );
  file.str(""); file << folder.str() << "/PRAll.dat";
  filesGDAll.push_back( string( file.str().c_str() ) );
}

MergeFiles( filesGD300, string( "PR300.dat") );
MergeFiles( filesGD350, string( "PR350.dat") );
MergeFiles( filesGD400, string( "PR400.dat") );
MergeFiles( filesGD450, string( "PR450.dat") );
MergeFiles( filesGD500, string( "PR500.dat") );
MergeFiles( filesGD550, string( "PR550.dat") );
MergeFiles( filesGamma, string( "PRGamma.dat") );
MergeFiles( filesGDAll, string( "PRAll.dat") );
exit;
}
