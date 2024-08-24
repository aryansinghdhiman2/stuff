#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkForWin();
int markBoard(int i);
void drawBoard();

char grid[10]={'0','1','2','3','4','5','6','7','8','9'};
bool player=0;

int main()
{
    int k;
    int counter;
    for(counter=1;counter<=9;counter++){
            drawBoard();
        if(player==0){
            printf("It is Player 1's turn\n");
        }
        if(player==1){
            printf("It is Player 2's turn\n");
        }
        printf("Please enter the place where you want to mark  ");
        scanf("%d", &k);
        markBoard(k);

        if(checkForWin()==1){
            system("clear");
            drawBoard();
            printf("Player %d has won", player+1);
            break;
        }
        else{
            system("clear");
        }
        if(player==0){
                player=1;
        }
        else if(player==1){
            player=0;
        }

    }
    if(counter>9){
        printf("You have run out of moves\n");
    }
    else {
        printf("\nEnter any number to exit: ");
        scanf("%d", &k);
    }
    return 0;
}

void drawBoard()
{
    printf(" %c   %c   %c\n %c   %c   %c\n %c   %c   %c\n",grid[1],grid[2],grid[3],grid[4],grid[5],grid[6],grid[7],grid[8],grid[9]);
}
bool checkForWin()
{
    if(grid[1]==grid[2] && grid[3]==grid[2]){
        return 1;
    }
    if(grid[4]==grid[5] && grid[5]==grid[6]){
        return 1;
    }
    if(grid[7]==grid[8] && grid[8]==grid[9]){
        return 1;
    }


    if(grid[1]==grid[5] && grid[5]==grid[9]){
        return 1;
    }
    if(grid[7]==grid[5] && grid[3]==grid[5]){
        return 1;
    }



    if(grid[1]==grid[4] && grid[4]==grid[7]){
        return 1;
    }
    if(grid[2]==grid[5] && grid[5]==grid[8]){
        return 1;
    }
    if(grid[3]==grid[6] && grid[6]==grid[9]){
        return 1;
    }
    return 0;
}

int markBoard(int i)
{
    for(;;)
    {
        if(i<1 || i==0){
            printf("Invalid Move\n");
			scanf("%d", &i);
        }
        if(i>9){
            printf("Invalid Move\n");
			scanf("%d", &i);
        }
        if(grid[i]=='X' || grid[i]=='O'){
            printf("Invalid Move\n");
			scanf("%d", &i);
        }
        else if(player==0){
            grid[i]='X';
            break;
        }
        else if(player==1){
            grid[i]='O';
            break;
        }
    }
    return 0;
}
