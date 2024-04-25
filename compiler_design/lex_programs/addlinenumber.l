%{
FILE* yyin;
char* str=NULL;
int lineno=0;
%}


%%
.* {str = malloc(yyleng+1);strncpy(str,yytext,yyleng);str[yyleng]='\0';}
\n {printf("%d: %s\n",++lineno,str); free(str);}
%%

int yywrap(){return 1;}

int main()
{
    yyin = fopen("addlinenumber.txt","r");
    yylex();
    fclose(yyin);
    return 0;
}