#include<bits/stdc++.h>

using namespace std;

vector<int>ar[10001];
int visited[10001];
int color[10001];

bool dfs(int node,int c)
{
	visited[node]=1;
	color[node]=c;
	
	for(int child : ar[node])
	{
		if(visited[child]==0)
		{
			if(dfs(child,c^1)==false)
			return false;
		}
		
		else
		{
			if(color[node]==color[child])
			return false;
		}
	}
	return true;
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
	
	flag=dfs(1,0);
	
	if(flag)
	cout<<"YES";
	
	else
	cout<<"NO";
	
	return 0;
}
