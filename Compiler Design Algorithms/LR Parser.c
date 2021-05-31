#include <stdio.h>
#include <ncurses.h>

char stack[30];
int top = -1;

void push(char c)
{
    top++;
    stack[top] = c;
}

char pop()
{
    char c;
    if (top != -1)
    {
        c = stack[top];
        top--;
        return c;
    }
    return 'x';
}

void printstat()
{
    int i;
    printf("\n\t\t\t $");
    for (i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
}

void main()
{
    int i, j, k, l;
    char s1[20], s2[20], ch1, ch2, ch3;
    clrscr();
    printf("\n\n\t\t LR PARSING");
    printf("\n\t\t ENTER THE EXPRESSION");
    scanf("%s", s1);
    l = strlen(s1);
    j = 0;
    printf("\n\t\t $");
    for (i = 0; i < l; i++)
    {
        if (s1[i] == 'i' && s1[i + 1] == 'd')
        {
            s1[i] = ' ';
            s1[i + 1] = 'E';
            printstat();
            printf("id");
            push('E');
            printstat();
        }
        else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/' || s1[i] == 'd')
        {
            push(s1[i]);
            printstat();
        }
    }
    printstat();

    l = strlen(s2);
    while (l)
    {
        ch1 = pop();
        if (ch1 == 'x')
        {
            printf("\n\t\t\t $");
            break;
        }
        if (ch1 == '+' || ch1 == '/' || ch1 == '*' || ch1 == '-')
        {
            ch3 = pop();
            if (ch3 != 'E')
            {
                printf("errror");
                exit();
            }
            else
            {
                push('E');
                printstat();
            }
        }
        ch2 = ch1;
    }
    getch();
}