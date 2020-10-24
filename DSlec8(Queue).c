#include<stdio.h>
#define max 5

struct QUEUE
{
    int ele[max];
    int rear,front;
};

typedef struct QUEUE queue;
queue q;

int isFull()
{
    if(q.rear==max-1)
    {
        printf("queue is full");
        return(1);
    }
    else
         return(0);
}

int isEmpty()
{
    if(q.front>q.rear || q.front==-1)
    {
        printf("queue is empty");
        return(1);
    }
    else
        return(0);
}

void ENQueue(int newele)
{
    if(!isFull())
    {
        q.rear++;
        q.ele[q.rear]=newele;
        if(q.front==-1)
            q.front++;
    }
}

 void DEQueue()
{

    if(!isEmpty())
    {

        q.front++;
    }
}

int PEEK()
{
    if(!isEmpty())
    {
      return(q.ele[q.front]);
    }
}

void Traverse()
{
    int i;
    for(i=q.front;i<=q.rear;i++)
        printf(" %d",q.ele[i]);
}

int main()
{
  int newele,choice;
  q.rear=q.front=-1;
  while(1)
  {
  printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - -");
  printf("\n - - - - - - -> 1. insert element - - - - - - - - -");
  printf("\n - - - - - - -> 2. Remove element - - - - - - - - -");
  printf("\n - - - - - - -> 3. Display front element- - - - - -");
  printf("\n - - - - - - -> 4. Traverse - - - - - - - - - - - -");
  printf("\n - - - - - - -> 5. Exit - - - - - - - - - - - - - -");
  printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
  printf("\nEnter a your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
     printf("\nEnter new element : ");
     scanf("%d",&newele);
     ENQueue(newele);
     break;
  case 2:
     DEQueue();
     break;
  case 3:
     printf("\nFront element is a %d",PEEK());
     break;
  case 4:
     printf("\nTraversing is a ");
     Traverse();
     break;
  case 5:
     exit(0);
  }
  }
}
