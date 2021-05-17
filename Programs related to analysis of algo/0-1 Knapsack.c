#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,W,j;
	printf("Enter the value of n:");
	scanf("%d",&n);
	int weights[n],values[n];
	for(i=0;i<n;i++)
	{
		printf("Enter weight of item-%d:",(i+1));
		scanf("%d",&weights[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("Enter value of item-%d:",(i+1));
		scanf("%d",&values[i]);
	}
	printf("\n Enter the capacity W:");
	scanf("%d",&W);
	
	int dp[n+1][W+1];
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=W;j++)
		{
			if(weights[i-1]<=j)
			{
				int curr=values[i-1]+dp[i-1][j-weights[i-1]];
				dp[i][j]=dp[i-1][j]>curr?dp[i-1][j]:curr;
			}
			else
			    dp[i][j]=dp[i-1][j];
		}
	}
	printf("\nThe maximum total value in the knapsack:%d",dp[n][W]);
	return dp[n][W];
}

