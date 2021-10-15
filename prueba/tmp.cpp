
#include <iostream>

using namespace std;

int main(){
  int a,i,suma=0;
  std::cin>>a;
  for(i=0;i<=a;i++){
    suma+=i;
    std::cout<<i<<"\n";
  }
  std::cout<<"La suma de los n primeros números es: "<<suma<<"\n";
  std::cout<<"Hola Mundo!\n";
  return 0;
}
