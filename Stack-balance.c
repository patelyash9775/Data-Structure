#include<stdio.h>
#include<string.h>
#define max 10

struct STACK
{
    int Top;
    char ele[max];
};

typedef struct STACK stack;
stack s;

int isFull()
{
    if(s.Top==max-1)
        {   printf("stack is in overflow");
            return(1);
        }
    return(0);
}

int isEmpty()
{
    if(s.Top==-1)
    {
        printf("stack is in underflow");
        return(1);
    }
    return(0);
}
void push(char new_ele)
{
    if(!isFull())
    {
        s.ele[++s.Top]=new_ele;
    }
}

char pop()
{
    if(!isEmpty())
    {
        return(s.ele[s.Top--]);
    }
}

main()
{
    char a[max];
    s.Top=-1;
    printf("Enter a string : ");
    gets(a);
    int i=0;
    while(a[i]!='\0')
    {
        if(a[i]=='(' || a[i]=='{' || a[i]=='[')
            push(a[i]);
        else if(a[i]==')')
        {
            if(pop()!='(')
                break;
        }
        else if(a[i]=='}')
        {
            if(pop()!='{')
                break;
        }
        else if(a[i]==']')
        {
             if(pop()!='[')
                break;
        }

        i++;
    }
    if(i==strlen(a))
    {
        printf("\nExpression is balanced");
    }
    else
    {
        printf("\nExpression is not balanced");

    }
}
