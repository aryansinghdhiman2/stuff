// const array<string,34> keywords = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
// const array<char,9> delimiters = {',',';','{','}','[',']','(',')',' '};
// const array<char,12> operators = {'+','-','*','/','%','=','<','>','!','&','|','^'};
// const array<string,19> combined_operators = {"++","--","+=","-=","*=","/=","%=","&=","|=","^=",">>","<<","==","!=","<=",">=","&&","||"};
// const array<string,13> directives = {"#include", "#pragma", "#define", "#error", "#warning", "#undef", "#if", "#else", "#elif", "#endif", "#ifdef", "#ifndef", "#line"};

%{
#include <ctype.h>
#include <stdio.h>
// FILE* yyin;
%}

keywords auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|inline|int|long|register|restrict|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
delimiters ,|;|\{|\}|\[|\]|\(|\)|[[:blank:]]|
operators = +|-|*|\/|%|=|<|>|!|&|\||\^
combined_operators "++"|"--"|"+="|"-="|"*="|"/="|"%="|"&="|"|="|"^="|">>"|"<<"|"=="|"!="|"<="|">="|"&&"|"||"
directives = "#include"|"#pragma"|"#define"|"#error"|"#warning"|"#undef"|"#if"|"#else"|"#elif"|"#endif", "#ifdef", "#ifndef", "#line"
%%
%%

int yywrap(){return 0;}

int main()
{
    // yyin = fopen("upperToLower.txt","r");
    yylex();
    // fclose(yyin);
    return 0;
}