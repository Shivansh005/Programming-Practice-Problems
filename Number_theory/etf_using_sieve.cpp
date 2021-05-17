#include<bits/stdc++.h>
using namespace std;

int phi[100001];

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
		int k;
		cin>>k;
		
		cout<<phi[k]<<endl;
	}
	return 0;
}
