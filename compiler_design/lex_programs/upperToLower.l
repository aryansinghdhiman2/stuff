%{
#include <ctype.h>
char* convertStringToLower(char* s)
{
    for(int i=0; i<yyleng;i++ )
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

%}


%%
[A-Za-z]+ {printf("%s",convertStringToLower(yytext));}
.\n ;
%%

int yywrap(){return 0;}

int main()
{
    printf("Enter Input: \n");
    yylex();
    return 0;
}