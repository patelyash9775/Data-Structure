#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 20

struct STACK
{
    char ele[max];
    int Top;
};

typedef struct STACK stack;
stack s;

int is_Full()
{
    if(s.Top==max-1)
         return(1);
    return(0);
}

int is_Empty()
{
    if(s.Top==-1)
         return(1);
    return(0);
}

void push(char new_ele)
{
    if(!is_Full())
       s.ele[++s.Top]=new_ele;
}

char pop()
{
    if(!is_Empty())
       return(s.ele[s.Top--]);
}
int priority(char x)
{
   if(x=='$')
       return(3);
   else if(x=='*' || x=='/')
       return(2);
   else if(x=='+' || x=='-')
       return(1);
   else if(x=='(')
        return(0);
}


int main()
{
  char ex[20];
  s.Top=-1;
  int i=0;
  printf("Enter a infix string ");
  gets(ex);
  while(ex[i]!='\0')
  {
      if(isalnum(ex[i]))
      {
          printf("%c",ex[i]);
      }
      else if(ex[i]=='(')
      {
          push(ex[i]);
      }
      else if(ex[i]==')')
      {
          while(s.ele[s.Top]!='(')
          {
              printf("%c",pop());

          }
          s.Top--;
      }
      else
      {

          if(priority(ex[i])>priority(s.ele[s.Top]))
          {
              push(ex[i]);
          }
          else
          {
              if(ex[i]=='$' && s.ele[s.Top]=='$')
             {
              push(ex[i]);
             }

            else{
              while(priority(ex[i])<=priority(s.ele[s.Top]))
              {
                  printf("%c",pop());

              }
              push(ex[i]);
          }
          }

      }
      i++;
  }

    while(s.Top!=-1)
    {
          printf("%c",pop());
      }

   return(0);
}
