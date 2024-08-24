%{
    FILE* yyin;
    FILE* out = NULL;
%}



%%
.*?\/\/(.*) {;}
.* {fprintf(out,"%s",yytext);}
\n {fprintf(out,"\n");}
%%

int yywrap(){return 1;}

int main()
{
    yyin = fopen("removeComments.c","r+");
    out = fopen("removeCommentsOut.c","w");
    yylex();
    fclose(yyin);
    fclose(out);
    return 0;
}
