#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int>vis(200001,0);
vector<int>subsize(200001,0);
vector<int>adj[2000001];

int dfs(int src)
{
	vis[src]=1;
	int cur=1;
	for(int child : adj[src])
	{
		if(vis[child]==0)
		cur+=dfs(child);
	}
	
	return subsize[src]=cur;
}

signed main()
{
	int n;
	cin>>n;
	
	int par[n+1];
	
	for(int i=2;i<=n;i++)
	cin>>par[i];
	
	vector<int>count(200001,0);

	for(int i=2;i<=n;i++)
	{
		adj[par[i]].push_back(i);
	}

	dfs(1);
	
	for(int i=1;i<=n;i++)
	cout<<subsize[i]-1<<endl;
	return 0;
}

