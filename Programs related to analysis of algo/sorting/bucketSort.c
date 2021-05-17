#include <string.h>
#include <stdio.h>
#include <time.h> 

int cmp(float *a, float *b) 
{
   return a>b;
}

void bucketSort(float a[],int n)
{
	float bucket[n][n/10000];
	int count[n];
	memset(count,0,sizeof(count));
	int i;
	//Storing elements in bucket
	for(i=0;i<n;i++)
	{
		int bi=n*a[i];
		bucket[bi][count[bi]]=a[i];
		count[bi]++;
	}
	for(i=0;i<n;i++)
	{
		int l=count[i];
		qsort(bucket[i],l,sizeof(float),cmp); //Sort each bucket
	}
	int k=0,j;
	for(i=0;i<n;i++)
	{
		int l=count[i];
		for(j=0;j<l;j++)
		{
			a[k++]=bucket[i][j];
		}
	}
}

//to reverse the elements of the array
void reverseArray(float arr[], int start, int end)
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
	int r,i,temp,digits=0;
   time_t t;
   clock_t time_req;

   int n = 10000; //input size that increases
   // creating file pointer to work with files
    FILE *fptr;

    // opening file in writing mode
    fptr = fopen("C:/Users/HP/Desktop/Assignments/Analysis of Algorithms/Assignment-4/bucketSort.txt", "w");
    fprintf(fptr, "#Input Size       Avg    Best            Worst        (time in sec)");
   fprintf(fptr, "\n");
   printf("Input Size\tAverage Case\tBest Case\tWorst Case\t(time in seconds)\n");
	while(n<=100000)
	{
	float a[n]; //data to be sorted
   
   //Intializes random number generator 
   srand((unsigned) time(&t));

   // store 10000 random numbers in the array
   for( i = 1 ; i <= n ; i++ ) {
		a[i] = rand();
   }
   
   r=a[0];
   //finding maximum element in the array
    for(i=1;i<n;i++)
    if(a[i]>r)
    r=a[i];

   //average case due to random data
   time_req = clock();
   bucketSort(a,n);
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
   bucketSort(a,n);
   time_req = clock() - time_req;
   
   printf("%f\t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "%f \t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "\t");
      
   //reversing sorted array for worst case
   reverseArray(a,1,n);
   
   //for worst case, giving already sorted array to algorithm
   time_req = clock();
   bucketSort(a,n);
   time_req = clock() - time_req;
   
   printf("%f\n", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "%f \t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "\n");
      
   n += 10000;   
   }
   
    fclose(fptr);    
    
	return 0;
}
