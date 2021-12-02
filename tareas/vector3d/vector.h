#pragma once
#include <iostream>
struct Vector
{
    double x,y,z;
    Vector(int a=0, int b=0, int c=0){x=a; y=b; z=c;}

    Vector operator + (Vector const &obj){
        Vector sum;
        sum.x = x+obj.x;
        sum.y = y+obj.y;
        sum.z = z+obj.z;
        return sum;
    }

    double operator * (Vector const &obj){
        return (x*obj.x)+(y*obj.y)+(z*obj.z);
    }

    void print() {std::cout<< x << "\t" << y <<"\t" << z << "\t"<<std::endl;}
};
