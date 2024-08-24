%{
    // FILE* yyin;
    // FILE* out = NULL;
    // char* str = NULL;
    int lineno=0;
%}



%%
.*?\/\/.* {printf("Comment :%s",yytext);}
.*\n {lineno++;printf("%d: %s",lineno,yytext);}

%%

int yywrap(){return 0;}

int main()
{
    // yyin = fopen("removeComments.c","r+");
    // out = fopen("remove2Out.c","w");
    yylex();
    // fclose(yyin);
    // fclose(out);
    return 0;
}
