#include <iostream>
#include <math.h>

using namespace std;

void init_genrand64(unsigned long long seed);
double genrand64_real3(void);

int Ex2()
{
    cout << "Exercise 2" << endl;

    init_genrand64(431);
    genrand64_real3();
    long double R=0.0;
    double dMinRatio=double(pow(10,7)), dMaxRatio=0.0, dMeanRatio=0.0;
    double dTemp=0.0;
    int iBins=40;
    double dBinLength=1.0/double(iBins); //symmetricy
    double aPosition[15]={-1};
    double aTempPosition[15]={-1};
    int iHit, iMiss;

    int iMaxRepeat=pow(10,1);
    for (int N=1;N<16; N++){
        // cout << "N: "<< N << endl;
        // for each N
        iHit=0;
        iMiss=0;
        aPosition[15]={-1};
        dMinRatio=double(pow(10,7)), dMaxRatio=0.0, dMeanRatio=0.0;
        for(int iRepeat=0; iRepeat<iMaxRepeat;iRepeat++){
            for(int i=0; i<pow(iBins, N)+1;i++){
                R=0;
                for(int iArrayPass=0; iArrayPass<N+1; iArrayPass++){
                    aTempPosition[iArrayPass]=aPosition[iArrayPass]+genrand64_real3()*dBinLength;
                    R=R+pow(aTempPosition[iArrayPass],2);
                }
                if(R<1){
                    iHit++;
                }else{
                    iMiss++;
                }
                aPosition[0]+=dBinLength;
                for(int iArrayPass=0; iArrayPass<N; iArrayPass++){
                    if(aPosition[iArrayPass]>0){ //symmetricy
                        aPosition[iArrayPass]=-1;
                        aPosition[iArrayPass+1]+=dBinLength;
                    }
                }
                //aMatrix[i]=genrand64_real3();
            }

            // cout << "N: " << N <<", Volume: " << double(iHit)/double(iMiss + iHit) *double(pow(2,N))<< endl;
            dTemp=double(iHit)/(double(iHit)+double(iMiss))*double(pow(2,N));
            if(dTemp>dMaxRatio){dMaxRatio=dTemp;}
            if(dTemp<dMinRatio){dMinRatio=dTemp;}
            dMeanRatio+=dTemp;
        }
        cout <<"N: "<<N << ", Volyymi: "<< dMeanRatio/double(iMaxRepeat) << "+-" << max(dMeanRatio/double(iMaxRepeat) - dMinRatio, dMaxRatio - dMeanRatio/double(iMaxRepeat)) << endl;


    }

    return 0;
}

