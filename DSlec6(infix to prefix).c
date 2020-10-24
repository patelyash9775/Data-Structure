#include<stdio.h>
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
    else
      return(0);
}

int is_Empty()
{
    if(s.Top==-1)
         return(1);
    else
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
   else if(x==')')
        return(0);
   else if(x=='\0')
        return(0);
}



int main()
{
  char ex[20];
  char a[20],b[20];
  s.Top=-1;
  int i=0,j;
  printf("Enter a infix string ");
  gets(a);
  for(j=strlen(a)-1;j>=0;j--)
  {
      ex[i]=a[j];
      i++;
  }

  i=0,j=0;
  while(ex[i]!='\0')
  {
      if(isalnum(ex[i]))
      {
          b[j++]=ex[i];
      }
      else if(ex[i]==')')
      {
          push(ex[i]);
      }
      else if(ex[i]=='(')
      {
          while(s.ele[s.Top]!=')')
          {
              b[j++]=pop();

          }
          s.Top--;
         }
      else
      {
          if(priority(ex[i])>=priority(s.ele[s.Top]))
          {
              if(ex[i]=='$' && s.ele[s.Top]=='$')
              {
                  while(ex[i]==s.ele[s.Top])
                  {
                      b[j++]=pop();
                  }
                  push(ex[i]);
              }
            else
              {     push(ex[i]);    }
          }
          else
          {

              while(priority(ex[i])<priority(s.ele[s.Top]))
              {
                  b[j++]=pop();

              }
              push(ex[i]);
          }
          }

      i++;
    }

    while(s.Top!=-1)
    {
        b[j++]=pop();
      }

    for(i=strlen(b)-1;i>=0;i--)
           printf("%c",b[i]);
    return(0);
  }
