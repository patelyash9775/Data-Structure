#include<stdio.h>
#define max 5

struct CQUEUE
{
    int ele[max];
    int rear,front;
};

typedef struct CQUEUE CQueue;
CQueue q;

int isFull()
{
    if(q.front==(q.rear+1)%max)
    {
        printf("Queue is full");
        return(1);
    }
    else
       return(0);
}

int isEmpty()
{
  if(q.front==-1)
  {

    return(1);
  }
  else
    return(0);
}

void ENCQueue(int newele)
{
    if(!isFull())
    {
        if(q.rear==max-1)
            q.rear=0;
        else
            q.rear++;

        q.ele[q.rear]=newele;

        if(q.front==-1)
            q.front++;
    }
}

void DECQueue()
{
   if(isEmpty())
   {
       printf("Queue is Empty");
   }
   else if(q.front==q.rear)
   {
       q.front=q.rear=-1;
   }
   else
   {
       q.front=(q.front+1)%max;
   }
}

int PEEK()
{
    if(!isEmpty())
        return(q.ele[q.front]);
}

void Traverse()
{
    int i=q.front;
    while(i!=q.rear)
    {
        printf(" %d",q.ele[i]);
        i=(i+1)%max;
    }
    printf(" %d",q.ele[q.rear]);

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
     ENCQueue(newele);
     break;
  case 2:
     DECQueue();
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
