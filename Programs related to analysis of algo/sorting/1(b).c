
#include<stdio.h>

void main()
{
	int n,i,k,pos=0;
	printf("Enter the number of elements in the given data : ");
	scanf("%d",&n);
	
	int a[n];
	
	printf("\nEnter the elements : ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	selectionSort(a,n);
}

void selectionSort(int a[],int n)
{
	int temp,i,j,k;
	
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k])
			k=j;
		}
		if(k!=i)
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
	
	printf("\nThe elements after sorting are : ");
	
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
