#include <iostream>
#include <math.h>

using namespace std;

void init_genrand64(unsigned long long seed);
double genrand64_real3(void);

double fEx4Fuction(double index, int base){
    double result=0.0;
    double f=1.0;
    double i = index;
    while(i>0){
        f = f/base;
        result = result + f * (i % base);
        i = int(i / base);
    }
}

int Ex4()
{
    cout << "Exercise 4" << endl;

    init_genrand64(431);
    genrand64_real3();


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
