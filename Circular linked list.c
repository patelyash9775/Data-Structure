#include<stdio.h>

struct node
{
  int info;
  struct node *next ;
};

typedef struct node node;
node *head=NULL;

node* createnode()
{
    node *newnode;
    int data;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter a data : ");
    scanf("%d",&data);
    newnode->info=data;
    newnode->next=newnode;
    return(newnode);
}


node* insert_at_end(node *newnode)
{
    node *tp;

    if(head==NULL)
    {
        head=newnode;
        head->next=head;
        return(head);
    }

    else
    {
        tp=head;
        while(tp->next!=head)
        {
            tp=tp->next;
        }
        tp->next=newnode;
        newnode->next=head;
        return(head);
    }
}

node* insert_at_beg(node *newnode)
{
    node *tp;
    if(head=='\0')
    {
        head=newnode;
        head->next=head;
        return(head);
    }
    else
    {
        tp=head;
        while(tp->next!=head)
        {
            tp=tp->next;
        }
        tp->next=newnode;
        newnode->next=head;
        head=newnode;
        return(head);
    }
}

node* insert_at_afternode(int key,node *newnode)
{
    node *tmp,*tp;
    if(head=='\0')
    {
        printf("Linked list is not exist");
        return(head);
    }
    else
    {
        tp=head;
        while(tp->next!=head && tp->info!=key)
        {
            tp=tp->next;
        }
       if(tp->info==key)
       {
           if(tp->next==head)
           {
              tp->next=newnode;
              newnode->next=head;
              return(head);
           }
           else{
            newnode->next=tp->next;
            tp->next=newnode;
            return(head);
           }

       }
       else
       {
           printf("\nData has not found");
           return(head);
       }

        }
    }

void Delete_at_beg()
{
     node *tp,*tmp;
    if(head==NULL)
    {
        printf("linked list is Empty");
    }
    else
    {
        if(head->next==head)
        {
            printf("Deleted value is a %d",head->info);
            head=NULL;
        }
        else{
        tp=head;
        tmp=head;
        printf("Deleted element is a %d",head->info);
        head=head->next;
        while(tmp->next!=tp)
        {
            tmp=tmp->next;
        }
        tmp->next=head;
        free(tp);
        }
    }
}

void Delete_at_end()
{
    node *prev,*tp;
    if(head==NULL)
    {
        printf("linked list is Empty");
    }
    else{
        if(head->next==head)
        {
            printf("Deleted value is a %d",head->info);
            head=NULL;
        }
        else
        {
            tp=head;
            while(tp->next!=head)
            {
                prev=tp;
                tp=tp->next;
            }
            printf("Deleted value is a %d",tp->info);
            prev->next=head;
            free(tp);
        }

    }
}

void Delete_at_afternode(int key)
{
   node *tp,*tmp;
   if(head=='\0')
    {
        printf("Linked list is not exist");
    }
   else{

        tp=head;
        while(tp->next!=head && tp->info!=key)
        {
            tp=tp->next;
        }
        if(tp->info==key)
        {
            if(head->next==head)
            {   printf("Deleted value is a %d",head->info);
                head=NULL;
            }
            else if(tp->next==head)
            {
                printf("Deleted value is a %d",tp->next->info);
                tmp=head;
                head=head->next;
                tp->next=head;
                free(tmp);
            }
            else
            {
                printf("Deleted value is a %d",tp->next->info);
                tmp=tp->next;
                tp->next=tmp->next;
                free(tmp);
            }
        }
        else{
            printf("Data is not found");
        }
        }
}
void Traverse()
{
    node *tp;
    tp=head;
    if(head==NULL)
    {
        printf("Circular linked list is not exist");
    }
    else
    {
    while(tp->next!=head)
    {
     printf("%d ",tp->info);
     tp=tp->next;
    }
    printf("%d",tp->info);
    }
}
void main()
 {
     int key;
     node *newnode;
     int choice;
     while(1)
     {
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");
     printf("\n- - - - - - - - 1--> Insert at beg - - - - - - - ");
     printf("\n- - - - - - - - 2--> Insert at End - - - - - - - ");
     printf("\n- - - - - - - - 3--> Insert at afternode- - - - -");
     printf("\n- - - - - - - - 4--> Delete at beg - - - - - - -");
     printf("\n- - - - - - - - 5--> Delete at End - - - - - - -");
     printf("\n- - - - - - - - 6--> Delete at afternode - - - -");
     printf("\n- - - - - - - - 7--> Traverse- - - - - - - - - -");
     printf("\n- - - - - - - - 8--> Exit- - - - - - - - - - - -");
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");
     printf("\nEnter a your choice");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
        newnode=createnode();
        head=insert_at_beg(newnode);
        break;
     case 2:
        newnode=createnode();
        head=insert_at_end(newnode);
        break;
     case 3:
        newnode=createnode();
        printf("Enter a key");
        scanf("%d",&key);
        head=insert_at_afternode(key,newnode);
        break;
     case 4:
        Delete_at_beg();
        break;
     case 5:
        Delete_at_end();
        break;
     case 6:
        printf("Enter a key: ");
        scanf("%d",&key);
        Delete_at_afternode(key);
        break;
     case 7:
        Traverse();
        break;
     case 8:
        exit(0);
     }
    }
 }
