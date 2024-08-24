#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lengthOfString(const char strng[]);
char joinTwoStrings(char string_2[],char string_3[]);
bool compareTwoStrings(char string_5[],char string_6[]);

int main()
{
    char string_1[1000];
    char string_4[1000];
    printf("Please enter first string\n");
    scanf("%s", string_1);
    printf("Please enter second string \n");
    scanf("%s", string_4);
    if(compareTwoStrings(string_1,string_4)==1){
        printf("\nThey are equal");
    }
    else if(compareTwoStrings(string_1,string_4)==0){
        printf("\nThey are not equal");
    }
    printf("\n\nLength of first string is %d", lengthOfString(string_1));
    joinTwoStrings(string_1,string_4);
    printf("\n\nThe concatenation of the first and second string is: %s\n", string_1 );
    return 0;
}

int lengthOfString(const char strng[])
{
    int i,result;
    for(i=0,result=0;strng[i]!='\0';i++){
        result=i+1;
    }
    return result;
}
char joinTwoStrings(char string_2[],char string_3[])
{
    char resultString[1000];
    int k,i,j;
    for(j=0,i=0;string_2[i]!='\0';i++,j++)
    {
        resultString[j]=string_2[i];
    }
    for(k=0,j=i;string_3[k]!='\0';k++,j++){
        resultString[j]=string_3[k];
    }
    resultString[j]='\0';
    for(i=0;resultString[i]!='\0';i++){
        string_2[i]=resultString[i];
    }
    string_2[i]='\0';
    return '1';
}
bool compareTwoStrings(char string_5[],char string_6[])
{
    int i,j,finalValue;
    for(i=0,j=0;string_5[i]!='\0' || string_6[j]!='\0';i++,j++){
        if(string_5[i]!=string_6[j]){
                finalValue=0;
        }
        else if(string_5[i]==string_6[j]){
            finalValue=1;
        }
    }
    return finalValue;
}
