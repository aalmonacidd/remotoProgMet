#include <iostream>
#include <cmath>

double DeltaTrap(int n);
double DeltaSimp(int n);
double trapecio(double a, double b, int n);
double simpson(double a, double b, int n);
double fun(double x);
double exacto(double x);

int main()
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    std::cout<<"10"<<"\t"<<DeltaTrap(10)<<"%"<<"\t"<<DeltaSimp(10)<<"%"<<"\n"<<
    "1000"<<"\t"<<DeltaTrap(1000)<<"%"<<"\t"<<DeltaSimp(1000)<<"%"<<"\n";
    return 0;
}


double fun(double x){
    return x*(std::sin(x));
}
double exacto(double x){
    double resultado= (std::sin(x)-x*std::cos(x));
    return resultado;
}

double DeltaTrap(int n){
    double T= trapecio(0,4,n);
    return std::abs(T-exacto(4))/exacto(4)*100;
}

double DeltaSimp(int n){
    double S= simpson(0,4,n);
    return std::abs(S-exacto(4))/exacto(4)*100;
}

double trapecio(double a, double b, int n){
    double h=(b-a)/n;
    double suma=0;
    for(int i=1;i<=n-1;i++){
        suma+=2*fun(i*h);
    }
    suma+=fun(a)+fun(b);
    suma*=h/2;
    return suma;
}

double simpson(double a, double b, int n){
    double h=(b-a)/n;
    double suma=0,s1=0,s2=0;
    for(int i=1;i<=n/2;i++){
        s1+=4*fun((2*i-1)*h);
    }
    for(int i=1;i<=(n-2)/2;i++){
        s2+=2*fun(2*i*h);
    }
    suma+=fun(a)+s1+s2+fun(b);
    suma*=h/3;
    return suma;
}
