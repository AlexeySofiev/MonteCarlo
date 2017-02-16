#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <iomanip>      // std::setprecision

using namespace std;

void init_genrand64(unsigned long long seed);
double genrand64_real3(void);

double fEx3Function1(double x, double lambda){
  double dTemp=exp(x*log(2)-2-log(tgamma(x+1)));
  return dTemp ;
}

int Ex3(){
    std::setprecision(10);
    cout << std::setprecision(10);
    cout << "Exercise 3" << endl;
    long double dExact=0.946997089979748;
    double dCoord1, dCoord2;
    double dLambda=2;
    init_genrand64(431);
//    cout << fEx3Function1(1.3, dLambda)<<endl;

    double dTemp;
	clock_t t1, t2;
	//t1 = clock();
	//Your code here

	// Hit and miss
	cout << "HM" <<endl;
	int iHit=0, iMiss=0, N;
	for(int i=2; i<7; i++){
		t1 = clock();
		iHit=0; iMiss=0;
		N=pow(10,i);
		for(int iRandom=0; iRandom<N; iRandom++){
		      dCoord1=genrand64_real3()*10; 	//x, from 0 to 10
		      dCoord2=genrand64_real3()*0.5;	//y, from 0 to 0.5
		      if(dCoord2<fEx3Function1(dCoord1, dLambda)){
				iHit++;
			}else{
				iMiss++;
			}
		}
        t2 = clock();

        //cout << double(iHit) << " "<<double(iHit+iMiss) <<endl;
        dTemp =0.5*10.0*double(iHit)/double(iHit+iMiss) -dExact;

        cout << "N=10^"<< i <<", ";
        printf("delta I: %.9f ,", dTemp);
        printf("Time: %8.9f sec \n",difftime(t2,t1)/CLOCKS_PER_SEC);

	}

	// DS
	cout << "DS" <<endl;
	double dSum=0.0;
	for(int i=2; i<7; i++){
		t1 = clock();
		iHit=0; iMiss=0;
		N=pow(10,i);
		dSum=0.0;
		for(int iRandom=0; iRandom<N; iRandom++){
		      dCoord1=genrand64_real3()*10; 	//x, from 0 to 10
		      dSum+=fEx3Function1(dCoord1, dLambda);
		}
        t2 = clock();

        //cout << double(iHit) << " "<<double(iHit+iMiss) <<endl;
        dTemp =dSum*10.0/double(N) -dExact;

        cout << "N=10^"<< i <<", ";
        printf("delta I: %.9f ,", dTemp);
        printf("Time: %8.9f sec \n",difftime(t2,t1)/CLOCKS_PER_SEC);

	}


	// SS
	cout << "SS" <<endl;

	for(int i=2; i<7; i++){
		t1 = clock();
		iHit=0; iMiss=0;
		N=pow(10,i);
		dSum=0.0;
		for(int iDx=0;iDx<int(sqrt(N)); iDx++){
            for(int iDy=0;iDy<int(sqrt(N)); iDy++){
                dCoord1=iDx*10.0 /int(sqrt(N))+genrand64_real3()*10.0 /int(sqrt(N));
                dCoord2=genrand64_real3()*0.5 /int(sqrt(N))+ iDy*0.5 /int(sqrt(N));
                if(dCoord2<fEx3Function1(dCoord1, dLambda)){
                    iHit++;
                }else{
                    iMiss++;
                }

            }
		}

        t2 = clock();

        //cout << double(iHit) << " "<<double(iHit+iMiss) <<endl;
        dTemp =double(iHit)/double(iHit+iMiss) *10.0*0.5 -dExact;

        cout << "N=10^"<< i <<", ";
        printf("delta I: %.9f ,", dTemp);
        printf("Time: %8.9f sec \n",difftime(t2,t1)/CLOCKS_PER_SEC);

	}




	// PSS
	cout << "PSS" <<endl;

	for(int i=2; i<7; i++){
		t1 = clock();
		iHit=0; iMiss=0;
		N=pow(10,i);
		dSum=0.0;
		for(int iDx=0;iDx<100; iDx++){
                dCoord1=iDx*10.0 /100.0+genrand64_real3()*10.0 /100.0;

                for(int iRand=0; iRand<N/100    ; iRand++){
                    dCoord2=genrand64_real3()*0.5;
                    if(dCoord2<fEx3Function1(dCoord1, dLambda)){
                        iHit++;
                    }else{
                        iMiss++;
                    }
                }
            }

        t2 = clock();

        //cout << double(iHit) << " "<<double(iHit+iMiss) <<endl;
        dTemp =double(iHit)/double(iHit+iMiss) *10.0*0.5 -dExact;

        cout << "N=10^"<< i <<", ";
        printf("delta I: %.9f ,", dTemp);
        printf("Time: %8.9f sec \n",difftime(t2,t1)/CLOCKS_PER_SEC);


	}





//	printf("Time: %8.5f sec", difftime(t2,t1)/CLOCKS_PER_SEC)


    return 0;
}

