#include <iostream>
#include <cmath>
#include <cstdlib>

double f(double);
template <class fptr>
double bisection(double xl, double xu, fptr fun, double eps, int & niter);
template <class fptr>
double bisectionrec(double xl, double xu, fptr fun, double eps, int & niter);

int main(int argc, char **argv)
{
  std::cout.precision(6); std::cout.setf(std::ios::scientific);

  const double XL = std::atof(argv[1]);
  const double XU = std::atof(argv[2]);
  double EPS[4];
  for(int i=3;i<=6;i++){
    EPS[i-3] = std::atof(argv[i]);
  }
  int counter = 0;
  std::cout << "EPS        \t"<<"Biseccion for   \t"<<"Biseccion recursiva"<< std::endl;
  for(int i=0;i<4;i++){
    std::cout << EPS[i] <<"\t"<<bisection(XL,XU,f,EPS[i],counter)<<"\t"<< bisectionrec(XL, XU, f, EPS[i], counter) << std::endl;
  }
  return 0;
}

double f(double x)
{
  return 9.81*(68.1)*(1 - std::exp(-x*10/68.1))/x - 40;
}

template <class fptr>
double bisection(double xl, double xu, fptr fun, double eps, int & niter)
{
  double xr = 0;
  int iter = 1;
  for( ;  ; ) { // while(true)
    xr = (xl + xu)/2; // bisection
    // encontre la raiz?
    if (std::fabs(fun(xr)) <= eps) break;
    // actualizar los limites
    iter++;
    if (fun(xr)*fun(xl) < 0) {
      xu = xr;
    } else {
      xl = xr;
    }
  }
  niter = iter;
  return xr;
}

template <class fptr>
double bisectionrec(double xl, double xu, fptr fun, double eps, int & niter){
  double xr=0;
  int iter=1;
  xr = ( xl + xu)/2; //biseccion
  if(std::fabs(fun(xr))<=eps) return xr;
  iter++;
  if(fun(xr)*fun(xl) < 0){
    return bisectionrec(xl,xr,fun,eps,niter);//recursividad actualizando límites
  }
  else{
    return bisectionrec(xr,xu,fun,eps,niter);
  }
}
