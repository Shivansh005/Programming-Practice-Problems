#include<bits/stdc++.h>

using namespace std;

vector<int>ar[1001];
int vis[1001];

bool dfs(int node, int par)
{
	vis[node]=1;
	
	for(int child : ar[node])
	{
		if(vis[child]==0)
		{
			if(dfs(child,node))
			return true;
		}
		
		else
		{
			if(child!=par)
			return true;
		}
	}
	return false;
}

int main()
{
	int n,m,a,b;
	bool flag;
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	
	flag=dfs(1,-1);
	
	if(flag)
	cout<<"YES";
	
	else
	cout<<"NO";
	return 0;
}
