#include<stdio.h>

int fact(int n)
{
if(n==0 || n==1)
  return(1);
return(n*fact(n-1));
}

int main()
{
int n;
printf("Enter a number : ");
scanf("%d",&n);
printf("factorial of %d is a %d",n,fact(n));
}
