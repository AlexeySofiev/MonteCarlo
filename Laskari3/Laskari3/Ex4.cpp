#include <iostream>
#include <math.h>
#include <iomanip>      // std::setprecision

using namespace std;

void init_genrand64(unsigned long long seed);
double genrand64_real3(void);

double fEx4Fuction(int index, int base){
    double result=0.0;
    double f=1.0;
    int i = index;
    while(i>0){
        f = f/base;
        result = result + f * (i % base);
        i = int(i / base);
    }
    return result;
}

int Ex4()
{
    cout << "Exercise 4" << endl;

    init_genrand64(431);
    genrand64_real3();

    for(int n=501; n<511; n++){
        cout << setprecision(7)<< "n: "<< n<< ", value base 7: " << fEx4Fuction(n, 7) << ", value base 13: " << fEx4Fuction(n, 13) << endl;

    }

    return 0;
}

/*
FUNCTION (index, base)
   BEGIN
       result = 0;
       f = 1;
       i = index;
       WHILE (i > 0)
       BEGIN
           f = f / base;
           result = result + f * (i % base);
           i = FLOOR(i / base);
       END
       RETURN result;
   END
   */
