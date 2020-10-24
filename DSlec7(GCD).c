#include<stdio.h>

int GCD(int a,int b)
{
if(a==b)
  return(a);
else if(a%b==0)
  return(b);
else if(b%a==0)
  return(a);
else if(a>b)
  return(GCD(a%b,b));
else
  return(GCD(a,b%a));
}

int main()
{
 int a,b;
 printf("Enter a two number ");
 scanf("%d %d",&a,&b);
 printf("\nGCD is a %d",GCD(a,b));
}
