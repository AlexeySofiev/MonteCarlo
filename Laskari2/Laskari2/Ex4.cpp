#include <iostream>
#include <math.h>
#include <fstream>


using namespace std;

void init_genrand64(unsigned long long seed);
double genrand64_real3(void);


double f(double x){
    return (20/(M_PI *(x*x+4)));
}

void Ex4(){

    ofstream myfile, myfile2;
    // Initializing Mersenne
    init_genrand64(431);
    //genrand64_real3();

    //inversion method
    // x=2*tan(u*pi^2 /20)

    double dRandInv;


    myfile.open("data/ex4inv.txt");
    for(int i=0; i<pow(10,6);i++){
        //dRandInv=2*tan(genrand64_real3()*M_PI*M_PI/20);
        dRandInv=2.0*tan(genrand64_real3()*M_PI/2.0);
        myfile << (dRandInv) << "\n";
        dRandInv=2.0*tan(genrand64_real3()*M_PI/2.0);
        myfile << -(dRandInv) << "\n";  // Tangens symmetry elimination
        //cout << dRandInv <<endl;
        //cout << f(dRandInv) <<endl;
    }
    myfile.close();

    // Combined method
    double u1, u2;
    double phi, r;
    double x,y;
    int iHit, iMiss;

    init_genrand64(431);

    myfile.open("data/ex4combHist.txt");
    myfile2.open("data/ex4combHistMiss.txt");

    for(int i=0;i<pow(10,7);i++){
        u1=genrand64_real3();
        u2=genrand64_real3();
        phi=M_PI*u1 /8 *M_PI/180;
        r=pow(-2*log(u2), 0.5); // 1-u is same as u*, since u 0--1
        x=r*cos(phi)*sqrt(20);
        y=r*sin(phi);

        if(y<f(x)){
            iHit++;
            myfile << x <<" "<< y << "\n";
        }else{
            iMiss++;
            myfile2 << x <<" "<< y << "\n";
        }
    }
    cout << "Hits: " << iHit <<endl;
    cout << "Misses: "<< iMiss <<endl;
    myfile.close();
    myfile2.close();

}
