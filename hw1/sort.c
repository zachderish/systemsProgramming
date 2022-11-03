#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

char* toLower(char* string){
    for(int i = 0; i < strlen(string); i++){
        
        string[i] = tolower(string[i]);
    }
    return string;
}


int main(int argc, char *argv[]){
    if(argv[1] != NULL){
        int nums[100];
        int count = 0;
        int n = scanf("%d", &nums[count]);
        while(n == 1){
            count++;
            n = scanf("%d", &nums[count]);
        }
        //insertion sort
        for(int i = 1; i < count; i++){
            int num = nums[i];
            int j = i-1;

            while(j >= 0 && nums[j] > num){
                nums[j+1] = nums[j];
                j=j-1;
            }
            nums[j+1] = num;
        }
        for(int i = 0; i < count; i++){
            printf("%d\n", nums[i]);
        }
    }
    else{
        char* strings[100];
        int count = 0;
        strings[count] = malloc(100*sizeof(char));
        int n = scanf("%s", strings[count]);
        while(n == 1){
            count++;
            strings[count] = malloc(100*sizeof(char));
            n = scanf("%s", strings[count]);
        }
        //insertion sort
        for(int i = 1; i < count; i++){
            char* string = strings[i];
            int j = i-1;

            while(j >= 0 && strcasecmp(strings[j],string) > 0){
                strings[j+1] = strings[j];
                j=j-1;
            }
            strings[j+1] = string;
        }
        for(int i = 0; i < count; i++){
            printf("%s\n", strings[i]);
            free(strings[i]);
        }
    }
}