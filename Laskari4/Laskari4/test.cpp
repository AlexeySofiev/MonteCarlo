#include <iostream>
#include <random>
#include <math.h>
#include <fstream>



using namespace std;
void init_genrand64(unsigned long long seed);
double genrand64_real3(void);
double n(double E, int N, double V, double kB, double T);

/*
double n(double E, int N, double V, double kB, double T){

    return 2.0/pow(M_PI,0.5) * double(N)/V * pow(E, 0.5) / pow(kB *T, 1.5) *exp(-E/(kB*T));
}
*/

int test()
{
    cout << "debug" << endl;
    ofstream myfile;

    init_genrand64(431);
    genrand64_real3();

    double kB=8.6173324*pow(10, -5);
    double T = 300.0;
    int iNRuns=500;
    double V = 10; // volume
    int N=1000;

    double x;
    double x0;
    double xNew;
    double u;
    double dXmax=0.5;
    double dRho0=n(x, N, V, kB, T);
    double dX0=x;
    double dRho;
    double dRhoNew;
    double u1;
    bool bJatketaanko;
    int iIter=0;
    myfile.open ("data/ex1.txt");

//    for(int i=0; i<100; i++){
        //cout << n(genrand64_real3(), N, V, kB, T) << endl;

        bJatketaanko=true;
        iIter=0;
//        cout << i << endl;
//        while(bJatketaanko){
            // Select an initial configuration x, p(x)>0
            x=genrand64_real3();
            dRho=n(x, N, V, kB, T);
            while(dRho<0){
                x=genrand64_real3();
                dRho=n(x, N, V, kB, T);
            }

            //cout << "Starting MC" << endl;
            //Choose a maximum displacement value dXmax
            dXmax=0.1;

            //Calculate the initial rho
            dRho=n(x, N, V, kB, T);

            //Store the current state
            x0=x;

            // Generate a random number vector u, [-1,1]
            u=genrand64_real3()*2-1;

            //Generate a new trial state xNew = x + u*dXmax
            xNew=x+ u*dXmax;

            //Calculate the value of the function in the trial state
            dRhoNew=n(xNew, N, V, kB, T);

            cout << "x0: " << x0 <<endl;
            cout << "dRho: " << dRho <<endl;
            cout << "dRhoNew " << dRhoNew <<endl;

            if(dRhoNew/dRho >=1){
                dRho=dRhoNew;
                x=xNew;
            }else{
                u1=genrand64_real3();
                cout << "u1: " << u1 << endl;
                if(dRhoNew/dRho >=u1){
                    dRho=dRhoNew;
                    x=xNew;
                }else{
                    x=x0;
                    bJatketaanko=false;
//                    cout << i << " ended."<< endl;
                }

            }

            iIter++;
            if(iIter>pow(10,5)){
                bJatketaanko=false;
                cout << "Max iterations limit reached" <<endl;
            }
 //       }



        myfile << x<<"\n";
//    }

    myfile.close();

    return 0;
}

