#include<stdio.h>

int main()
{

    int a[20],b[20],c[20];
    int i,j,k;
    int p,q;
    printf("\nNo. of elements for array 1: - ");
    scanf("%d",&p);
    printf("\nNo. of elements for array 2: - ");
    scanf("%d",&q);
    printf("\nEnter elements for array 1 : -");
    for(i=0;i<p;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter elements for array 2: - ");
    for(j=0;j<q;j++)
    {
        scanf("%d",&b[j]);
    }
    i=0;
    j=0;
    k=0;
    while(i!=p && j!=q)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }

    while(i==p && j!=q)
    {
        c[k++]=b[j++];

    }

    while(j==q && i!=p)
    {
        c[k++]=a[i++];
    }

    printf("Result array is a : ");
    for(i=0;i<k;i++)
    {
        printf(" %d",c[i]);
    }

}
