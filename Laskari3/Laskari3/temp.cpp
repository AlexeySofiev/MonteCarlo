#include <iostream>
#include <math.h>
#include "randoms.h"
#include <time.h>
#include <stdio.h>

using namespace std;

void init_genrand64(unsigned long long seed);
double genrand64_real3(void);

double fEx3Function1(double x, double lambda){
  double dTemp=exp(x*log(2)-2-log(tgamma(x+1)));  
  return dTemp ;
}

int main(){
    cout << "Exercise 3" << endl;
    long double dExact=0.946997089979748;
    double dCoord1, dCoord2;
    double dLambda=2;
    init_genrand64(431);
//    cout << fEx3Function1(1.3, dLambda)<<endl;

	clock_t t1, t2;
	t1 = clock();
	//Your code here
	
	// Hit and miss
	cout << "HM" <<endl;
	int iHit=0, iMiss=0, N;
	for(int i=2; i<7; i++){
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
	}
	


	t2 = clock();
//	printf("Time: %8.5f sec", difftime(t2,t1)/CLOCKS_PER_SEC)
	cout << double(iHit)/double(iHit+iMiss) <<endl;
	printf("delta I: %8.5f \n",double(iHit)/double(iHit+iMiss)-dExact);
	
	printf("Time: %8.5f sec",difftime(t2,t1)/CLOCKS_PER_SEC);


    return 0;
}


