#include<stdio.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
    int ele[max];
    int rear,front;
};

typedef struct node node;

node* createnode()
{
    int data;
    printf("\nEnter a data :");
    scanf("%d",&data);
    node *n;
    n=(node*)malloc(sizeof(node));
    n->info=data;
    n->left=NULL;
    n->right=NULL;
    return(n);
}

void insert(node *rt,node *newnode)
{
    if(newnode->info<rt->info)
    {
        if(rt->left==NULL)
        {
            rt->left=newnode;
        }
        else
        {
            insert(rt->left,newnode);
        }
    }
    else if(newnode->info>rt->info)
    {
        if(rt->right==NULL)
        {
            rt->right=newnode;
        }
        else
        {
            insert(rt->right,newnode);
        }
    }
}

void intraverse(node *rt)
{
    if(rt!=NULL)
    {
        intraverse(rt->left);
        printf(" %d",rt->info);
        intraverse(rt->right);
    }
}

void pretraverse(node *rt)
{
    if(rt!=NULL)
    {
        printf(" %d",rt->info);
        pretraverse(rt->left);
        pretraverse(rt->right);
    }
}


void posttraverse(node *rt)
{
    if(rt!=NULL)
    {
        posttraverse(rt->left);
        posttraverse(rt->right);
        printf(" %d",rt->info);
    }
}

void BST(node *rt,int key)
{
    if(rt->info==key)
    {
        printf("Searching is successful");
    }
    else if(key<rt->info)
    {
        if(rt->left==NULL)
        {
             printf("Searhing is an unsuccessful");
        }
        else
        {
       BST(rt->left,key);
        }
    }
    else if(key>rt->info)
    {
        if(rt->right==NULL)
        {
            printf("Searhing is an unsuccessful");
        }
        else
        {
        BST(rt->right,key);
        }
    }

}

int maxdepth(node *rt)
{

    if(rt==NULL)
    {
        return(0);
    }
    int leftdepth=maxdepth(rt->left);
    int rightdepth=maxdepth(rt->right);
    if(leftdepth>rightdepth)
    {
         return(1+leftdepth);
    }
    else
    {
        return(1+rightdepth);
    }

}

int calculatesum(node *rt)
{
   int sum,sumleft,sumright;
   sum=sumleft=sumright=0;
   if(rt==NULL)
   {
       printf("\nTree is empty");
       return(0);
   }
   else
   {
    if(rt->left!=NULL)
   {
      sumleft=calculatesum(rt->left);
   }
   if(rt->right!=NULL)
   {
       sumright=calculatesum(rt->right);
   }
   sum=rt->info+sumleft+sumright;
   return(sum);
   }

}


void main()
{
  node *newnode,*root;
  root=NULL;
  newnode=NULL;
  int choice,key;
  while(1)
  {
  printf("\n- - - - - - - - - - - - - - - - - - - - -\n");
  printf("\n- - - - - - 1 - -> Insert - - - - - - - - ");
  printf("\n- - - - - - 2 - -> Intraverse - - - - - - ");
  printf("\n- - - - - - 3 - -> Pretraverse- - - - - - ");
  printf("\n- - - - - - 4 - -> Posttraverse - - - - - ");
  printf("\n- - - - - - 5 - -> BST - - - - - - - - - ");
  printf("\n- - - - - - 6 - -> Depth of tree - - - - ");
  printf("\n- - - - - - 7 - -> Sum of information- - ");
  printf("\n- - - - - - 8 - -> Exit - - - - - - - - - ");
  printf("\n- - - - - - - - - - - - - - - - - - - - -\n");
  printf("\nEnter a choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
      if(root==NULL)
         root=createnode();
      else
      {
          newnode=createnode();
          insert(root,newnode);
      }
      break;
  case 2:
     intraverse(root);
     break;
  case 3:
     pretraverse(root);
     break;
  case 4:
     posttraverse(root);
     break;
  case 5:
     printf("\nEnter a key");
     scanf("%d",&key);
     BST(root,key);
     break;
  case 6:
     printf("\nMaximum depth of tree is %d",maxdepth(root));
     break;
  case 7:
     printf("\nSum of all information is  a %d",calculatesum(root));
     break;
  case 8:
     exit(0);
  default:
      printf("\nYour choice is a wrong");
      break;
  }

  }
}
