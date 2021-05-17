#include<bits/stdc++.h>

using namespace std;

vector<int>ar[100001];

int visited[100001];

void dfs(int node)
{
	visited[node]=1;
	
	for(int child : ar[node])
	{
		if(!visited[child])
		dfs(child);
	}	
}

int main()
{
	int n,m,a,b;
	
	cin>>n>>m;
	
	for(int i=1;i<=100001;i++)
	visited[i]=0;
	
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	
	int cc_count=0;
	
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			dfs(i);
			cc_count++;
		}
	}
	cout<<cc_count;
}

