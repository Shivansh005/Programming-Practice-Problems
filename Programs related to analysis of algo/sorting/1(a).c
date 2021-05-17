
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
	
	bubbleSort(a,n);
}

//code for bubble sort of the list of given data

void bubbleSort(int a[],int n)
{
	int i,j,temp;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			//Checking each alternate elements and swap if needed
			  
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	//Printing the data after sorting 
	
	printf("After sorting the elements of the list are : ");
	
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
