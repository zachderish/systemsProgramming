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
    if(strcmp(argv[1], "-i") == 0){
        char s[100];
        int n = scanf("%[^\n]%*c", s);
        char* old = (char*)malloc(100*sizeof(char));
        strcpy(old, s);
        while (n == 1) {
            if(strstr(toLower(s), toLower(argv[2])) != NULL){
                printf("%s\n", old);
            }
            n = scanf("%[^\n]%*c", s);
            strcpy(old, s);
        }
        free(old);
    }
    else{
        char s[100];
        int n = scanf("%[^\n]%*c", s);
        while (n == 1) {
            if(strstr(s, argv[1]) != NULL){
                printf("%s\n", s);
            }
            n = scanf("%[^\n]%*c", s);
        }
    }
}