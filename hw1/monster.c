#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// print the game board
int printBoard(int boardX, int boardY, int plrX, int plrY, int goalX, int goalY, int monX, int monY){
    for(int i = boardY-1; i >=0 ; i--){
        for(int j = 0; j < boardY; j++){
            if(j == plrX && i == plrY){
                printf("%c ", 'P');
            }
            else if(j == goalX && i == goalY){
                printf("%c ", 'G');
            }
            else if(j == monX && i == monY){
                printf("%c ", 'M');
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    return 1;
}

//move the player based on user input
void updatePlayer(int plrX, int plrY, int* plr, char* s){
    if(*s == 'N'){
        plr[1] = plr[1] + 1;
    }
    else if(*s == 'S'){
        plr[1] = plr[1] - 1;
    }
    else if(*s == 'W'){
        plr[0] = plr[0] - 1;
    }
    else if(*s == 'E'){
        plr[0] = plr[0]+1;
    }
    //printf("%d %d %s\n", plr[0], plr[1], s);
}

// movement of monster based on lowest of horzinontal or vertical distance to player
char updateMon(int plrX, int plrY, int monX, int monY, int* mon){
    int xDiff = abs(plrX-monX);
    int yDiff = abs(plrY-monY);
    if(xDiff > yDiff){
        if(plrX > monX){
            mon[0] = mon[0]+1;
            char message = 'E';
            return message;
        }
        else if(plrX < monX){
            mon[0] = mon[0]-1;
            char message = 'W';
            return message;
        }
    }
    else if(xDiff < yDiff){
        if(plrY > monY){
            mon[1] = mon[1]+1;
            char message = 'N';
            return message;
        }
        else if(plrY < monY){
            mon[1] = mon[1]-1;
            char message = 'S';
            return message;
        }
    }
    else{
        srand(time(NULL));
        int r = rand()%2;
        //printf("%d\n", r);
        if(r == 0){
            if(plrX > monX){
                mon[0] = mon[0]+1;
                char message = 'E';
                return message;
            }
            else if(plrX < monX){
                mon[0] = mon[0]-1;
                char message = 'W';
                return message;
            }
        }
        else{
            if(plrY > monY){
                mon[1] = mon[1]+1;
                char message = 'N';
                return message;
            }
            else if(plrY < monY){
                mon[1] = mon[1]-1;
                char message = 'S';
                return message;
            }
        }
    }
}

// check various game conditions (hitting monster, hitting goal, out of bounds)
void checkBoard(int boardX, int boardY, int plrX, int plrY, int goalX, int goalY, int monX, int monY, int* plr, char* s){
    // monster gets player
    if(plrX == monX && plrY == monY){
        printf("monster wins!\n");
        exit(0);
    }
    else if(plrX == goalX && plrY == goalY){
        printf("player wins!\n");
        exit(0);
    }
    //printBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
}

int validMove(int boardX, int boardY, int plrX, int plrY, char* s){
    if(*s=='N' && plrY == boardY-1){
        return 0;
    }
    else if(*s=='S' && plrY == 0){
        return 0;
    }
    else if(*s=='E' && plrX == boardX-1){
        return 0;
    }
    else if(*s=='W' && plrX == 0){
        return 0;
    }
    else{
        return 1;
    }
}

int validMonMove(char move, int monX, int monY, int goalX, int goalY){
    if(move=='N' && monX==goalX && monY+1==goalY){
        return 0;
    }
    else if(move=='S' && monX==goalX && monY-1==goalY){
        return 0;
    }
    else if(move=='W' && monX-1==goalX && monY==goalY){
        return 0;
    }
    else if(move=='E' && monX+1==goalX && monY==goalY){
        return 0;
    }
    else{
        return 1;
    }

}

int main(int argc, char *argv[]){
    // get starting board inputs
    int boardX = atoi(argv[1]);
    int boardY = atoi(argv[2]);
    int plrX = atoi(argv[3]);
    int plrY = atoi(argv[4]);
    int goalX = atoi(argv[5]);
    int goalY = atoi(argv[6]);
    int monX = atoi(argv[7]);
    int monY = atoi(argv[8]);
    printBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
    char s[100];
    // read user direction for player
    int n = scanf("%s", s);
    //create player array
    int plr[2];
    //create monster array
    int mon[2];

    if(validMove(boardX, boardY, plrX, plrY, s) == 1){
        plr[0] = atoi(argv[3]);
        plr[1] = atoi(argv[4]);
        //update player
        updatePlayer(plrX, plrY, plr, s);
        plrX = plr[0];
        plrY = plr[1];
        checkBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY, plr, s);

        mon[0] = monX;
        mon[1] = monY;
        //update monster
        char move = updateMon(plrX, plrY, monX, monY, mon);
        if(validMonMove(move, monX, monY, goalX, goalY) == 1){
            monX = mon[0];
            monY = mon[1];
            char message[100] = "monster moves ";
            strncat(message, &move, 1);
            printf("%s\n", message);
        }

        checkBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY, plr, s);
        printBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
    }
    else{
        printf("invalid move\n");
        printBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
    }

    while(n == 1){
        //read user direction for player
        n = scanf("%s", s);
        if(validMove(boardX, boardY, plrX, plrY, s) == 1){
            plr[0] = plrX;
            plr[1] = plrY;
            //update player
            updatePlayer(plrX, plrY, plr, s);
            plrX = plr[0];
            plrY = plr[1];
            checkBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY, plr, s);
    
            mon[0] = monX;
            mon[1] = monY;
            //update monster
            char move = updateMon(plrX, plrY, monX, monY, mon);
            //ensure monster is not going through goal
            if(validMonMove(move, monX, monY, goalX, goalY) == 1){
                monX = mon[0];
                monY = mon[1];
                char message[100] = "monster moves ";
                strncat(message, &move, 1);
                printf("%s\n", message);
            }

            checkBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY, plr, s);
            printBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
        }
        else{
            printf("invalid move\n");
            printBoard(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
        }
    }
}