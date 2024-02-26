%{
    int words = 0;
%}


%%
\s ;
[^\s | ^\n]+ {words++;};
\n {printf("\nNumber of Words in Line: %d\n",words);words=0;};
%%

int yywrap(){return 0;}

int main()
{
    printf("Enter Input: \n");
    yylex();
    return 0;
}