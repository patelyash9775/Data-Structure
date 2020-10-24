#include<stdio.h>
#define max 5

struct DEQUEUE
{
    int ele[max];
    int rear,front;
};

typedef struct DEQUEUE DEQueue;
DEQueue q;

Enqueuefront(int newele)
{
    if((q.front==0 && q.rear==max-1) || q.front==q.rear+1)
        printf("Dequeue is overflow");
    else if(q.front==-1 && q.rear==-1)
        {
            q.front=q.rear=0;
            q.ele[q.front]=newele;
        }
    else if(q.front==0)
         {   q.front=max-1;
             q.ele[q.front]=newele;
         }
    else
          {
              q.front--;
              q.ele[q.front]=newele;
          }
}

Enqueuerear(int newele)
{
    if((q.front==0 && q.rear==max-1) || q.front==q.rear+1)
         printf("\nDequeue is overflow");
    else if(q.front==-1 && q.rear==-1)
        {
            q.rear=q.front=0;
            q.ele[q.rear]=newele;
        }
    else if(q.rear==max-1)
    {
        q.rear=0;
        q.ele[q.rear]=newele;
    }
    else
    {
        q.rear++;
        q.ele[q.rear]=newele;
    }

}

Dequeuefront()
{
    if(q.front==-1)
    {
        printf("\nDequeue is underflow");
    }
    else if(q.front==q.rear)
    {
        printf("Deleted element is a %d",q.ele[q.front]);
        q.front=q.rear=-1;
    }
    else if(q.front==max-1)
    {
        printf("Deleted element is a %d",q.ele[q.front]);
        q.front=0;
    }
    else{

        printf("Deleted element is a %d",q.ele[q.front]);
        q.front++;
    }
}

Dequeuerear()
{
     if(q.front==-1)
    {
        printf("\nDequeue is underflow");
    }
    else if(q.front==q.rear)
    {
        printf("Deleted element is a %d",q.ele[q.rear]);
        q.front=q.rear=-1;
    }
    else if(q.rear==0)
    {
         printf("Deleted element is a %d",q.ele[q.rear]);
         q.rear=max-1;
    }
    else{
         printf("Deleted element is a %d",q.ele[q.rear]);
         q.rear--;
    }
}

PEEK()
{
    if(q.front==-1)
    {
        printf("\nDequeue is Empty");
    }
    else{

        printf("Front element is a %d",q.ele[q.front]);
    }

}

Traverse()
{
    int i=q.front;
    if(q.front==-1)
    {
        printf("\nDequeue is Empty");
    }
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
  printf("\n - - - - - - -> 1. insert front - - - - - - - - - - ");
  printf("\n - - - - - - -> 2. Remove front - - - - - - - - - - ");
  printf("\n - - - - - - -> 3. insert rear - - - - - - - - - - -");
  printf("\n - - - - - - -> 4. Remove rear - - - - - - - - - - -");
  printf("\n - - - - - - -> 5. Display front element- - - - - -");
  printf("\n - - - - - - -> 6. Traverse - - - - - - - - - - - -");
  printf("\n - - - - - - -> 7. Exit - - - - - - - - - - - - - -");
  printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
  printf("\nEnter a your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
     printf("\nEnter new element : ");
     scanf("%d",&newele);
     Enqueuefront(newele);
     break;
  case 2:
     Dequeuefront();
     break;
  case 3:
     printf("\nEnter new element : ");
     scanf("%d",&newele);
     Enqueuerear(newele);
     break;
  case 4:
     Dequeuerear();
     break;
  case 5:
     PEEK();
     break;
  case 6:
     printf("\nTraversing is a ");
     Traverse();
     break;
  case 7:
     exit(0);

  }
  }
}
