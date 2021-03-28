#include<stdio.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node node;
node *newnode,*front,*rear,*temp;

node* createnode()
{
    node *n;
    int info;
    n=(struct node*)malloc(sizeof(node));
    n->prev=NULL;
    n->next=NULL;
    printf("\nEnter a value:- ");
    scanf("%d",&info);
    n->data=info;
    return(n);
}

void Display()
{
    node *temp;
    if(front==NULL)
    {
        printf("\nDequeue is an empty");
    }
    else{
        temp=front;
        while(temp!=NULL)
        {
            printf(" %d",temp->data);
            temp=temp->next;
        }
    }
}

void insert_at_front()
{
    node *n;
    n=createnode();
    if(front==NULL)
    {
        front=n;
        rear=n;
    }
    else{
    n->next=front;
    front->prev=n;
    front=n;
    }
}

void insert_at_rear()
{
    node *n;
    n=createnode();
    if(rear==NULL)
    {
        front=n;
        rear=n;
    }
    else{
    n->prev=rear;
    rear->next=n;
    rear=n;
    }
}

void delete_at_front()
{
    node *temp;
    if(front==NULL)
    {
        printf("\nDequeue is an empty");
    }
    else{
        temp=front;
        printf("Deleted value is a %d",front->data);
        front=front->next;
        front->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
}

void delete_at_rear()
{
    node *temp;
    if(rear==NULL)
    {
        printf("\nDequeue is an empty");
    }
    else{
        temp=rear;
        printf("Deleted value is a %d",rear->data);
        rear=rear->prev;
        rear->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
}

void main()
 {
     int choice;
     while(1)
     {
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");
     printf("\n- - - - - - 1--> Insert at front - - - - - - - - -");
     printf("\n- - - - - - 2--> Insert at rear- - - - - - - - - -");
     printf("\n- - - - - - 3--> Delete at front - - - - - - - - -");
     printf("\n- - - - - - 4--> Delete at rear - - - - - - - - -");
     printf("\n- - - - - - 5--> Display- - - - - - - - - - - - -");
     printf("\n- - - - - - 6--> Exit- - - - - - - - - - - - - - -");
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");
     printf("\nEnter a your choice :- ");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
         insert_at_front();
         break;
     case 2:
         insert_at_rear();
         break;
     case 3:
         delete_at_front();
         break;
     case 4:
         delete_at_rear();
         break;
     case 5:
         Display();
         break;
     case 6:
        exit(0);
     default:
        printf("Your choice is not available");
     }

     }
 }
