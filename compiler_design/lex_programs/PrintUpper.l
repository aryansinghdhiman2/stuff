%%
[A-Z]+ {ECHO; printf("\n");}
.|\n                      ;
%%

int yywrap(){return 0;}

int main()
{
    yylex();
    return 0;
}