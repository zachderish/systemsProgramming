#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// using trial division
int main (int argc, char *argv[]){
    //store user input
    int num = atoi(argv[1]);
    //create array to store primes
    int* primes = (int*)calloc(num, sizeof(int));
    //initialize factor
    int factor = 2;
    //keep track of how many prime numbers
    int numPrimes = 0;
    //iterate through possible prime factors
    while(num > 1){
        //if factor, then divide
        if(num%factor == 0){
            num = num/factor;
            primes[numPrimes] = factor;
            numPrimes++;
        }
        // iterate to diff factor
        else{
            factor++;
        }
    }

    // print factors
    for(int i = 0; i < numPrimes; i++){
        printf("%d ", primes[i]);
    }
    printf("\n");
    free(primes);
}