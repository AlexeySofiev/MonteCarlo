#include <iostream>
#include <math.h>

using namespace std;

void init_genrand64(unsigned long long seed);
double genrand64_real3(void);

int Ex1()
{
    cout << "Exercise 1" << endl;

    init_genrand64(431);
    genrand64_real3();
    long double R=0.0;
    int iHit=0, iMiss=0;
    double dMinRatio=double(pow(10,7)), dMaxRatio=0.0, dMeanRatio=0.0;
    double dTemp=0.0;
    int iMaxRepeat=pow(10,1);
    for (int N=1;N<16; N++){
        //cout << "N: "<< N << endl;

        for (int iRepeat=0; iRepeat<iMaxRepeat; iRepeat++){
            iHit=0, iMiss=0;

            for(int iRound=0; iRound<pow(10,7)+3; iRound++){
                R=0.0;
                for(int i=0;i<N;i++){
                    //cout << i <<endl;
                    R=R+pow(2.0*genrand64_real3()-1.0,2);
                }
                if(R>1){
                    iMiss++;
                }else{
                    iHit++;
                }
            }
            //cout << iHit << " "<< iMiss << endl;
            //cout << "Result:" << double(iHit)/(double(iHit)+double(iMiss))*double(pow(2,N))<< endl;
            dTemp=double(iHit)/(double(iHit)+double(iMiss))*double(pow(2,N));
            if(dTemp>dMaxRatio){dMaxRatio=dTemp;}
            if(dTemp<dMinRatio){dMinRatio=dTemp;}
            dMeanRatio+=dTemp;
        }
        cout <<"N: "<<N << ", Volyymi: "<< dMeanRatio/double(iMaxRepeat) << "+-" << max(dMeanRatio/double(iMaxRepeat) - dMinRatio, dMaxRatio - dMeanRatio/double(iMaxRepeat)) << endl;
        //cout << N <<" "<< dMinRatio <<" " << dMaxRatio  <<" " << dMeanRatio << " " << iMiss << " " << iHit << endl;
        dMinRatio=double(pow(10,7)), dMaxRatio=0.0, dMeanRatio=0.0;
    }

    return 0;
}
