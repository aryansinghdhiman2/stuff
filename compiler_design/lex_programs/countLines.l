%{
    int lineno = 1;
%}

line .*\n

%%
{line} {printf("%5d %s",lineno++,yytext);}
%%

int yywrap(){return 0;}

int main()
{
    printf("Enter Input: \n");
    yylex();
    return 0;
}