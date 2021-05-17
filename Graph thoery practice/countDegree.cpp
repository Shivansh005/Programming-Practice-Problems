#include<bits/stdc++.h>

using namespace std;

vector<int>ar[10001];

int main()
{
	int t,n,m,a,b;
	cout<<"Enter number of test cases : ";
	cin>>t;
	
	while(t--)
	{
		cout<<"\nEnter no. of vertices : ";
		cin>>n;
		
		cout<<"\nEnter no. of edges : ";
		cin>>m;
		
		for(int i=1;i<=n;i++)
		{
			ar[i].clear();
		}

		
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b;
			ar[a].push_back(b);
			ar[b].push_back(a);
		}
		
		for(int i=1;i<=n;i++)
		{
			cout<<"\nDegree of vertex -  "<< i<<" is : "<<ar[i].size();
		}
	}
}
