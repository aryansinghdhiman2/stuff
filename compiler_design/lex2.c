#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a character is a delimiter
bool isDelimiter(char ch)
{
    // Use single quotes for characters, not double quotes
    if (ch == ' ' || ch == ',' || ch == ';' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' || ch == '=' || ch == '&' || ch == '#' || ch == '%' ||
        ch == '"' || ch == '\'')
        return (true);
    return (false);
}

// Function to check if a character is a special symbol
bool isSpecial(char ch)
{
    if (ch == ',' || ch == ';' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '"' || ch == '\'' || ch == '#')
        return (true);
    return (false);
}

// Function to check if a character is an operator
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=' || ch == '&' || ch == '%')
        return (true);
    return (false);
}

// Function to check if a string is a valid identifier
bool validIdentifier(char *str)
{
    // Use single quotes for characters, not double quotes
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}

// Function to check if a string is a keyword
bool isKeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
        !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "main") ||
        !strcmp(str, "include") || !strcmp(str, "stdio.h") || !strcmp(str, "double") ||
        !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") ||
        !strcmp(str, "void") || !strcmp(str, "scanf") || !strcmp(str, "printf") ||
        !strcmp(str, "&var1") || !strcmp(str, "&var2") || !strcmp(str, "%d") ||
        !strcmp(str, "%c"))
        return (true);
    return (false);
}

// Function to check if a string is an integer
bool isInteger(char *str)
{
    int i, len = strlen(str);
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' &&
            str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' &&
            str[i] != '8' && str[i] != '9')
            return (false);
    }
    return (true);
}

// Function to check if a string is a combined operator
bool isCombined(const char *s)
{
    const char *operators[] = {
        "==", "!=", ">", "<", ">=", "<=",
        "=", "+=", "-=", "*=", "/=", "%=",
        "&=", "|=", "^=", "<<", ">>", "++", "--"};

    size_t numOperators = sizeof(operators) / sizeof(operators[0]);

    for (size_t i = 0; i < numOperators; ++i)
    {
        if (strcmp(operators[i], s) == 0)
        {
            return true;
        }
    }

    return false;
}

// Function to extract a substring
char *subString(char *str, int left, int right)
{
    int i;
    char *subStr = (char *)malloc(sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

// Function to perform lexical analysis
void func(char *str)
{
    int lineno = 1;
    int left = 0, right = 0;
    int len = strlen(str);

    // Use append mode "a" to avoid overwriting the file content
    FILE *fout = fopen("output.txt", "a");

    while (right <= len && left <= right)
    {
        if (str[right] == '\n')
        {
            lineno++;
        }
        if (isDelimiter(str[right]) == false)
            right++;

        if (isDelimiter(str[right]) == true && left == right)
        {
            if (isOperator(str[right]) == true)
            {
                char combinedOperator[3];
                strncpy(combinedOperator, &str[right], 2);
                combinedOperator[2] = '\0';

                if (isCombined(combinedOperator))
                    fprintf(fout, "%s \t\tCombined Operator\t %d\n", combinedOperator, lineno);
                else
                    fprintf(fout, "%c \t\tOperator\t %d\n", str[right], lineno);
            }
            if (isSpecial(str[right]) == true)
                fprintf(fout, "%c \t\tSpecial Symbol\t %d\n", str[right], lineno);
            right++;
            left = right;
        }
        else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right))
        {
            char *subStr = subString(str, left, right - 1);
            if (isKeyword(subStr) == true)
                fprintf(fout, "%s \t\tKeyword\t %d\n", subStr, lineno);
            else if (isInteger(subStr) == true)
                fprintf(fout, "%s \t\tConstant\t %d\n", subStr, lineno);
            else if (isSpecial(subStr[0]) == true)
                fprintf(fout, "%s \t\tSpecial Symbol\t %d\n", subStr, lineno);
            else if (validIdentifier(subStr) == true && isDelimiter(str[right - 1]) == false && subStr[0] != '\n' && str[right - 1] != '\n')
                fprintf(fout, "%s \t\tIdentifier\t %d\n", subStr, lineno);
            else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false)
                fprintf(fout, "%s\t\tidentifier\t %d\n", subStr, lineno);

            left = right;
        }
        else
        {
            right++;
        }
    }

    fclose(fout);
    return;
}

int main()
{
    // Initialize the string to an empty string
    char str[1000] = "";
    FILE *fp = fopen("t1.c", "r");
    if (fp == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    do
    {
        char ch = fgetc(fp);
        if (feof(fp))
            break;
        strncat(str, &ch, 1);
    } while (1);

    func(str);
    fclose(fp);
    return 0;
}