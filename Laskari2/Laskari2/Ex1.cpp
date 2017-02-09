#include <iostream>
#include <math.h>
//#include "randoms.h"
#include <fstream>
void seed_lcg(unsigned long seed);
double rand_lcg(void);
void seed_pm( long seed);
double rand_pm(void);
void init_genrand64(unsigned long long seed);
double genrand64_real3(void);


using namespace std;

void Ex1(){
    int iPoints=pow(10,6);
    int iNumBins = 60; // M

    cout << "\n  Exercise 1 "<<endl;
    cout << "Number of bins: " << iNumBins << endl;

    double dRandLcg,b,c;
    seed_lcg(15);   //Pu
    int iNumTests=6;
    int iBinResult[iNumBins][iNumTests]={0};
    //fill(iBinResult, iBinResult+int(dNumBins), 0);

    // Initialization as zero, fill was somehow bugged...
    for (int iTempVar1=0; iTempVar1<iNumBins;iTempVar1++){
        for (int iTempVar2=0; iTempVar2<iNumTests; iTempVar2++){
            iBinResult[iTempVar1][iTempVar2]=0;
        }
    }
    // End of array initialization


    // Binning
    for (int iTest=0; iTest<iNumTests; iTest++){
        for (int iPoint=0; iPoint<iPoints; iPoint++){
            dRandLcg = rand_lcg()*60;
            iBinResult[int(dRandLcg)][iTest]++;
         }
     }
/*
     for (int i=0; i<iNumBins;i++){
        cout << i << " ";
        for (int j=0; j<iNumTests;j++){
        cout <<iBinResult[i][j] << " ";
        }
        cout<< endl;
     }
*/

    // Saving
     ofstream myfile ("data/ex1_data_lcg.txt");
     if (myfile.is_open()){

        for (int i=0; i<iNumBins;i++){
            myfile << i << " ";
            for (int j=0; j<iNumTests;j++){
            myfile <<iBinResult[i][j] << " ";
            }
            myfile<< "\n";
        }


        myfile.close();
     }
//----------------------------------------------------------------------------
// PM



     seed_pm(7895);

    iBinResult[iNumBins][iNumTests]={0};
    //fill(iBinResult, iBinResult+int(dNumBins), 0);

    // Initialization as zero, fill was somehow bugged...
    for (int iTempVar1=0; iTempVar1<iNumBins;iTempVar1++){
        for (int iTempVar2=0; iTempVar2<iNumTests; iTempVar2++){
            iBinResult[iTempVar1][iTempVar2]=0;
        }
    }
    // End of array initialization


    // Binning
    for (int iTest=0; iTest<iNumTests; iTest++){
        for (int iPoint=0; iPoint<iPoints; iPoint++){
            dRandLcg = rand_pm()*60;
            iBinResult[int(dRandLcg)][iTest]++;
         }
     }


    // Saving
     myfile.open("data/ex1_data_pm.txt");
     if (myfile.is_open()){

        for (int i=0; i<iNumBins;i++){
            myfile << i << " ";
            for (int j=0; j<iNumTests;j++){
            myfile <<iBinResult[i][j] << " ";
            }
            myfile<< "\n";
        }


        myfile.close();
     }

     //----------------------------------------------------------------------------
// MT


    init_genrand64(431);

    iBinResult[iNumBins][iNumTests]={0};
    //fill(iBinResult, iBinResult+int(dNumBins), 0);

    // Initialization as zero, fill was somehow bugged...
    for (int iTempVar1=0; iTempVar1<iNumBins;iTempVar1++){
        for (int iTempVar2=0; iTempVar2<iNumTests; iTempVar2++){
            iBinResult[iTempVar1][iTempVar2]=0;
        }
    }
    // End of array initialization


    // Binning
    for (int iTest=0; iTest<iNumTests; iTest++){
        for (int iPoint=0; iPoint<iPoints; iPoint++){
            dRandLcg = genrand64_real3()*60;
            iBinResult[int(dRandLcg)][iTest]++;
         }
     }


    // Saving
     myfile.open("data/ex1_data_mt.txt");
     if (myfile.is_open()){

        for (int i=0; i<iNumBins;i++){
            myfile << i << " ";
            for (int j=0; j<iNumTests;j++){
            myfile <<iBinResult[i][j] << " ";
            }
            myfile<< "\n";
        }


        myfile.close();
     }


}
