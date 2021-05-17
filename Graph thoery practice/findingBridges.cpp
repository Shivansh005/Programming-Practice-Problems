#include<bits/stdc++.h>

using namespace std;

vector<int>ar[10001];
int vis[10001];

int in[10001],low[10001];
int timer=1;

void dfs(int node,int par)
{
	vis[node]=1;
	in[node]=low[node]timer++;
	
	for(int child : ar[node])
	{
		if(child==par)
		continue;
		
		if(vis[child]==1)				//back edge
		{
			low[node]=min(low[node],in[child]);
		}
		
		else							//to check for bridge
		{
			dfs(child,node);
			
			low[node]=min(low[node],low[child]);
			
			if(low[child]>in[node])
			{
				cout<<"There is a bridge between "child<<" and "<<node<<endl;
			}
			else
			{
				cout<<"There is not a bridge between "child<<" and "<<node<<endl;	
			}
			
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
		dfs(1,-1);
}
