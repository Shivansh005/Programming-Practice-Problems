#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--){
		string s;
		cin>>s;
		
		int n=s.length();
		
		int dp[n+1][n+1];
		
		memset(dp,0,sizeof(dp));
		
		for(int i=0;i<=n;i++)
			dp[0][i]=dp[1][i]=1;
			
		for(int i=2;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(s[j-1]==s[j-i] && dp[i-2][j-1]==1)
				dp[i][j]=1;
				
				else
				dp[i][j]=0;
			}
		}
		
		for(int i=0;i<=n;i++)
			{
			for(int j=0;j<=n;j++)
				cout<<dp[i][j]<<' ';
				cout<<endl;	
			}
	}
	return 0;
}
