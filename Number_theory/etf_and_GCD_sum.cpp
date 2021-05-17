#include<bits/stdc++.h>
using namespace std;

int phi[100001];

int getCount(int d,int n)
{
	return phi[n/d];
}

void init(int n)
{
	for(int i=1;i<=n;i++)
	phi[i]=i;
	
	for(int i=2;i<=n;i++)
	{
		if(phi[i]==i)
		{
			phi[i]=i-1;
			
			for(int j=i;j<=n;j+=i)
			{
				phi[j]=(phi[j]/i)*(i-1);
			}
		}
	}
}
int main()
{
	init(100000);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int res=0;
		
		for(int i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				int d1=i;
				int d2=n/i;
				
				res+=d1*getCount(d1,n);
				
				if(d1!=d2)
				res+=d2*getCount(d2,n);
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
