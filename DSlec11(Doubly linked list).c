#include<stdio.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

typedef struct node node;
node *head=NULL;

node* createnode()
{
    node *n;
    n=(node*)malloc(sizeof(node));
    n->next=NULL;
    n->prev=NULL;
    return(n);
}

node* insert_at_beg(int data)
{
    node *newnode=createnode();
    newnode->info=data;
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return(head);
    }
}

node* insert_at_end(int data)
{
    node *newnode=createnode();
    newnode->info=data;
    node *tp;
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
      newnode->prev=tp;
      return(head);
    }
}

void insert_at_afternode(int key,int data)
{
    node *newnode,*tp,*tmp;
    newnode=createnode();
    newnode->info=data;
    if(head==NULL)
    {
        printf("Linked list is a empty");
    }
    else
    {
        tp=head;
        while(tp->next!=NULL && tp->info!=key)
        {
            tp=tp->next;
        }
       if(tp->info==key)
       {
           tmp=tp->next;
           tp->next=newnode;
           newnode->prev=tp;
           if(tmp!=NULL)
           {
               newnode->next=tmp;
               tmp->prev=newnode;
           }

       }
       else{
        printf("Data is not found");

       }
    }
}

 void Delete_at_beg()
 {
   node *tp;
   if(head==NULL)
   {
       printf("Doubly linked list is empty");
   }
   else
   {
       tp=head;
       printf("Deleted element is a %d",head->info);
       head=head->next;
       head->prev=NULL;
       free(tp);
   }
 }

 void Delete_at_end()
 {
     node *tp,*tmp;
     if(head==NULL)
     {
         printf("Doubly linked list is empty");
     }
     else
     {   if(head->next==NULL)
         {
             printf("Deleted value is a %d",head->info);
             head=NULL;

         }
         else
         {
         tp=head;
         while(tp->next!='\0')
         {   tmp=tp;
             tp=tp->next;
         }
         printf("Deleted value is a %d",tp->info);
         tmp->next=NULL;
         free(tp);
         }
     }
 }

 void Delete_at_afternode(int key)
 {
     node *tp,*tmp;
     if(head==NULL)
     {
         printf("Doubly linked list is empty");
     }
     else
     {
         tp=head;
         while(tp->next!=NULL && tp->info!=key)
         {
             tp=tp->next;
         }
        if(tp->info==key)
        {
          if(tp->next==NULL)
          {
            printf("After node is not available");
           }
          else{

          tmp=tp->next;
          tp->next=tmp->next;
          printf("\nDeleted value is %d",tmp->info);
          if(tmp->next!=NULL)
          {
          tmp->next->prev=tp;
           }
          free(tmp);
           }
        }
        else
        {
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
        printf("Doubly linked list is empty");
    }
    else{
    while(tp!=NULL)
    {
        printf(" %d",tp->info);
        tp=tp->next;
    }
    }
}

void Revtraverse()
{
    node *tp;
    tp=head;
    while(tp->next!=NULL)
    {
        tp=tp->next;
    }
    printf("\nReverse traverse is a ");
    while(tp!=NULL)
    {
        printf("%d ",tp->info);
        tp=tp->prev;
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
     printf("\n- - - - - - - - 8--> Reverse Traverse- - - - - -");
     printf("\n- - - - - - - - 9--> Exit- - - - - - - - - - - -");
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
        insert_at_afternode(key,data);
        break;
     case 4:
        Delete_at_beg();
        break;
     case 5:
        Delete_at_end();
        break;
     case 6:
        printf("\nEnter a key");
        scanf("%d",&key);
        Delete_at_afternode(key);
        break;
     case 7:
        Traverse();
        break;
     case 8:
        Revtraverse();
        break;
     case 9:
        exit(0);
     }

     }
 }
