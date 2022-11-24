#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
# define MAX 100
 
int stack[MAX];
char postfix[MAX];
int top=-1;

void push(int);
int pop();
int post_eval();

int main()
{
    int result;
    printf("Enter the postfix expression:");
    gets(postfix);

    result = post_eval();
    printf("%d",result);
    return 0;
}


int post_eval()
{
    int i,a,b;
    for(i=0; i<strlen(postfix); i++)
    {

        if(postfix[i]>= '0' && postfix[i]<= '9')
            push(postfix[i]-'0');

        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
                case '+':
                    push(b+a); break;
                case '-':
                    push(b-a); break;
                case '*':
                    push(b*a); break;
                case '/':
                    push(b/a); break;
                case '^':
                    push(pow(b,a)); break;

            }

        }
    }
    return pop();
}
 
 

void push(int c)
{
    if(top == MAX - 1)
    {

        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

int pop()
{
    int c;
    if(top == -1)
    {   
        printf("Stack underflow");
        exit(1);
    }
    
    c=stack[top];  
    top = top - 1;
    return c;
}
