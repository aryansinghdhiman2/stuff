%%
[a-zA-Z]+ printf("%s is a word\n",yytext);
.\n printf("%s is not a word\n",yytext);
%%

int yywrap(){return 0;}

int main()
{
    printf("Enter Input: \n");
    yylex();
    return 0;
}