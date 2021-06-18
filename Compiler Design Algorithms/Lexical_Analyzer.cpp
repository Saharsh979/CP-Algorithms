#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Returns 'true' if the character is a DELIMITER
bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
        ch == '%' || ch == '!' || ch == '&' || ch == '|' ||
        ch == '\n')
        return (true);
    return (false);
}

//Returns 'true' if the character can be continuation of a single operator
bool isOperator_secondHalf(char ch)
{
    if (ch == '=' || ch == '&' ||
        ch == '|' || ch == '+' || ch == '-')
        return (true);
    return (false);
}

//Returns 'true' if the character is a punctuator
bool isPunctuator(char ch)
{
    if (ch == '{' || ch == '}' ||
        ch == ',' || ch == ';')
        return (true);
    return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '%')
        return (true);
    return (false);
}

//Returns 'true' if the character is the assignment operator
bool isAssignment(char ch)
{
    if (ch == '=')
        return (true);
    return (false);
}

//Returns 'true' if character array is a valid logical operator
bool isLogical_operator(char *arr)
{
    if (!strcmp(arr, "&&") || !strcmp(arr, "||") || !strcmp(arr, "!"))
        return (true);
    return (false);
}

//Returns 'true' if character array is a valid relational operator
bool isRelational_operator(char *arr)
{
    if (!strcmp(arr, ">") || !strcmp(arr, ">=") ||
        !strcmp(arr, "<") || !strcmp(arr, "<=") ||
        !strcmp(arr, "==") || !strcmp(arr, "!="))
        return (true);
    return (false);
}

//Return 'true' if the character array is an increment or decrement operator
bool isOperator2(char *arr)
{
    if (!strcmp(arr, "++") || !strcmp(arr, "--"))
        return (true);
    return (false);
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool validIdentifier(char *str)
{
    int val = (int)str[0];
    if (val >= 48 && val <= 57 || isDelimiter(str[0]) == true)
        return (false);
    if ((val >= 65 && val <= 90) || (val >= 97 && val <= 122))
    {
        return (true);
    }
    return (false);
}

// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") || !strcmp(str, "for") ||
        !strcmp(str, "continue") || !strcmp(str, "case") ||
        !strcmp(str, "switch") || !strcmp(str, "goto") ||
        !strcmp(str, "else if"))
        return (true);
    return (false);
}

// Returns 'true' if the string is an INTEGER.
bool isInteger(char *str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(char *str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

// Extracts the SUBSTRING.
char *subString(char *str, int left, int right)
{
    int i;
    char *subStr = (char *)malloc(
        sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

// Parsing the input STRING.
void parse(char *str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right)
    {
        if (isDelimiter(str[right]) == false)
            right++;

        if (isDelimiter(str[right]) == true && left == right)
        {
            char ch = str[right];
            int temp = right + 1;
            char arr[] = "";
            arr[0] = ch;
            arr[1] = '\0';
            if (isPunctuator(ch) == true)
                printf("'%c' -> PUNCTUATOR\n", str[right]);
            else if (isOperator_secondHalf(str[temp]) == true)
            {
                arr[1] = str[temp];
                arr[2] = '\0';
                if (isLogical_operator(arr) == true)
                {
                    printf("'%s' -> LOGICAL OPERATOR\n", arr);
                    right = temp;
                }
                else if (isRelational_operator(arr) == true)
                {
                    printf("'%s' -> RELATIONAL OPERATOR\n", arr);
                    right = temp;
                }
                else if (isOperator2(arr) == true)
                {
                    printf("'%s' -> INCREMENT/DECREMENT OPERATOR\n", arr);
                    right = temp;
                }
            }
            if (right != temp)
            {
                arr[1] = '\0';
                if (isOperator(ch) == true)
                    printf("'%c' -> ARITHMETIC OPERATOR\n", str[right]);
                else if (isAssignment(ch) == true)
                    printf("'%c' -> ASSIGNMENT OPERATOR\n", str[right]);
                else if (isLogical_operator(arr) == true)
                    printf("'%c' -> LOGICAL OPERATOR\n", str[right]);
                else if (isRelational_operator(arr) == true)
                    printf("'%c' -> RELATIONAL OPERATOR\n", str[right]);
                else if (ch == '&' || ch == '|')
                    printf("'%c' -> UNRECOGNIZED TOKEN\n", str[right]);
            }
            right++;
            left = right;
        }
        else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right))
        {
            char *subStr = subString(str, left, right - 1);

            if (isKeyword(subStr) == true)
                printf("'%s' -> KEYWORD\n", subStr);

            else if (isInteger(subStr) == true)
                printf("'%s' -> INTEGER\n", subStr);

            else if (isRealNumber(subStr) == true)
                printf("'%s' -> REAL NUMBER\n", subStr);

            else if (validIdentifier(subStr) == true && isDelimiter(str[right - 1]) == false)
                printf("'%s' -> IDENTIFIER\n", subStr);

            else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false)
                printf("'%s' -> INVALID IDENTIFIER\n", subStr);
            left = right;
        }
    }
    return;
}

// DRIVER FUNCTION
int main()
{
    // maximum length of string is 100 here
    printf("\tSYMBOL TABLE\n");
    printf("\nTOKEN \t\tCOMMENT\n");
    //sample
    char str[100] = "void main()\n{  int a,b,c,d,a2,3b;\n     int a = b ++ (c*d);\n    ad >= d;\n}";

    parse(str); // calling the parse function
    return (0);
}
