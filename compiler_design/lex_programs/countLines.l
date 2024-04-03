FILE* yyin;
%{
    int lineno = 1;
%}

line .*\n

%%
{line} {printf("%5d %s",lineno++,yytext);}
%%

int yywrap(){return 1;}

int main()
{
    yyin = fopen("countlines.l","r+");
    yylex();
    fclose(yyin);
    return 0;
}
