
#include<stdio.h>

void main()
{
	int n,i;
	printf("Enter the number of elements in the given data : ");
	scanf("%d",&n);
	
	int a[n];
	
	printf("\nEnter the elements : ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);

	insertionSort(a,n);
}

void insertionSort(int a[],int n)
{
	int i,j,temp;
	
	for(i=1;i<n;i++)
	{
		temp=a[i];
		
		for(j=i-1;j>=0 && a[j]>temp;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
	printf("\nThe elements after sorting are : ");
	
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
