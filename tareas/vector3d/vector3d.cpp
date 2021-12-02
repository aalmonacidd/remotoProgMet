#include <iostream>
#include "vector.h"
int main()
{
    Vector v1(1,2,3), v2(4,5,6);
    Vector v3 = v1+v2;
    v3.print();
    std::cout << v1*v2 <<std::endl;
}
