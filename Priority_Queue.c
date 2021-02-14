#include<stdio.h>
#define size 10

int priority[size];
char ele[size];
int total=0;

void Enqueue(char newele,int prio)
{
    int count=0,i;
    if(total>=size)
    {
        printf("Queue is a full");
    }
    else if(total==0)
    {
        ele[total]=newele;
        priority[total]=prio;
        total++;
    }
    else
    {
      while(count!=total)
      {
        if(prio>=priority[count])
            count++;
        else
            break;
       }

      if(count==total)
       {
         ele[count]=newele;
         priority[count]=prio;
         total++;
        }
      else
      {
        for(i=total;i>count;i--)
        {
            ele[i]=ele[i-1];
            priority[i]=priority[i-1];
        }
        ele[count]=newele;
        priority[count]=prio;
        total++;
      }
    }
}

void Dequeue(char dele,int prio)
{
    int count=0,i;
    if(total==0)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        while(count!=total)
        {
            if(prio==priority[count] && dele==ele[count])
                break;
            else
                count++;
        }
        if(count==total)
        {
            printf("\nElement is not found");
        }
        else
        {
            for(i=count;i<total;i++)
            {
                ele[i]=ele[i+1];
                priority[i]=priority[i+1];
            }
            total--;
            printf("\nDelete element is %c",dele);
        }
    }
}
void display()
{
    int i;
    for(i=0;i<total;i++)
    {
        printf("\nElement : %c  -->  priority : %d",ele[i],priority[i]);
    }
    printf("\n");
}

void main()
{
    int choice;
    int p;
    char newele;
    while(1)
    {
    printf("\n---------------------------------------------");
    printf("\n - - - - - - 1 --> Insertion - - - - - - - - ");
    printf("\n - - - - - - 2 --> Deletion - - - - - - - - -");
    printf("\n - - - - - - 3 --> Display - - - - - - - - - ");
    printf("\n - - - - - - 4 --> Exit - - - - - - - - - - -");
    printf("\n---------------------------------------------\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:
         printf("\nEnter element : ");
         scanf("%s",&newele);
         printf("\nEnter priority : ");
         scanf("%d",&p);
         Enqueue(newele,p);
         break;
     case 2:
         printf("\nEnter element : ");
         scanf("%s",&newele);
         printf("\nEnter priority : ");
         scanf("%d",&p);
         Dequeue(newele,p);
         break;
     case 3:
         printf("All element is : --->\n ");
         display();
         break;
     case 4:
        exit(0);

    }
    }
}
