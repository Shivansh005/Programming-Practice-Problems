#include <stdio.h>
#include <string.h>
#include <limits.h> 
int dp[101][101];

int chain_mul(int arr[],int i,int j)
{
	if(i==j)
	   return 0;
	if(dp[i][j]!=-1)
	   return dp[i][j];
	dp[i][j]=INT_MAX;
	int k;
	for(k=i;k<j;k++)
	{
		int curr=chain_mul(arr,i,k)+chain_mul(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
		dp[i][j]=dp[i][j]<curr?dp[i][j]:curr;
    }      
    return dp[i][j];
}
int main()
{
    int n,i;
    memset(dp,-1,sizeof(dp));
    printf("Enter size of dimension array:");
	scanf("%d",&n);
	int arr[n];
	printf("Array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Minimum number of multiplications is :%d",chain_mul(arr,1,n-1));
	return 0;
}    
