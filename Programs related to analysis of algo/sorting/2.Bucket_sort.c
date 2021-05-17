#include <string.h>
#include <stdio.h>
#include <time.h> 
int cmp(float *a, float *b) 
{
   return a>b;
}
void bucket_sort(float a[],int n)
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
int main()
{
	int n=70000;
	float arr[n];
	int i=0;
	char s[30];
	FILE *fptr;
	fptr = fopen("a.txt","r");
	if(fptr==NULL)
	{
		printf("File not found!!");
		return ;
	}
	else
	{
		while(fgets(s,10,fptr)!=NULL) 
	    {
           float x;
           sscanf(s,"%f",&x);
           arr[i]=x;
           i++;
        }
	}
	fclose(fptr);
	clock_t t; 
    t = clock();
	bucket_sort(arr,n);
	t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken in sorting:%.2fs\n",time_taken);
    
    printf("Sorted List:\n");
    for(i=0;i<n;i++)
       printf("%f ",arr[i]);
}
