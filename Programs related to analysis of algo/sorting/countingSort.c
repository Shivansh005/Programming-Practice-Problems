
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void countingSort(int a[],int b[],int cnew[],int n)
{
	//sorting to get the final result
    int i;
    for(i=n;i>0;i--)
   {
       b[cnew[a[i]]]=a[i];
        cnew[a[i]]--;
   }
   
   //printing the data values
   
    for(i=1;i<=n;i++)
    {
    	a[i]=b[i];
	}
	
	for(i=1;i<=n;i++)
    {
    	printf("%d ",a[i]);
	}
}

//to reverse the elements of the array
void reverseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }   
}     

int main()
{
	int r,i,sum;
   time_t t;
   clock_t time_req;

   int n = 10000; //input size that increases
   // creating file pointer to work with files
    FILE *fptr;

    // opening file in writing mode
    fptr = fopen("C:/Users/HP/Desktop/Assignments/Analysis of Algorithms/Assignment-3/countingSort.txt", "w");
    fprintf(fptr, "#Input Size       Avg    Best            Worst        (time in sec)");
   fprintf(fptr, "\n");
   printf("Input Size\tAverage Case\tBest Case\tWorst Case\t(time in seconds)\n");
	while(n<=100000)
	{
	int a[n],b[n]; //data to be sorted
   
   //Intializes random number generator 
   srand((unsigned) time(&t));

   // store 10000 random numbers in the array
   for( i = 1 ; i <= n ; i++ ) {
		a[i] = rand();
   }
   
   r=a[1];
    
    //finding maximum element in the array
    for(i=1;i<=n;i++)
    if(a[i]>r)
    r=a[i];
    
    int c[r+1],cnew[r+1];
    
	//initialisation
    
    for(i=0;i<r+1;i++)
    c[i]=0;
    
    //calculating frequency of each element
    
    for(i=1;i<=n;i++)
    ++c[a[i]];
    
    cnew[0]=c[0];
    sum=c[0];
    
    for( i=1;i<r+1;i++)
    {
        cnew[i]=sum+c[i];
        sum=cnew[i];
    }
    
   //average case due to random data
   time_req = clock();
   countingSort(a,b,cnew,n);
   time_req = clock() - time_req;
   
   printf("%d\t\t", n);
   fprintf(fptr, "%d", n);
   fprintf(fptr, "\t");
   
   //calculating total time for sorting algorithm
   printf("%f\t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "%f \t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "\t");
   
   //for best case, giving already sorted array to algorithm
   time_req = clock();
   countingSort(a,b,cnew,n);
   time_req = clock() - time_req;
   
   printf("%f\t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "%f \t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "\t");
      
   //reversing sorted array for worst case
   reverseArray(a,1,n);
   
   //for worst case, giving already sorted array to algorithm
   time_req = clock();
   countingSort(a,b,cnew,n);
   time_req = clock() - time_req;
   
   printf("%f\n", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "%f \t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "\n");
      
   n += 10000;   
   }
   
    fclose(fptr);    
    
    return 0;
}
