#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#define K 10
int main(int argc, char ** argv){
    if(argc!=2) {
        printf("Command in format: primeTest <number>");
        exit(0);
    }
    int p = atoi(argv[1]);
    if(p==0) {
        printf("0 is not prime or composit");
    }
    printf("Testing %d (p) if prime", p);

    //Init exponent and mod, and isPrime
    mpz_t out, a, modP;
    int to_pMinus = p-1;
    mpz_init_set_ui(modP, p);
    bool isPrime = true;
    unsigned long t = 1;
    //Will be changed in our loop
    mpz_init(a);
    mpz_init(out);

    //Init random num gen
    srand(time(NULL));

    //test for k times
    for(int i=0; i<K; i++) {
        // Generate a = {random num in 1 to p-1}
        mpz_init_set_ui(a, 1+rand()%(p-1));
        mpz_powm_ui(out, a, to_pMinus, modP);
        printf("\nCase %d\t\t",i+1);
        gmp_printf("a: %Zd\t\t", a);
        gmp_printf("a^(p-1)= %Zd",out);
        if(mpz_cmp_ui(out,t)!=0) {
            isPrime = false;
        }
    }
    printf("\nThe number is %s",isPrime ? "prime" : "composite");
    mpz_clear(out);
    mpz_clear(a);
    mpz_clear(modP);

    printf("\n");
    return true;
}