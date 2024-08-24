#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    int randomNumber = rand()%21;

    int counter,guessedNumber;
            for(counter=5;;counter--)
            {
                if(counter==0){
                    printf("You have run out of tries");
                    break;
                }
            printf("\nNumber of tries left are %d\n", counter);
            printf("Enter a guess between 0 and 20: ");
            scanf("%d", &guessedNumber);
                if(guessedNumber>20 || guessedNumber<0){
                    printf("Please enter a valid number\n");
                    counter++;
                }
                else if(guessedNumber<randomNumber){
                    printf("Sorry %d is wrong,My number is higher than that\n",guessedNumber);
                }
                else if(guessedNumber>randomNumber){
                    printf("Sorry %d is wrong,My number is lower than that\n",guessedNumber);
                }
                else if(guessedNumber==randomNumber) {
                    printf("You have won");
                    break;
             }
            }
    return 0;
}
