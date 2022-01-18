#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <boost/numeric/odeint.hpp>

// constants
const double pi = 4.0* std::atan(1.0);
const double X0 = 0;
const double XF = pi*0.5;
const double DX = 0.01;

typedef std::vector<double> state_t; // alias for state type

void print(const state_t & y, double time);
template <class fptr>
double newton(double x0, fptr fun, double eps, int & niter);

int main(int argc, char **argv)
{
  const int N = 2;
  const double E0=atof(argv[1]);
  const double phi0= atof(argv[2]);
  const double phidot0=atof(argv[3]);
  state_t y(N); // (T, z)

  // create lambda function: receives one arg (z) and return the final T value minus the expected one.
  struct Fderive {
    double E_=0;
    void operator()(const state_t &y, state_t &dydx, double t){
      dydx[0]=y[1];
      dydx[1]=-E_*y[0];
    }
  };

  auto faux= [&y, phi0, phidot0](double E){
    y[0]=phi0; y[1]=phidot0;
    Fderive j; j.E_ = E;
    boost::numeric::odeint::integrate(j,y,X0,XF,DX);
    return y[0]-0;};
  // perform a Newton-Raphson procedure to find the root
  // compute numerically the derivative
  int nsteps = 0;
  double z0  = newton(E0, faux, 0.000001, nsteps);

  // print final data
  y[0] = phi0; y[1] = phidot0;
  Fderive n; n.E_=z0;
  boost::numeric::odeint::integrate(n, y, X0, XF, DX, print);
  std::cerr << z0 <<std::endl;

  return 0;
}

void print(const state_t & y, double time)
{
  std::cout << time << "\t" << y[0] << std::endl;
}


// xi+1 = xi - f(xi)/f'(xi)
template <class fptr>
double newton(double x0, fptr fun, double eps, int & niter)
{
  double h = 0.00001;
  double xr = x0;
  int iter = 1;
  while(std::fabs(fun(xr)) > eps) {
    double fderiv =  (fun(xr+h/2) - fun(xr-h/2))/h;
    xr = xr - fun(xr)/fderiv;
    iter++;
  }
  niter = iter;
  return xr;
}
