#include <iostream>
#include <math.h>
#include <fstream>


using namespace std;

void init_genrand64(unsigned long long seed);
double genrand64_real3(void);


double fFunctionEx3(double x){
    if((1-pow(x,4)/10 *exp(-x/2)*sin(5*x)*sin(5*x)) >0){
        return (1-pow(x,4)/10 *exp(-x/2)*sin(5*x)*sin(5*x));
    }else{
        return -(1-pow(x,4)/10 *exp(-x/2)*sin(5*x)*sin(5*x));
    }
}

void Ex3(){
    cout << "Ex3" <<endl;
    ofstream myfile, myfile2;
    // Initializing Mersenne
    init_genrand64(431);
    //genrand64_real3();

    // First approach, hit and miss
    int iHit=0, iMiss=0;
    int iModHit=0, iModMiss=0;
    double x,y,ymod,dCurrentB;
    double dBTable[4]={1,2,5,10};

    for(int b=0;b<4;b++){
        cout << "b= "<< dBTable[b]<<endl;
        for(int i=0;i<pow(10,6);i++){
            x=genrand64_real3()*dBTable[b];
            y=genrand64_real3()*7;
            if(y<fFunctionEx3(x)){
                iHit++;
            }else{
                iMiss++;
            }

            // modified method
            if(x<4){
                ymod=genrand64_real3()*3;
            }else{
                ymod=genrand64_real3()*7;
            }
            if(ymod<fFunctionEx3(x)){
                iModHit++;
            }else{
                iModMiss++;
            }


        }
        cout << "Basic method, hits: "<< iHit << endl;
        cout << "Basic method, misses:" << iMiss << endl;

        cout << "Combined method, hits: "<< iModHit << endl;
        cout << "Combined method, misses:" << iModMiss << endl;
    }


}
