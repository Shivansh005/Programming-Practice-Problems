#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int I[10001][10001];
int a[10001][10001];
int N=10001;

void power(int I[][10001], int a[][10001], int m)
{
	int res[m+1][m+1];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			res[i][j]=0;
			for(int k=1;k<=m;k++)
			{
				res[i][j]+=I[i][k]*a[k][j];
			}
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			I[i][j]=res[i][j];
	}
}

void mat(int n,int m)
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
		if(i==j)I[i][j]=1;
		
		else
		I[i][j]=0;	
		}
	}
	
	while(n)
	{
		if(n%2==1)
			power(I,a,m), n--;
			
		else
			power(a,a,m), n/=2;
	}
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	
	mat(n,m);
	cout<<"matrix a (order m) to the power n equals--> "<<endl;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
	return 0;
}
