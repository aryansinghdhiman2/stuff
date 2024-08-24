%%
[a-z]*[A-Z]*[0-9]{4} {ECHO; printf("\n");}
.|\n                      ;
%%

int yywrap(){return 0;}

int main()
{
    yylex();
    return 0;
}