/*

Exercise 1.2 of the course Basics of Monte Carlo Simulations 2012.

Implementation of LCG, Park-Miller and Mersenne twister RNGs .

Eero Holmstrom 2011
rev. Konstantin Avchaciov 2012
rev. 2014
rev. Junlei Zhao 2015
rev. Junlei Zhao 2017

*/

#include <stdio.h>

//LCG starts here
static unsigned long iseed_lcg = 7;
#define IA 3557181
#define IC 1547
#define IM 113829760
#define IIM (1.0/IM)


void seed_lcg(unsigned long seed)
{
   iseed_lcg=seed;
}

unsigned long rand_lcg_int(void)
{
    iseed_lcg = ((iseed_lcg*IA) + IC) % IM;
    return iseed_lcg;
}
double rand_lcg(void)
{
    iseed_lcg = ((iseed_lcg*IA) + IC) % IM;
    return iseed_lcg*IIM;
}

//Park-Miller starts here
static  long iseed_pm = 7;
#define JA 16807
#define JM 2147483647
#define AM (1.0/JM)
#define JQ 127773
#define JR 2836
#define MASK 123459876

void seed_pm( long seed)
{
  iseed_pm=seed;
}

double rand_pm(void)
{
  long k;
  int ans;

  iseed_pm ^= MASK;
  k=(iseed_pm)/JQ;
  iseed_pm=JA*(iseed_pm-k*JQ)-JR*k;
  if (iseed_pm < 0) iseed_pm += JM;
  ans=iseed_pm;
  iseed_pm ^= MASK;
  return ans*AM;
}


//Mersenne twister starts here
#define NN 312
#define MM 156
#define MATRIX_A 0xB5026F5AA96619E9ULL
#define UM 0xFFFFFFFF80000000ULL /* Most significant 33 bits */
#define LM 0x7FFFFFFFULL /* Least significant 31 bits */

/* The array for the state vector */
static unsigned long long mt[NN];
/* mti==NN+1 means mt[NN] is not initialized */
static int mti=NN+1;

/* initializes mt[NN] with a seed */
void init_genrand64(unsigned long long seed)
{
    mt[0] = seed;
    for (mti=1; mti<NN; mti++)
        mt[mti] =  (6364136223846793005ULL * (mt[mti-1] ^ (mt[mti-1] >> 62)) + mti);
}
/* generates a random number on [0, 2^64-1]-interval */
unsigned long long genrand64_int64(void)
{
    int i;
    unsigned long long x;
    static unsigned long long mag01[2]={0ULL, MATRIX_A};

    if (mti >= NN) { /* generate NN words at one time */

        /* if init_genrand64() has not been called, */
        /* a default initial seed is used     */
        if (mti == NN+1)
            init_genrand64(5489ULL);

        for (i=0;i<NN-MM;i++) {
            x = (mt[i]&UM)|(mt[i+1]&LM);
            mt[i] = mt[i+MM] ^ (x>>1) ^ mag01[(int)(x&1ULL)];
        }
        for (;i<NN-1;i++) {
            x = (mt[i]&UM)|(mt[i+1]&LM);
            mt[i] = mt[i+(MM-NN)] ^ (x>>1) ^ mag01[(int)(x&1ULL)];
        }
        x = (mt[NN-1]&UM)|(mt[0]&LM);
        mt[NN-1] = mt[MM-1] ^ (x>>1) ^ mag01[(int)(x&1ULL)];

        mti = 0;
    }

    x = mt[mti++];

    x ^= (x >> 29) & 0x5555555555555555ULL;
    x ^= (x << 17) & 0x71D67FFFEDA60000ULL;
    x ^= (x << 37) & 0xFFF7EEE000000000ULL;
    x ^= (x >> 43);

    return x;
}
/* generates a random number on (0,1)-real-interval */
double genrand64_real3(void)
{
    return ((genrand64_int64() >> 12) + 0.5) * (1.0/4503599627370496.0);
}

