%{
// FILE* yyin;
int counteh = 0;
int count = 0;
%}


%%
\b?[a-zA-z]*eh {printf("EH %d\n",++counteh);}
\b?[a-zA-z]* {printf("NOEH %d\n",++count);}
.|\n {;}
%%

int yywrap(){return 0;}

int main()
{
    // yyin = fopen("assign.txt","r");
    yylex();
    // fclose(yyin);
    // printf("Matches %d",&counteh);
    return 0;
}