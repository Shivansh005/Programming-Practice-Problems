#include<bits/stdc++.h>

using namespace std;

vector<int>ar[10001];
int vis[10001],dist[10001];

void dfs(int node,int d)
{
	vis[node]=1;
	dist[node]=d;
	
	for(int child : ar[node])
	{
		if(vis[child]==0)
		{
			dfs(child,dist[node]+1);
		}
	}	
}

int main()
{
	int n,m,a,b;
	
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
		{
			cin>>a>>b;
			
			ar[a].push_back(b);
			ar[b].push_back(a);
		}
		
		dfs(3,0);
		
		for(int i=1;i<=n;i++)
		cout<<"\nDistance of "<<i<<" from 3 is : "<<dist[i];
		
	return 0;
	
}
