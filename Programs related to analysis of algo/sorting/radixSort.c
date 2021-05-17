
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//function for counting Sort
void countingSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = { 0 }; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
   
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i];
        

}

//function for radix sort
void radixSort(int a[], int n, int max)
{
	int exp;
	for(exp=1;max/exp>0;exp*=10)
	{
		countingSort(a,n,exp);
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
	int r,i,temp,digits=0;
   time_t t;
   clock_t time_req;

   int n = 10000; //input size that increases
   // creating file pointer to work with files
    FILE *fptr;

    // opening file in writing mode
    fptr = fopen("C:/Users/HP/Desktop/Assignments/Analysis of Algorithms/Assignment-3/radixSort.txt", "w");
    fprintf(fptr, "#Input Size       Avg    Best            Worst        (time in sec)");
   fprintf(fptr, "\n");
   printf("Input Size\tAverage Case\tBest Case\tWorst Case\t(time in seconds)\n");
	while(n<=100000)
	{
	int a[n]; //data to be sorted
   
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
   radixSort(a,n,r);
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
   radixSort(a,n,r);
   time_req = clock() - time_req;
   
   printf("%f\t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "%f \t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "\t");
      
   //reversing sorted array for worst case
   reverseArray(a,1,n);
   
   //for worst case, giving already sorted array to algorithm
   time_req = clock();
   radixSort(a,n,r);
   time_req = clock() - time_req;
   
   printf("%f\n", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "%f \t", (double)time_req/CLOCKS_PER_SEC);
   fprintf(fptr, "\n");
      
   n += 10000;   
   }
   
    fclose(fptr);    
    
    return 0;
}
