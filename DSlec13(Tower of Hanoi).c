#include<stdio.h>

void Hanoi(char source,char dest,char aux,int n)
{
    if(n==1)
      printf("\nMove %d th disk from %c to %c",n,source,dest);
    else
    {
     Hanoi(source,aux,dest,n-1);
     printf("\nMove %d th disk from %c to %c",n,source,dest);
     Hanoi(aux,dest,source,n-1);
    }

}

void main()
{
    int n;
    char s,a,d;
    s='A';
    a='B';
    d='C';
    printf("Enter no. of disks : ");
    scanf("%d",&n);
    Hanoi(s,d,a,n);
}
