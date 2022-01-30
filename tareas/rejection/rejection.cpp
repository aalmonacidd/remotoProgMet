#include <iostream>
#include <vector>
#include <random>
#include <fstream>

void pdf(double SEED, double SAMPLES, double XMIN, double XMAX, int NBINS, double DX);

int main(int argc, char **argv)
{
    const double SEED=std::atof(argv[1]);
    const double SAMPLES=std::atof(argv[2]);
    const double XMIN= std::atof(argv[3]);
    const double XMAX= std::atof(argv[4]);
    const int NBINS= std::atof(argv[5]);
    const double DX=(XMAX-XMIN)/NBINS;
    pdf(SEED,SAMPLES,XMIN,XMAX,NBINS,DX);

    return 0;
}

void pdf(double SEED, double SAMPLES, double XMIN, double XMAX, int NBINS, double DX){
    std::vector<double> histo(NBINS,0.0);
    std::ofstream fout("datos.txt");
    std::mt19937 gen(SEED);
    std::uniform_real_distribution<double> disx(-1.0, 1.0);
    std::uniform_real_distribution<double> disy(0.0,3.0/4.0);
    int k=0;
    for(int i=0;k<=SAMPLES;i++){
        double x=disx(gen);
        double y=disy(gen);
        double fx=3.0/4.0*(1-(x*x));
        int bin=int((x-XMIN)/DX);
        if(y<fx){
            fout<<x<<"\t"<<y<<"\n";
            if(0<= bin && bin<NBINS){
                histo[bin]++;
                k++;
            }
        }
    }
    fout.close();

    std::ofstream gout("densidad.txt");
    for(int i=0;i<NBINS;i++){
        gout<<XMIN+(i*DX)<<"\t"<<histo[i]/(DX*SAMPLES)<<"\n";
    }
    gout.close();

}
