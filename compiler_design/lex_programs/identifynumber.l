%{
FILE* yyin;
%}


%%
[0-9]+ {printf("%s\t",yytext);}
. {}
\n {printf("\n");}
%%

int yywrap(){return 1;}

int main()
{
    yyin = fopen("identifynumber.txt","r");
    yylex();
    fclose(yyin);
    return 0;
}