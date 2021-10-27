#include <iostream>

int main(void){
  int a=9;
  std::cout<<a<<"\n";
  std::cout<<&a<<"\n";
  {
    int a=10;
    std::cout<<a<<"\n";
    std::cout<<&a<<"\n";
  }

  std::cout<<a<<"\n";
 std::cout<<&a<<"\n";

  return 0;
}
