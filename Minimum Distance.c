#include<stdio.h>

main()
{
 int n,i,x,y,j;
 int l=0,m=0;
 printf("\nEnter no. of elements : ");
 scanf("%d",&n);
 int a[n],b[n],c[n];
 printf("\nEnter array :\n");
 for(i=0;i<n;i++)
 {
     scanf("%d",&a[i]);
 }
 printf("\nEnter two place : \n");
 scanf("%d %d",&x,&y);
 for(i=0;i<n;i++)
 {
     if(a[i]==x)
     {
         b[l++]=i;
     }
 }
  for(i=0;i<n;i++)
 {
     if(a[i]==y)
     {
         c[m++]=i;
     }
 }
  int min=b[0]-c[0];
  int d,p,q;
  p=b[0];
  q=c[0];
  for(i=0;i<l;i++)
  {
     for(j=0;j<m;j++)
     {
         d=b[i]-c[j];
        if(d>=0)
        {
            if(d<min)
               {
                   min=d;
                   p=b[i];
                   q=c[j];
               }

        }
        else
        {
            d=-d;
            if(d<min)
              {
                min=d;
                p=b[i];
                q=c[j];
              }

        }

     }
   }

 min=min<0?-min:min;
 printf("\n%d is at index %d and %d is at index %d So Minimum distance is a %d",x,p,y,q,min);
}
