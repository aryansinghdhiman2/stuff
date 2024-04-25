%{
#include <ctype.h>
#include <stdio.h>
char* convertStringToLower(char* s)
{
    for(int i=0; i<yyleng;i++ )
    {
        s[i] = tolower(s[i]);
    }
    return s;
}
FILE* yyin;
%}


%%
[A-Za-z]+ {printf("%s",convertStringToLower(yytext));}
.\n ;
%%

int yywrap(){return 1;}

int main()
{
    yyin = fopen("upperToLower.txt","r");
    yylex();
    fclose(yyin);
    return 0;
}