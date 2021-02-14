#include<stdio.h>

struct node
{
    char ele;
    struct node *next;
};

typedef struct node node;
node *head=NULL;
node* createnode()
{
    node *n;
    n=(node*)malloc(sizeof(node));
    n->next=NULL;
    return(n);
}

node* Enqueue(char newele)
{
    node *newnode=createnode();
    node *tp;
    newnode->ele=newele;
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        tp=head;
        while(tp->next!=NULL)
        {
            tp=tp->next;
        }
        tp->next=newnode;
        return(head);
    }
}

  Dequeue()
 {
    node *tp;
    if(head==NULL)
    {
        printf("Queue is Empty");
    }
    else
    {   tp=head;
        printf("Deleted element is a %c",head->ele);
        head=head->next;
        free(tp);
    }
 }

 void Traverse()
{
    node *tp;
    tp=head;

    while(tp!=NULL)
    {
        printf(" %c",tp->ele);
        tp=tp->next;
    }
}

 void PEEK()
 {
     node *tp;
     tp=head;
     if(head==NULL)
     {
         printf("Stack is Empty");
     }
     else
     {
        while(tp->next!=NULL)
        {

        tp=tp->next;
        }
        printf("Front value is a %c",tp->ele);
     }
 }
void main()
 {
     char newele;
     int choice;
     while(1)
     {
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");
     printf("\n- - - - - - - - 1--> Enqueue - - - - - - - - - - - ");
     printf("\n- - - - - - - - 2--> Dequeue - - - - - - - - - - - ");
     printf("\n- - - - - - - - 3--> peek - - - - - - - - - - - -");
     printf("\n- - - - - - - - 4--> Traverse - - - - - - - - - -");
     printf("\n- - - - - - - - 5--> exit - - - - - - - - - - - -");
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");
     printf("\nEnter a your choice");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
        printf("\nEnter a new element");
        scanf("%s",&newele);
        head=Enqueue(newele);
        break;
     case 2:
        Dequeue();
        break;
     case 3:
        PEEK();
        break;
     case 4:
        Traverse();
        break;
     case 5:
        exit(0);
      }
     }
 }
