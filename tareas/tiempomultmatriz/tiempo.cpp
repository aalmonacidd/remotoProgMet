#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>

void multiply(const std::vector<double> & m1, const std::vector<double> & m2, std::vector<double> & m3);
double sumaterminos(const std::vector<double> & m1, const std::vector<double> & m2, int i, int j, int N);

int main(int argc, char **argv) {
    const int SEED = std::atoi(argv[1]);
    double durcuatro=1;//inicializar variable de duracion para matrices 4*4
    std::ofstream fout("GraficaTiempos.txt");
    for(int k=2;k<=9;k++){
        int N=pow(2,k);
        std::vector<double> A(N*N, 0.0), B(N*N, 0.0), C(N*N, 0.0);
        std::mt19937 gen(SEED);
        std::uniform_real_distribution<> dist(0.,1.);
        // lambda function: a local function that captures [] something, receives something (), and return something {}
        // See: https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
        std::generate(A.begin(), A.end(), [&gen, &dist](){ return dist(gen); }); // uses a lambda function
        std::generate(B.begin(), B.end(), [&gen, &dist](){ return dist(gen); }); // uses a lambda function // multiply the matrices A and B and save the result into C. Measure time
        auto start = std::chrono::high_resolution_clock::now();
        multiply(A, B, C);
        auto stop = std::chrono::high_resolution_clock::now();

        // use the matrix to avoid the compiler removing it
        C[N/2];
        std::cout<<"Tiempo para N="<<N<<std::endl;
        // print time
        auto elapsed = std::chrono::duration<double>(stop - start);
        if(k==2){
          durcuatro=elapsed.count();
        }
        std::cout << elapsed.count()/durcuatro << "\n\n";

        //Impresion en archivo
        fout<< N <<"\t"<< elapsed.count()/durcuatro << "\n";
}
  return 0;
}

// implementations
void multiply(const std::vector<double> & m1, const std::vector<double> & m2, std::vector<double> & m3)
{
  const int N = std::sqrt(m1.size()); // assumes square matrices
  int i=1;
  int a=0;
  for(int o=0;o<N;o++){
      for(int p=0;p<N;p++){
        m3[o*N+p]=sumaterminos(m1,m2,o,p,N);
      }
  }
}

double sumaterminos(const std::vector<double> & m1, const std::vector<double> & m2, int i, int j, int N){
    double suma=0;
    for(int k=0;k<N;k++){
        suma+= (m1[i*N+k]*m2[k*N+j]); //indices de dos dimensiones a vector 1d
    }
    return suma;
}
