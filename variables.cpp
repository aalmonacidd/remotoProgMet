#include <iostream>

int main(){
  float f;
  bool b= false;
  double d;
  float n=1.0e40;
  std::cout<<f<<"\n"<<b<<"\n"<<d<<" "<<&d<<"\n"<<sizeof(double)<<"\n"<< n<<"\n";
  //Expresa este número como inf ya que supera los límites máximos
  //a los que puede llegar una variable tipo float. 
}
