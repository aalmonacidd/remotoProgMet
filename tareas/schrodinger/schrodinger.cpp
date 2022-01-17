#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <boost/numeric/odeint.hpp>
#define PI 3.141592653
// constants

const double X0 = 0;
const double XF = PI*0.5;
const double DX = 0.01;

typedef std::vector<double> state_t; // alias for state type

void print(const state_t & y, double time);
template <class fptr>
double newton(double x0, fptr fun, double eps, int & niter);

int main(int argc, char **argv)
{
  const int N = 2;
  const double E=atof(argv[1]);
  const double phi0= atof(argv[2]);
  const double phidot0= atof(argv[3]);

  state_t y(N); // (T, z)

  struct Fderiv{
    double E_=0;
    void operator()(const state_t & y, state_t & dydx,double E_){
    dydx[0]=y[1];
    dydx[1]=-E_*y[0];
    }
  };

  // create lambda function: receives one arg (Energy) and return the final T value minus the expected one.
  auto faux = [&y, phi0, phidot0](double E){
    y[0] = phi0; y[1] = phidot0;
    Fderiv j; j.E_ = E;
    boost::numeric::odeint::integrate(j, y, X0, XF, DX);
    return y[0] - 0;};

  // perform a Newton-Raphson procedure to find the root
  // compute numerically the derivative
  int nsteps = 0;
  double z0  = newton(-10, faux, 0.001, nsteps);
  y[0]=phi0;y[1]=phidot0;
  Fderiv j; j.E_ =E;
  boost::numeric::odeint::integrate(j,y,X0,XF,DX,print);
  // print final data
  return 0;
}

void print(const state_t & y, double time)
{
    std::cout << time << "\t"  << "\t" << -y[1] << std::endl;
}



// xi+1 = xi - f(xi)/f'(xi)
template <class fptr>
double newton(double x0, fptr fun, double eps, int & niter)
{
  double h = 0.0001;
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
