#include<stdio.h>
#define max 5

struct STACK
{
    int Top;
    int ele[max];
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
void push(int new_ele)
{
    if(!isFull())
    {
        s.ele[++s.Top]=new_ele;
    }
}

int pop()
{
    if(!isEmpty())
    {
        return(s.ele[s.Top--]);
    }
}

int peek()
 {
    if(!isEmpty())
    {
        return(s.ele[s.Top]);
    }
 }

void Traverse()
 {
    int i;
    for(i=s.Top;i>=0;i--)
        printf(" %d",s.ele[i]);
 }

void sort()
{
    int t,i,j;
    int l=s.Top;
    for(i=0;i<=l;i++)
    {
        for(j=i+1;j<=l;j++)
        {
            if(s.ele[i]>=s.ele[j])
            {
            t=s.ele[j];
            s.ele[j]=s.ele[i];
            s.ele[i]=t;
            }
        }
    }
}
int main()
 {
     int choice,new_ele;
     s.Top=-1;
     while(1)
     {
         printf("\n--------------------------------------\n");
         printf("\n         1   --->    push value         ");
         printf("\n         2   --->    pop  value         ");
         printf("\n         3   --->    peek               ");
         printf("\n         4   --->    Traverse           ");
         printf("\n         5   --->    exit             \n");
         printf("\n--------------------------------------\n");
         printf("\nEnter your choice");
         scanf("%d",&choice);
         switch(choice)
         {
         case 1:
            printf("\nEnter new value");
            scanf("%d",&new_ele);
            push(new_ele);
            break;
         case 2:
            printf("\npop value is : %d",pop());
            break;
         case 3:
            printf("\nTop of stack value is : %d",peek());
            break;
         case 4:
            printf("\nTraversing of stack is :");
            Traverse();
            break;
         case 5:
            printf("sorting ");
            break;
         case 6:
            return(0);

         }

     }
 }
