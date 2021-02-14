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
    newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    return(newnode);

}

node* insert_at_end(int data)
{
    node *newnode=createnode();
    node *tp;
    newnode->info=data;
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        tp=head;
        while(tp->next!='\0')
        {
            tp=tp->next;
        }
        tp->next=newnode;
        return(head);
    }
}

node* insert_at_beg(int data)
{
    node *newnode=createnode();
    newnode->info=data;
    if(head=='\0')
    {
        head=newnode;
        return(head);
    }
    else
    {
        newnode->next=head;
        head=newnode;
        return(head);
    }
}

node* insert_at_afternode(int key,int data)
{
    node *newnode=createnode();
    node *tmp,*tp;
    newnode->info=data;
    if(head=='\0')
    {
        printf("Linked list is not exist");
        return(head);
    }
    else
    {
        tp=head;
        while(tp!='\0' && tp->info!=key)
        {
            tp=tp->next;
        }
        if(tp=='\0')
        {
            printf("Data is not found");
            return(head);
        }
        else{
            tmp=tp->next;
            tp->next=newnode;
            newnode->next=tmp;
            return(head);
        }
    }

}

void Delete_at_beg()
 {
    node *tp;
    if(head==NULL)
    {
        printf("linked list is Empty");
    }
    else
    {   tp=head;
        printf("Deleted element is a %d",head->info);
        head=head->next;
        free(tp);
    }
 }

 void Delete_at_end()
{
    node *tp,*tmp;
    tp=head;
    if(head==NULL)
    {
         printf("linked list is Empty");
     }
    else
    {
    while(tp->next!=NULL)
    {
        tmp=tp;
        tp=tp->next;
    }
    tmp->next=NULL;
    printf("Deleted value is a %d",tp->info);
    free(tp);
    }

}

void Delete_at_afternode(int key)
{
   node *tp,*tmp;
   if(head=='\0')
    {
        printf("Linked list is not exist");
    }
   else
    {
        tp=head;
        while(tp!='\0' && tp->info!=key)
        {
            tp=tp->next;
        }
        if(tp=='\0')
        {
            printf("Data is not found");
        }
        else
        {
            tmp=tp->next;
            printf("Deleted value is a %d",tmp->info);
            tp->next=tmp->next;
            free(tmp);
        }
    }
}

void Traverse()
{
    node *tp;
    tp=head;

    while(tp!=NULL)
    {
        printf(" %d",tp->info);
        tp=tp->next;
    }
}

void main()
 {
     int data,key;
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
        printf("\nEnter a new element");
        scanf("%d",&data);
        head=insert_at_beg(data);
        break;
     case 2:
        printf("\nEnter a new element");
        scanf("%d",&data);
        head=insert_at_end(data);
        break;
     case 3:
        printf("\nEnter a new element");
        scanf("%d",&data);
        printf("Enter a key");
        scanf("%d",&key);
        head=insert_at_afternode(key,data);
        break;
     case 4:
        Delete_at_beg();
        break;
     case 5:
        Delete_at_end();
        break;
     case 6:
        printf("Enter a key");
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
     return(0);
 }
