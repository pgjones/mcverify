
// Return the graph of predicted yield versus total energy of electron, if plotting then draw graphs
TGraph* PredictedCerenkovYield( bool plotting = false )
{
  double photonKE[] = { 1.000e-01, 1.500e-01, 2.000e-01, 3.000e-01, 4.000e-01, 5.000e-01, 6.000e-01, 8.000e-01, 1.000e+00, 1.022e+00, 1.250e+00, 1.500e+00, 2.000e+00, 2.044e+00, 3.000e+00, 4.000e+00, 5.000e+00, 6.000e+00, 7.000e+00, 8.000e+00, 9.000e+00, 1.000e+01 };
  double photonCrossSection[] = { 1.707e-01, 1.505e-01, 1.370e-01, 1.186e-01, 1.061e-01, 9.687e-02, 8.956e-02, 7.866e-02, 7.072e-02, 6.997e-02, 6.323e-02, 5.754e-02, 4.942e-02, 4.883e-02, 3.969e-02, 3.403e-02, 3.031e-02, 2.770e-02, 2.577e-02, 2.429e-02, 2.313e-02, 2.219e-02 };//cm^2/g from NIST for H2O
  double electronKE[] = { 1.000e-02, 1.250e-02, 1.500e-02, 1.750e-02, 2.000e-02, 2.500e-02, 3.000e-02, 3.500e-02, 4.000e-02, 4.500e-02, 5.000e-02, 5.500e-02, 6.000e-02, 7.000e-02, 8.000e-02, 9.000e-02, 1.000e-01, 1.250e-01, 1.500e-01, 1.750e-01, 2.000e-01, 2.500e-01, 3.000e-01, 3.500e-01, 4.000e-01, 4.500e-01, 5.000e-01, 5.500e-01, 6.000e-01, 7.000e-01, 8.000e-01, 9.000e-01, 1.000e+00, 1.250e+00, 1.500e+00, 1.750e+00, 2.000e+00, 2.500e+00, 3.000e+00, 3.500e+00, 4.000e+00, 4.500e+00, 5.000e+00, 5.500e+00, 6.000e+00, 7.000e+00, 8.000e+00, 9.000e+00, 1.000e+01, 1.250e+01, 1.500e+01, 1.750e+01, 2.000e+01, 2.500e+01, 3.000e+01, 3.500e+01, 4.000e+01, 4.500e+01, 5.000e+01, 5.500e+01, 6.000e+01, 7.000e+01, 8.000e+01, 9.000e+01, 1.000e+02, 1.250e+02, 1.500e+02, 1.750e+02, 2.000e+02, 2.500e+02, 3.000e+02, 3.500e+02, 4.000e+02, 4.500e+02, 5.000e+02, 5.500e+02, 6.000e+02, 7.000e+02, 8.000e+02, 9.000e+02, 1.000e+03 }; 
  double electronInverseCrossSection[] = {2.515e-04, 3.728e-04, 5.147e-04, 6.762e-04, 8.566e-04, 1.272e-03, 1.756e-03, 2.306e-03, 2.919e-03, 3.591e-03, 4.320e-03, 5.103e-03, 5.940e-03, 7.762e-03, 9.773e-03, 1.196e-02, 1.431e-02, 2.083e-02, 2.817e-02, 3.622e-02, 4.488e-02, 6.372e-02, 8.421e-02, 1.060e-01, 1.288e-01, 1.523e-01, 1.766e-01, 2.013e-01, 2.265e-01, 2.778e-01, 3.302e-01, 3.832e-01, 4.367e-01, 5.717e-01, 7.075e-01, 8.432e-01, 9.785e-01, 1.247e+00, 1.514e+00, 1.777e+00, 2.037e+00, 2.295e+00, 2.550e+00, 2.802e+00, 3.052e+00, 3.545e+00, 4.030e+00, 4.506e+00, 4.975e+00, 6.117e+00, 7.219e+00, 8.286e+00, 9.320e+00, 1.130e+01, 1.317e+01, 1.496e+01, 1.665e+01, 1.828e+01, 1.983e+01, 2.132e+01, 2.276e+01, 2.547e+01, 2.799e+01, 3.035e+01, 3.258e+01, 3.761e+01, 4.204e+01, 4.600e+01, 4.957e+01, 5.582e+01, 6.116e+01, 6.583e+01, 6.996e+01, 7.368e+01, 7.706e+01, 8.014e+01, 8.299e+01, 8.810e+01, 9.258e+01, 9.657e+01, 1.002e+02 }; //http://physics.nist.gov/cgi-bin/Star/e_table.pl


  const double z = 1.0; // Used in rat
  //const double z = 0.111898 * 1.0 + 0.888102 * 8.0; // from NIST by weight
  const double density = 1.0; // g/cm^3 lightwater_snoman
  //const double density = 9.9973E-01; // SNOMAN PEGS value (also has different z)
  const double hbarc =  197.327 * 1e6 * 1e-6; // eV nm
  const double hc = hbarc * 2.0 * 3.14; // eV nm
  const double me = 0.511; //MeV

  TGraph* nCer = new TGraph();
  TGraph* dxPlot = new TGraph();
  TGraph* netPlot = new TGraph();
  int graphPoint = 0;
  // Loop over the KE values
  for( int iEnergy = 0; iEnergy < 80; iEnergy++ )
    {
      const double eTotal = electronKE[iEnergy] + me;
      const double beta2 = 1.0 - 0.511 * 0.511 / pow( eTotal, 2 );
      const double dx = electronInverseCrossSection[iEnergy] / density; // Mean free path
      const double N = 370 * z * z * ( hc / 220 - hc / 710 - 1/beta2 * 2.18 ); // See Geant4 physics reference manual
      nCer->SetPoint( graphPoint, eTotal, N );
      dxPlot->SetPoint( graphPoint, eTotal, dx );
      netPlot->SetPoint( graphPoint, eTotal, N * dx );
      graphPoint++;
    }
  if( plotting )
    {
      TCanvas* c1 = new TCanvas();
      c1->Divide( 3, 1 );
      c1->cd(1);
      dxPlot->GetXaxis()->SetTitle( "Electron Total Energy [MeV]" );
      dxPlot->GetYaxis()->SetTitle( "Interaction length [cm]" );
      dxPlot->Draw( "AL" );
      c1->cd(2);
      nCer->GetXaxis()->SetTitle( "Electron Total Energy [MeV]" );
      nCer->GetYaxis()->SetTitle( "Mean number of Cerenkov photons per length [cm^-1]" );
      nCer->Draw( "AL" );
      c1->cd(3);
      netPlot->GetXaxis()->SetTitle( "Electron Total Energy [MeV]" );
      netPlot->GetYaxis()->SetTitle( "Total number of Cerenkov photons" );
      netPlot->Draw( "AL" );
      c1->cd();
    }
  return netPlot; // Use netPlot->Eval( energy ) to query it
}
