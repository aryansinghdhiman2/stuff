%{
FILE* yyin;
int count = 0;
%}


%%
[a-zA-Z]{2}[0-9]{3}uiet {count++;}
.|\n {;}
%%

int yywrap(){return 1;}

int main()
{
    yyin = fopen("assign.txt","r");
    yylex();
    fclose(yyin);
    printf("Matches %d",&count);
    return 0;
}