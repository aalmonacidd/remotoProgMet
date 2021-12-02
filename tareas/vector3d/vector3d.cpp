#include <iostream>

struct Vector
{
    double x,y,z;
    Vector(double a=0.0, double b=0.0, double c=0.0){x=a; y=b; z=c;}//Constructor
    ~Vector(){};//Destructor


    Vector operator + (Vector const &obj){//+ overload
        Vector sum;
        sum.x = x+obj.x;
        sum.y = y+obj.y;
        sum.z = z+obj.z;
        return sum;
    }



    double operator * (Vector const &obj){// * overload
        return (x*obj.x)+(y*obj.y)+(z*obj.z);
    }

    void print() {std::cout<< x << "\t" << y <<"\t" << z << "\t"<<std::endl;}//funcion print vector

};


int main()
{

    Vector v1(1.0,2.0,3.0), v2(4.0,5.0,6.0);
    Vector v3 = v1+v2;
    v3.print();
    std::cout << v1*v2 <<std::endl;
}
