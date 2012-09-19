////////////////////////////////////////////////////////
/// Calculates the theorectical Cerenkov photon yield 
/// using the Nist estar http://www.nist.gov/pml/data/star/index.cfm
/// values for electrons in water.
/// This only works for lightwater!
/// P G Jones <p.g.jones@qmul.ac.uk>
///
/// 17/09/2012 : New File
////////////////////////////////////////////////////////
#include <TF1.h>
#include <TGraph.h>

double // Returned cerenkov photon yield
CalculateCerenkovYield( const double eStart, // Total energy of the particle at the start [MeV]
                        double& range ) // Returned range of the electron [cm]
{
  const double z = 1.0; // Value as used in RAT
  const double density = 1.0; // g/cm^2 Used dE/dx for water
  const double hbarc =  197.327 * 1e6 * 1e-6; // eV nm
  const double hc = hbarc * 2.0 * 3.14; // eV nm
  const double me = 0.511; //MeV
  //const double nbar = 1.342; // Average refractive index for light water 
  const double nMin = 200.0; //nm for lightwater
  const double nMax = 800.0; //nm for lightwater

  TF1* beta2Func = new TF1( "beta2", "1 - [0]*[0] / ( x * x )", 0.0, 10.0 ); // Beta square value
  beta2Func->SetParameter( 0, me );
  double electronKE[] = { 1.000E-02, 1.250E-02, 1.500E-02, 1.750E-02, 2.000E-02, 2.500E-02, 3.000E-02, 3.500E-02, 4.000E-02, 4.500E-02, 5.000E-02, 5.500E-02, 6.000E-02, 7.000E-02, 8.000E-02, 9.000E-02, 1.000E-01, 1.250E-01, 1.500E-01, 1.750E-01, 2.000E-01, 2.500E-01, 3.000E-01, 3.500E-01, 4.000E-01, 4.500E-01, 5.000E-01, 5.500E-01, 6.000E-01, 7.000E-01, 8.000E-01, 9.000E-01, 1.000E+00, 1.250E+00, 1.500E+00, 1.750E+00, 2.000E+00, 2.500E+00, 3.000E+00, 3.500E+00, 4.000E+00, 4.500E+00, 5.000E+00, 5.500E+00, 6.000E+00, 7.000E+00, 8.000E+00, 9.000E+00, 1.000E+01, 1.250E+01, 1.500E+01, 1.750E+01, 2.000E+01, 2.500E+01, 3.000E+01, 3.500E+01, 4.000E+01, 4.500E+01, 5.000E+01, 5.500E+01, 6.000E+01, 7.000E+01, 8.000E+01, 9.000E+01, 1.000E+02, 1.250E+02, 1.500E+02, 1.750E+02, 2.000E+02, 2.500E+02, 3.000E+02, 3.500E+02, 4.000E+02, 4.500E+02, 5.000E+02, 5.500E+02, 6.000E+02, 7.000E+02, 8.000E+02, 9.000E+02, 1.000E+03 }; // MeV
  double electrondEdx[] = { 2.256E+01, 1.898E+01, 1.647E+01, 1.461E+01, 1.318E+01, 1.110E+01, 9.657E+00, 8.596E+00, 7.781E+00, 7.134E+00, 6.607E+00, 6.170E+00, 5.801E+00, 5.211E+00, 4.761E+00, 4.407E+00, 4.119E+00, 3.596E+00, 3.242E+00, 2.988E+00, 2.798E+00, 2.533E+00, 2.360E+00, 2.241E+00, 2.154E+00, 2.090E+00, 2.041E+00, 2.003E+00, 1.972E+00, 1.926E+00, 1.896E+00, 1.876E+00, 1.862E+00, 1.845E+00, 1.841E+00, 1.844E+00, 1.850E+00, 1.868E+00, 1.889E+00, 1.910E+00, 1.931E+00, 1.951E+00, 1.971E+00, 1.991E+00, 2.010E+00, 2.047E+00, 2.082E+00, 2.116E+00, 2.149E+00, 2.230E+00, 2.306E+00, 2.381E+00, 2.454E+00, 2.598E+00, 2.738E+00, 2.876E+00, 3.013E+00, 3.150E+00, 3.286E+00, 3.421E+00, 3.556E+00, 3.827E+00, 4.096E+00, 4.366E+00, 4.636E+00, 5.311E+00, 5.987E+00, 6.663E+00, 7.341E+00, 8.698E+00, 1.006E+01, 1.142E+01, 1.278E+01, 1.414E+01, 1.551E+01, 1.688E+01, 1.824E+01, 2.098E+01, 2.371E+01, 2.645E+01, 2.919E+01 }; // MeV cm^2 / g
  TGraph* dEdx = new TGraph( 81, electronKE, electrondEdx );

  const double Estep = 0.001; // Intergral step size
  double N = 0.0;
  range = 0.0;
  // Integrate from rest, me, to the start energy if the number created is less or equal to zero then ignore
  for( double Etotal = me; Etotal <= eStart; Etotal += Estep )
    {
      const double dx = 1.0 / ( dEdx->Eval( Etotal - me ) * density ) * Estep; // In cm
      range += dx;
      // 370 is the constant for photons eV^-1 cm^-1
      // 2.58 is the integral over 1/n^2 for lightwater and the limits of 220 and 710nm.
      const double dN = 370 * z * z * ( hc / nMin - hc / nMax - 1.0 / beta2Func->Eval( Etotal ) * 2.58 ) * dx;
      if( dN > 0.0 )
        N += dN;
    }
  return N;
}
