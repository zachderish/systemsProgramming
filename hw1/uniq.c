#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[]){
    char* words[100];
    int count = 0;
    words[count] = malloc(100*sizeof(char));
    int n = scanf("%s", words[count]);
    // get strings from user input
    while(n==1){
        count++;
        words[count] = malloc(100*sizeof(char));
        n = scanf("%s", words[count]);
    }

    // print results, plus find num of repeats
    int counter = 1;
    for(int i = 1; i <= count; i++){
        if(strcmp(words[i], words[i-1]) == 0){
            counter++;
        }
        else{
            printf("%d %s\n", counter, words[i-1]);
            counter = 1;
        }
    }
}