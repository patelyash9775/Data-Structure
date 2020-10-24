#include<stdio.h>
#define max 5

struct CQUEUE
{
 int ele[max];
 int rear,front;
};

typedef struct CQUEUE CQueue;
CQueue q;

void Enqueue(int newele)
{
    if((q.front==0 && q.rear==max-1) || q.front==q.rear+1)
    {
        printf("Queue is overflow");
    }
    else if(q.rear==-1 || q.front==-1)
    {
        q.rear=q.front=0;
    }
    else if(q.rear==max-1)
    {
        q.rear=0;
    }
    else{
        q.rear=q.rear+1;
    }

    q.ele[q.rear]=newele;
}

int Dequeue()
{
    int num;
    num=q.ele[q.front];
    if(q.front==-1)
    {
        printf("Queue is underflow");
    }

    else if(q.front==max-1)
    {
        q.front=0;
    }
    else if(q.front==q.rear)
    {
        q.front=q.rear=-1;
    }
    else
    {
        q.front=q.front+1;
    }

    return(num);
}

int PEEK()
{
    if(q.front==-1)
    {
        printf("Queue is underflow");
        return;
    }
    else
    {
        return(q.ele[q.front]);
    }
}

void Traverse()
{
    int i;
    if(q.front==-1)
    {
        printf("Queue is Empty");
    }
    else{

        if(q.rear>=q.front)
        {
            for(i=q.front;i<=q.rear;i++)
                printf(" %d",q.ele[i]);
        }
        else
        {
            for(i=q.front;i<=max-1;i++)
                printf(" %d",q.ele[i]);
            for(i=0;i<=q.rear;i++)
                 printf(" %d",q.ele[i]);
        }

    }
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
     Enqueue(newele);
     break;
  case 2:
     printf("Deleted element is a %d",Dequeue());
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
