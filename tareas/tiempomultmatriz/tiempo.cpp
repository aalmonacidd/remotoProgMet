#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

void multiply(const std::vector<double> & m1, const std::vector<double> & m2, std::vector<double> & m3);
double sumaterminos(const std::vector<double> & m1, const std::vector<double> & m2, int i, int j, int N);

int main(int argc, char **argv) {
    const int SEED = std::atoi(argv[1]);
    double durcuatro=1;//inicializar variable de duracion para matrices 4*4
    for(int k=2;k<=9;k++){
        int N=pow(2,k);
        std::vector<double> A(N*N, 0.0), B(N*N, 0.0), C(N*N, 0.0);
        std::mt19937 gen(SEED);
        std::uniform_real_distribution<> dist(0.,1.);
        // lambda function: a local function that captures [] something, receives something (), and return something {}
        // See: https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
        std::generate(A.begin(), A.end(), [&gen, &dist](){ return dist(gen); }); // uses a lambda function
        std::generate(B.begin(), B.end(), [&gen, &dist](){ return dist(gen); }); // uses a lambda function

      // multiply the matrices A and B and save the result into C. Measure time
      auto start = std::chrono::high_resolution_clock::now();
      multiply(A, B, C);
      auto stop = std::chrono::high_resolution_clock::now();

      // use the matrix to avoid the compiler removing it
      C[N/2];
      std::cout<<"Proporción de tiempo entre 4 y N, para N="<<N<<std::endl;

      // print time
      auto elapsed = std::chrono::duration<double>(stop - start);
      if(k==2){
          durcuatro=elapsed.count();
      }
      std::cout << elapsed.count()/durcuatro << "\n\n";
}
  return 0;
}

// implementations
void multiply(const std::vector<double> & m1, const std::vector<double> & m2, std::vector<double> & m3)
{
  const int N = std::sqrt(m1.size()); // assumes square matrices
  for(int o=0;o<N;o++){
      for(int p=0;p<N;p++){
          m3[o*N+p]=sumaterminos(m1,m2,o,p,N);//función que realiza la operación para cada elemento de la matriz
      }
  }
}

double sumaterminos(const std::vector<double> & m1, const std::vector<double> & m2, int i, int j, int N){
    double suma=0;
    for(int k=0;k<N;k++){
        suma=m1[i*N+k]*m2[k*N+j]; //indices de dos dimensiones a vector 1d
    }
    return suma;
}
