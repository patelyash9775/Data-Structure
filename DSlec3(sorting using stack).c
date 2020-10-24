#include<stdio.h>
#define max 5

struct STACK
{
    int Top;
    int ele[max];
};

typedef struct STACK stack;


int isFull(stack s)
{
    if(s.Top==max-1)
        {   printf("stack is in overflow");
            return(1);
        }
    return(0);
}

int isEmpty(stack s)
{
    if(s.Top==-1)
    {
        printf("stack is in underflow");
        return(1);
    }
    return(0);
}

void push(stack s,int new_ele)
{
    if(!isFull(s))
    {
        s.ele[++s.Top]=new_ele;
    }
}

int pop(stack s)
{
    if(!isEmpty(s))
    {
        return(s.ele[s.Top--]);
    }
}

int peek(stack s)
 {
    if(!isEmpty(s))
    {
        return(s.ele[s.Top]);
    }
 }

void Traverse(stack s)
 {
    int i;
    for(i=s.Top;i>=0;i--)
        printf(" %d",s.ele[i]);
 }

 void sort(stack s1,stack s2)
 {
     int a,b;
     while(s1.Top!=-1)
     {

         if(s2.Top==-1)
         {
             a=pop(s1);
             push(s2,a);
         }
         else if(s2.ele[s2.Top]<=s1.ele[s1.Top])
         {
            a=pop(s1);
            push(s2,a);
         }
         else
         {
             a=pop(s1);
             while(s2.ele[s2.Top]>s1.ele[s1.Top])
             {
                 b=pop(s2);
                 push(s1,b);
             }
             push(s2,b);

         }

     }
     Traverse(s2);
 }

 int main()
 {
     int choice,new_ele;
     stack s1,s2;
     s1.Top=-1;
     s2.Top=-1;
     while(1)
     {
         printf("\n--------------------------------------\n");
         printf("\n         1   --->    push value         ");
         printf("\n         2   --->    pop  value         ");
         printf("\n         3   --->    peek               ");
         printf("\n         4   --->    Traverse           ");
         printf("\n         5   --->    sort               ");
         printf("\n         6   --->    exit             \n");
         printf("\n--------------------------------------\n");
         printf("\nEnter your choice");
         scanf("%d",&choice);
         switch(choice)
         {
         case 1:
            printf("\nEnter new value");
            scanf("%d",&new_ele);
            push(s1,new_ele);
            break;
         case 2:
            printf("\npop value is : %d",pop(s1));
            break;
         case 3:
            printf("\nTop of stack value is : %d",peek(s1));
            break;
         case 4:
            printf("\nTraversing of stack is :");
            Traverse(s1);
            break;
         case 5:
            printf("sorting : ");
            sort(s1,s2);
            break;
         case 6:
            return(0);

         }

     }
 }
