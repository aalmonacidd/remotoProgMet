 #include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <boost/numeric/odeint.hpp>

// constants
const double H=0.05;
const double TInf=200;

typedef std::vector<double> state_t; // alias for state type

void print(const state_t & y, double time);
void fderiv(const state_t & y, state_t & dydt, double t);

int main(void)
{
  const double DX = 0.01;
  const double XF = 10.0;
  const int N = 2;

  state_t y(N);//(T,z)


  //use a given initial condition z1i; obtain TF1;
  y[0]=300; y[1]=10;
  boost::numeric::odeint::integrate(fderiv, y, 0.0, XF, DX);
  double TF1 = y[0];
  //use a given initial condition z2i; obtain TF2;
  y[0]=300; y[1]=20;
  boost::numeric::odeint::integrate(fderiv, y, 0.0, XF, DX);
  double TF2 = y[0];
  //Interpolate to get correct
  double z0 =10+((400-TF1)*(10)/(TF2-TF1));

  //solve with correct zi
  y[0]=300;y[1]=z0;
  boost::numeric::odeint::integrate(fderiv, y, 0.0, XF, DX, print);


  return 0;
}



void print(const state_t & y, double time)
{
  std::cout << time << "\t" << y[0] << "\t" << y[1] << std::endl;
}

void fderiv(const state_t & y, state_t & dydt, double t)
{
  dydt[0] = y[1];
  dydt[1] = -H*(TInf-y[0]);
}
