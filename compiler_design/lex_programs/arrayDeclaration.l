%{
FILE* yyin;
FILE* out = NULL;
%}

datatypes int|char|short|unsigned|long|float|double
varname [A-Za-z_][A-Za-z_0-9]*
array \b?{datatypes}[[:blank:]]*{varname}\[[[:digit:]]\];
decl \b?{varname}[[:blank:]]*{varname}[[:blank:]]*?(,{varname}[[:blank:]]*?)*;
%%
{array} {fprintf(out,"%s\n",yytext);}
{decl} {fprintf(out,"%s\n",yytext);}
.|\n {;}
%%

int yywrap(){return 1;}

int main()
{
    yyin = fopen("arrayDeclaration.c","r");
    out = fopen("arrayDeclarationOut.c","w");
    yylex();
    fclose(yyin);
    fclose(out);
    return 0;
}