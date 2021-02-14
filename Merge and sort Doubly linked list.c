#include<stdio.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

node* createnode()
{
    node *n;
    n=(node*)malloc(sizeof(node));
    n->next=NULL;
    n->prev=NULL;
    return(n);
}

node* insert_at_end(node *head,int data)
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

 void Traverse(node *head)
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

node* sorting(node *p,node *q,node *s)
{
    node *t;
    if(p->info<q->info)
    {
        s=p;
        p=s->next;
    }
    else{
        s=q;
        q=s->next;
    }
    t=s;
    while(p!=NULL && q!=NULL)
    {
      if(p->info<q->info)
      {
          p->prev=s;
          s->next=p;
          s=p;
          p=s->next;
      }
      else{
          q->prev=s;
          s->next=q;
          s=q;
          q=s->next;
      }
    }
    if(p==NULL)
    {
        s->next=q;
        q->prev=s;
    }
    else
    {
        s->next=p;
        p->prev=s;
    }

    return(t);
}

void sort(node *head1)
{
    node *ptr,*cpt;
    ptr=head1;
    int temp;
    while(ptr->next!=NULL)
    {
        cpt=ptr->next;
        while(cpt!=NULL)
        {
            if(ptr->info>cpt->info)
            {
                temp=ptr->info;
                ptr->info=cpt->info;
                cpt->info=temp;
            }
            cpt=cpt->next;
        }
        ptr=ptr->next;
    }

}

void reverse(node *head)
{
    node *t;
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    while(t->prev!=NULL)
    {
        printf(" %d",t->info);
        t=t->prev;
    }
}

 void main()
 {
     int data,key;
     node *head1,*head2,*s;
     head1=NULL;
     head2=NULL;
     s=NULL;
     int choice;
     while(1)
     {
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");
     printf("\n- - - - - - - - 1--> Insert in list 1- - - - - - ");
     printf("\n- - - - - - - - 2--> Insert in list 2- - - - - - ");
     printf("\n- - - - - - - - 3--> Traverse of list 1- - - - - ");
     printf("\n- - - - - - - - 4--> Traverse of list 2- - - - - ");
     printf("\n- - - - - - - - 5--> sorting of list 1 - - - - - ");
     printf("\n- - - - - - - - 6--> sorting of list 2 - - - - - ");
     printf("\n- - - - - - - - 7--> merge sorted linked  list- -");
     printf("\n- - - - - - - - 8--> Exit- - - - - - - - - - - -");
     printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");
     printf("\nEnter a your choice");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
        printf("\nEnter a new element");
        scanf("%d",&data);
        head1=insert_at_end(head1,data);
        break;
     case 2:
        printf("\nEnter a new element");
        scanf("%d",&data);
        head2=insert_at_end(head2,data);
        break;
     case 3:
        Traverse(head1);
        break;
     case 4:
        Traverse(head2);
        break;
     case 5:
        sort(head1);
        break;
     case 6:
        sort(head2);
        break;
     case 7:
        s=sorting(head1,head2,s);
        printf("\nSorted doubly linked list is : ");
        Traverse(s);
        printf("\nReverse traverse is  : ");
        reverse(s);
        break;
     case 8:
        exit(0);
     }

     }
 }
