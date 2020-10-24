#include<stdio.h>
#define max 10


struct STACK
{
    int Top;
    char ele[max];
};

typedef struct STACK stack;
stack s;

int is_Full()
{
    if(s.Top==max-1)
         {  printf("STACK is in overflow");
             return(1);
         }
    return(0);
}

int is_Empty()
{

    if(s.Top==-1)
        {  printf("STACK is in underflow");
            return(1);
        }
    return(0);
}

void push(int new_ele)
{
    if(!is_Full())
        s.ele[++s.Top]=new_ele;
}

int pop()
{
    if(!is_Empty())
      return(s.ele[s.Top--]);
}

int main()
 {
     int choice;
     char a;
     s.Top=-1;
     while(1)
     {
         printf("\n--------------------------------------\n");
         printf("\n         1   --->    push value         ");
         printf("\n         2   --->    pop  value         ");
         printf("\n         3   --->    Reverse string     ");
         printf("\n         4   --->    exit             \n");
         printf("\n--------------------------------------\n");
         printf("\nEnter your choice");
         scanf("%d",&choice);
         switch(choice)
         {
          case 1:
             printf("\nEnter new value : ");
             scanf("%c",&a);
             push(a);
             break;
          case 2:
              printf("\npop value is : %c",pop());
              break;
          case 3:
              printf("Reverse string is : ");
              while(s.Top!=-1)
                printf("%c",pop());
              break;
          case 4:
             return(0);
         }

     }

 }

