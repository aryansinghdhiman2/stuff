%{
FILE* yyin;
int words = 0;
%}


%%
a. {++words;}
. {}
\n {++words;}
%%

int yywrap(){return 1;}

int main()
{
    yyin = fopen("countlinesorwordswitha.txt","r");
    yylex();
    fclose(yyin);
    printf("Number of newlines and words starting with a are: %d");
    return 0;
}