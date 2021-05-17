#include<bits/stdc++.h>

using namespace std;

vector<int>ar[10001];
int vis[10001],in[10001],low[10001];
set<int>AP;
int timer=0;

void dfs(int node,int par)
{
	vis[node]=1;
	in[node]=low[node]=timer++;
	
	int child_count=0;
	
	for(int child : ar[node])
	{
		if(child==par)
		continue;
		
		if(vis[child]==1)
		{
			low[node]=min(low[node],in[child]);
		}	
			
			else
			{
				dfs(child,node);
				child_count++;
				low[node]=min(low[node],low[child]);
				
				if(low[child]>=in[node]  && par!=-1)
				AP.insert(node);
			}
	}
	if(par==-1 && child_count>1)
	AP.insert(node);
	
	cout<<"Number of articulation points : ";
	cout<<AP.size()<<endl;	
	cout<<"These are : ";
	
	for(int child : AP)
	cout<<child<<" ";
	cout<<endl;
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
	
	return 0; 
}
