#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int binoCoeff(int n,int k)
{
	int C[n+1][k+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(i==j || j==0)
			C[i][j]=1;
			
			else
			C[i][j]=(C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
	
	return C[n][k];
}

int main()
{
	int n,k;
	cin>>n>>k;
	
	cout<<binoCoeff(n,k);
	return 0;
}
