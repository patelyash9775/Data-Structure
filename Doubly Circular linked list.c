#include<stdio.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

typedef struct node node;
node *head=NULL;

node* createnode()
{
   node *newnode;
   int data;
   newnode=(node*)malloc(sizeof(node));
   printf("Enter a data : ");
   scanf("%d",&data);
   newnode->prev=newnode;
   newnode->next=newnode;
   newnode->info=data;
   return(newnode);
}

node* insert_at_beg(node *newnode)
{
    node *last;
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
      node *last=head->prev;
      head->prev=newnode;
      newnode->next=head;
      head=newnode;
      head->prev=last;
      return(head);
    }
}

node* insert_at_end(node *newnode)
{
    node *last;
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        last=head->prev;
        head->prev=newnode;
        newnode->prev=last;
        last->next=newnode;
        newnode->next=head;
        return(head);
    }
}

node* insert_at_afternode(node *newnode,int key)
{
    node *tp,*last;
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else{
        tp=head;
        while(tp->next!=head && tp->info!=key)
        {
            tp=tp->next;
        }
        if(tp->info==key)
        {
            if(tp->next==head)
            {
                last=head->prev;
                head->prev=newnode;
                newnode->prev=last;
                last->next=newnode;
                newnode->next=head;
                return(head);
            }
            else{
                newnode->next=tp->next;
                tp->next->prev=newnode;
                tp->next=newnode;
                newnode->prev=tp;
                return(head);
            }
        }
        else
        {
            printf("Data is not found");
        }
    }
}

node* insert_at_place(node *newnode,int pos)
{
  node *tp,*last,*p;
  int count=1;
  tp=head;
  while(tp->prev->next!=head && count!=pos)
  {
      p=tp;
      tp=tp->next;
      count++;
  }
   if(head==NULL)
  {
      if(pos==1)
      {
          head=newnode;
          return(head);
      }
      else
        {  printf("We can not insert at there because linked list is empty");
           return(head);
        }
    }
   else if(count==pos)
   {
       if(pos==1 && head!=NULL)
       {
        last=head->prev;
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        head->prev=last;
        return(head);
       }
       else if(p->next==head)
       {
           p->next=newnode;
           newnode->prev=p;
           newnode->next=head;
           head->prev=newnode;
           return(head);
       }
       else{
          newnode->next=p->next;
          p->next=newnode;
          newnode->prev=p;
          tp->prev=newnode;
          return(head);
       }
   }
  else{
    printf("position is not available");
    return(head);
  }

}

node* Delete_at_beg()
{
    node *last,*tp;
    if(head==NULL)
    {
        printf("Doubly Circular linked list is not exist");
        return(head);
    }
    else
    {
        if(head->next==head)
        {
            printf("Deleted value is a %d",head->info);
            head=NULL;
            return(head);
        }
        else{
            last=head->prev;
            tp=head;
            printf("Deleted value is a %d",head->info);
            head=head->next;
            head->prev=last;
            last->next=head;
            free(tp);
            return(head);
        }
    }
}

void Delete_at_end()
{
    node *last,*tp;
    if(head==NULL)
    {
        printf("Doubly Circular linked list is not exist");
    }
    else{
        if(head->next==head)
        {
            printf("Deleted value is a %d",head->info);
            head=NULL;
        }
        else{
            last=head->prev;
            printf("Deleted value is a %d",last->info);
            last->prev->next=head;
            head->prev=last->prev;
            free(last);
        }
    }
}

void Delete_at_afternode(int key)
{
    node *tp,*tmp;
    if(head==NULL)
    {
         printf("Doubly Circular linked list is not exist");
    }
    else{
        tp=head;
        while(tp->next!=head && tp->info!=key)
        {
            tp=tp->next;
        }
        if(tp->info==key)
        {
            if(tp->next==head)
            {
                printf("Here after node not available");
            }

            else{

                tmp=tp->next;
                printf("Deleted value is a %d",tmp->info);
                if(tmp->next!=head)
                {
                tmp->next->prev=tmp->prev;
                }
                tp->next=tp->next->next;
                free(tmp);
            }
        }
        else
        {
            printf("Data is not found");
        }
    }
}

node* Delete_at_place(int pos)
{
    int count=1;
    node *tp,*last;
    if(head==NULL)
    {
       printf("Doubly Circular linked list is not exist");
       return(head);
    }
    else
    {
     tp=head;
     while(tp->next!=head && count!=pos)
     {
         tp=tp->next;
         count++;
     }
    if(count==pos)
      {
          if(head->next==head)
          {
              printf("Deleted value is a %d",head->info);
              head=NULL;
              return(head);
          }
          else if(pos==1)
          {
            last=head->prev;
            printf("Deleted value is a %d",head->info);
            head=head->next;
            head->prev=last;
            last->next=head;
            free(tp);
            return(head);
          }
          else if(tp->next==head)
          {   printf("Deleted value is a %d",tp->info);
              tp->prev->next=head;
              head->prev=tp->prev;
              free(tp);
              return(head);
          }
          else{
            tp->prev->next=tp->next;
            tp->next->prev=tp->prev;
            printf("Deleted value is a %d",tp->info);
            free(tp);
            return(head);
          }
      }
      else{
        printf("Position is not available");
        return(head);
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
    while(tp->next!=head)
    {
        printf(" %d",tp->info);
        tp=tp->next;
    }
    printf(" %d",tp->info);
    }
}

void Revtraverse()
{
    node *tp;
    if(head==NULL)
    {
        printf("Doubly linked list is empty");
    }
    else{
    tp=head->prev;
    printf("\nReverse traverse is a ");
    while(tp->prev!=head->prev)
    {
        printf("%d ",tp->info);
        tp=tp->prev;
    }
    printf("%d",tp->info);
    }

}

void main()
 {
     int key,pos;
     node *newnode;
     int choice;
     while(1)
     {
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");
     printf("\n- - - - - - - - 1--> Insert at beg - - - - - - - ");
     printf("\n- - - - - - - - 2--> Insert at End - - - - - - - ");
     printf("\n- - - - - - - - 3--> Insert at afternode- - - - -");
     printf("\n- - - - - - - - 4--> Insert at position- - - - -");
     printf("\n- - - - - - - - 5--> Delete at beg - - - - - - -");
     printf("\n- - - - - - - - 6--> Delete at End - - - - - - -");
     printf("\n- - - - - - - - 7--> Delete at afternode - - - -");
     printf("\n- - - - - - - - 8--> Delete at position- - - - -");
     printf("\n- - - - - - - - 9--> Traverse- - - - - - - - - -");
     printf("\n- - - - - - - -10--> Reverse Traverse- - - - - -");
     printf("\n- - - - - - - -11--> Exit- - - - - - - - - - - -");
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
        head=insert_at_afternode(newnode,key);
        break;
     case 4:
        newnode=createnode();
        printf("Enter a position : ");
        scanf("%d",&pos);
        head=insert_at_place(newnode,pos);
        break;
     case 5:
        head=Delete_at_beg();
        break;
     case 6:
        Delete_at_end();
        break;
     case 7:
        printf("Enter a key");
        scanf("%d",&key);
        Delete_at_afternode(key);
        break;
     case 8:
        printf("Enter a position : ");
        scanf("%d",&pos);
        head=Delete_at_place(pos);
        break;
     case 9:
        Traverse();
        break;
     case 10:
        Revtraverse();
        break;
     case 11:
        exit(0);
     }
    }
 }


