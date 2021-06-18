#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *input;
int i=0,n;
char lasthandle[6],stack[50],handles[][5]={")E(","E*E","E+E","i","E^E"};
char gram[10][20];
//(E) becomes )E( when pushed to stack

int top=0,l;
char prec[9][9]={

                            /*input*/

            /*stack    +    -   *   /   ^   i   (   )   $  */

            /*  + */  '>', '>','<','<','<','<','<','>','>',

            /*  - */  '>', '>','<','<','<','<','<','>','>',

            /*  * */  '>', '>','>','>','<','<','<','>','>',

            /*  / */  '>', '>','>','>','<','<','<','>','>',

            /*  ^ */  '>', '>','>','>','<','<','<','>','>',

            /*  i */  '>', '>','>','>','>','e','e','>','>',

            /*  ( */  '<', '<','<','<','<','<','<','>','e',

            /*  ) */  '>', '>','>','>','>','e','e','>','>',

            /*  $ */  '<', '<','<','<','<','<','<','<','>',

                };

int getindex(char c)
{
switch(c)
    {
    case '+':return 0;
    case '-':return 1;
    case '*':return 2;
    case '/':return 3;
    case '^':return 4;
    case 'i':return 5;
    case '(':return 6;
    case ')':return 7;
    case '$':return 8;
    }
}

// function f to exit from the loop
// if given condition is not true
void f()
{
	printf("\nNot operator grammar\n");
	exit(0);
}

int shift()
{
stack[++top]=*(input+i++);
stack[top+1]='\0';
}


int reduce()
{
int i,len,found,t;
for(i=0;i<5;i++)//selecting handles
    {
    len=strlen(handles[i]);
    if(stack[top]==handles[i][0]&&top+1>=len)
        {
        found=1;
        for(t=0;t<len;t++)
            {
            if(stack[top-t]!=handles[i][t])
                {
                found=0;
                break;
                }
            }
        if(found==1)
            {
            stack[top-t+1]='E';
            top=top-t+1;
            strcpy(lasthandle,handles[i]);
            stack[top+1]='\0';
            return 1;//successful reduction
            }
        }
   }
return 0;
}



void dispstack()
{
int j;
for(j=0;j<=top;j++)
    printf("%c",stack[j]);

}



void dispinput()
{
int j;
for(j=i;j<l;j++)
    printf("%c",*(input+j));
}

void check_operatorGrammar()
{
    // Here using flag variable set to 0, considers grammar is not operator grammar
    int i, j = 2, flag = 0;
    char c;
    for (i = 0; i < n; i++) {
		c = gram[i][2];

		while (c != '\0') {

			if (gram[i][3] == '+' || gram[i][3] == '-'
				|| gram[i][3] == '*' || gram[i][3] == '/')
				flag = 1;
			else {
				flag = 0;
				f();
			}

			if (c == '$') {
				flag = 0;
				f();
			}
			c = gram[i][++j];
		}
    }
	if (flag == 1)
		printf("\nIs an Operator grammar\n");
}


void main()
{
    int j;
    // taking number of productions from user
    printf("Enter the number of productions: ");
	scanf("%d", &n);
	printf("Enter the production rules(each in a new line)- \n");
    for (int i = 0; i < n; i++)
		scanf("%s", gram[i]);
    check_operatorGrammar();
    input=(char*)malloc(50*sizeof(char));
    printf("\nEnter the string\n");
    scanf("%s",input);
    input=strcat(input,"$");
    l=strlen(input);
    strcpy(stack,"$");
    printf("\nSTACK \tINPUT\t\tACTION");
    while(i<=l)
        {
        shift();
        printf("\n");
        dispstack();
        printf("\t");
        dispinput();
        printf("\t\tShift");
        if(prec[getindex(stack[top])][getindex(input[i])]=='>')
            {
            while(reduce())
                {
                printf("\n");
                dispstack();
                printf("\t");
                dispinput();
                printf("\t\tReduced: E->%s",lasthandle);
                }
            }
        }

    if(strcmp(stack,"$E$")==0)
        printf("\n\nInput String Accepted;");
    else
        printf("\nNot Accepted;");
    }
