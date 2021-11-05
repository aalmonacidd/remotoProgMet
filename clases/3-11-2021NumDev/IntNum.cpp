#include <iostream>
#include <cmath>

double fun(double x);

int main(int argc, char **argv){
  const double n=std::atoi(argv[1]);
  std::cout.precision(7);
  const double x=(1/n);
  double T=fun(1)+fun(2);
  for(double i=1+x;i<=2;i+=x){
    T+=2*fun(i);
    std::cout<<T<<std::endl;
  }
  std::cout<<T*x/2<<std::endl;
  return 0;
}


double fun(double x){
  return std::exp(std::pow(x,3));
}
