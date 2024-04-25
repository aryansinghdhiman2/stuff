%{
#include<stdio.h>
#include<string.h>
#define ECHO fwrite(yytext, yyleng, 1, yyout);
int count = 0;
%}

%%
[a-zA-Z]{11,} {printf("%.10s" ,yytext); count++;}
[a-zA-Z]+ {ECHO;}
. {ECHO;}
%%
int yywrap(void){
}
int main()
{
// The function that starts the analysis
printf("Enter your input \n");
yylex();
printf("Number of Words that are truncated: %d", count);
return 0;
}