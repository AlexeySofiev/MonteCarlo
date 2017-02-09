#include <iostream>
#include <math.h>
#include <fstream>


using namespace std;

void seed_lcg(unsigned long seed);
double rand_lcg(void);
void seed_pm( long seed);
double rand_pm(void);


double dShufflingTable[32]={0};

double fMyShufflingLCG(){
        double dTemp=rand_lcg();
        double dTemp2=rand_lcg()*32;
        double dTemp3=dShufflingTable[int(dTemp2)];
        dShufflingTable[int(dTemp2)]=dTemp;
        return dTemp3;
}


void Ex2(){

    cout << "Ex2" << endl;
    double dTemp;
    int iTemp;

    ofstream myfile;
    int N=pow(10,7), k=pow(10,6);
    int iRounds=100;

    seed_lcg(15);


    double c1=0.0;
    double c2=0.0;
    double c3=0.0;

    double dA0;

    myfile.open("data/ex2lcg.txt");
    for(int iRound=0; iRound<iRounds;iRound++){
    c1=0.0;
    c2=0.0;
    c3=0.0;
    dA0=rand_lcg();
    dTemp=dA0;
    c1=c1+dA0*dTemp;
    c2=c2+dTemp;
    c3=c3+pow(dTemp,2);
    for(int iIter=0;iIter<N-k;iIter++){
        dTemp=rand_lcg();
        c1=c1+dA0*dTemp;
        c2=c2+dTemp;
        c3=c3+pow(dTemp,2);
    }
    c1=c1/(N-k);
    for(int iIter=N-k; iIter<N;iIter++){
        dTemp=rand_lcg();
        c2=c2+dTemp;
        c3=c3+pow(dTemp,2);
    }
    c2=c2/N;
    c2=pow(c2,2);

    c3=c3/pow(N,2);




    cout << "LCG Ck= " << (c1-c2)/(c3-c2) << endl;

    myfile << (c1-c2)/(c3-c2) << "\n";
    }
    myfile.close();

    //pm
    seed_pm(7895);
    myfile.open("data/ex2pm.txt");
    for(int iRound=0; iRound<iRounds;iRound++){
    c1=0.0;
    c2=0.0;
    c3=0.0;
    dA0=rand_pm();
    dTemp=dA0;
    c1=c1+dA0*dTemp;
    c2=c2+dTemp;
    c3=c3+pow(dTemp,2);
    for(int iIter=0;iIter<N-k;iIter++){
        dTemp=rand_pm();
        c1=c1+dA0*dTemp;
        c2=c2+dTemp;
        c3=c3+pow(dTemp,2);
    }
    c1=c1/(N-k);
    for(int iIter=N-k; iIter<N;iIter++){
        dTemp=rand_lcg();
        c2=c2+dTemp;
        c3=c3+pow(dTemp,2);
    }
    c2=c2/N;
    c2=pow(c2,2);

    c3=c3/pow(N,2);

    cout << "PM Ck= " << (c1-c2)/(c3-c2) << endl;
    myfile << (c1-c2)/(c3-c2) << "\n";
    }
    myfile.close();

    // LCG with shuffling

    seed_lcg(15);



    myfile.open("data/ex2lcgShuffle.txt");

    for(int iRound=0; iRound<iRounds;iRound++){
     // Initializing LCG shuffle table

    for (int i=0;i<32;i++){
        dShufflingTable[i]=rand_lcg();
    }
    c1=0.0;
    c2=0.0;
    c3=0.0;
    dA0=fMyShufflingLCG();
    dTemp=dA0;
    c1=c1+dA0*dTemp;
    c2=c2+dTemp;
    c3=c3+pow(dTemp,2);
    for(int iIter=0;iIter<N-k;iIter++){
        dTemp=fMyShufflingLCG();
        c1=c1+dA0*dTemp;
        c2=c2+dTemp;
        c3=c3+pow(dTemp,2);
    }
    c1=c1/(N-k);
    for(int iIter=N-k; iIter<N;iIter++){
        dTemp=rand_lcg();
        c2=c2+dTemp;
        c3=c3+pow(dTemp,2);
    }
    c2=c2/N;
    c2=pow(c2,2);

    c3=c3/pow(N,2);




    cout << "LCG with shuffling Ck= " << (c1-c2)/(c3-c2) << endl;
    myfile << (c1-c2)/(c3-c2) << "\n";
    }
    myfile.close();

 /*
    double dTemp1, dTemp2;

    int iNumRandMax=pow(10,6);

    int aRandoms[iNumRandMax]={0};
    seed_lcg(15);
    for (int iLoop=0; iLoop<iNumRandMax;iLoop++){
        aRandoms[iLoop]=rand_lcg();
    }

     //start of the first sequence
    dTemp1=rand_lcg()*(pow(10,6)-pow(10,5));
    int k1=int(dTemp1);
     //start of the second sequence
    dTemp1=rand_lcg()*(pow(10,6)-pow(10,5));
    int k2=int(dTemp1);

    double c1,c2,c3,c4;
    double dSumC1=0;
    for (int i=0; i<pow(10,5);i++){
//        dSumC1+=aRandoms[k1+i]*aRandoms[k1+k2+i];
    }

*/

}

