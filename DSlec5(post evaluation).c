#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max 20

struct STACK
{
    int ele[max];
    int Top;
};

typedef struct STACK stack;
stack s;

int is_Full()
{
    if(s.Top==max-1)
    {

        return(1);
    }
    return(0);
}

int is_Empty()
{
    if(s.Top==-1)
    {

        return(1);
    }
    return(0);
}

void push(int new_ele)
{
    if(!is_Full())
    {
        s.ele[++s.Top]=new_ele;
    }
}

int pop()
{
    if(!is_Empty())
    {
        return(s.ele[s.Top--]);
    }
}

int evaluation(int op1,int op2,char x)
{
    if(x=='+')
         return(op1+op2);
    else if(x=='-')
         return(op1-op2);
    else if(x=='*')
          return(op1*op2);
    else if(x=='/')
          return(op1/op2);
    else if(x=='$')
        return(pow(op1,op2));
}

int main()
{
    char ex[20];
    s.Top=-1;
    int i=0;
    int op1,op2,ans;
    printf("Enter a postfix ");
    gets(ex);
    while(ex[i]!='\0')
    {
        if(isdigit(ex[i]))
        {
            push(ex[i]-48);
        }
        else
        {
            op2=pop();
            op1=pop();
            ans=evaluation(op1,op2,ex[i]);
            push(ans);
        }
        i++;
    }
    printf("Ans is %d : ",pop());
    return(0);
}
