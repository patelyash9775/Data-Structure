#include<stdio.h>
#define capacity 5

Traverse(int a[],int n)
{
	int i;
	printf("Traversing\n");
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
}
int search(int a[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(key==a[i])
		   return i;
	}
	return -1;
}
int insertion(int a[],int n,int new_ele)
{
	if(n>=capacity)
	{
		printf("\narray is full");
		return n;
	}
	else
	{ a[n]=new_ele;
	  return(n+1);
	}
}

int deletion(int a[],int n,int delete_ele)
{
	int index=search(a,n,delete_ele);
	int i;
	if(index==-1)
	   return n;
	else
	{
		for(i=index;i<n;i++)
		{
			a[i]=a[i+1];
		}
		return (n-1);
	   }

}
main()
{
	int a[capacity],i,n,m,key,new_ele,delete_ele;
	printf("How many elemens we want to add");
	scanf("%d",&n);
	printf("\nEnter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	Traverse(a,n);
	printf("\nEnter element which we want to search");
	scanf("%d",&key);
	m=search(a,n,key);
	if(m==-1)
	   printf("\nThis element is not available in array");
	printf("\nSearching is successful");

	printf("\nEnter new element which we want to add end of array");
	scanf("%d",&new_ele);
	n=insertion(a,n,new_ele);
	printf("\n");
	Traverse(a,n);

	printf("\nEnter element we want to delete in array");
	scanf("%d",&delete_ele);
	n=deletion(a,n,delete_ele);
	printf("\nFinal array is a ");
	Traverse(a,n);

}
