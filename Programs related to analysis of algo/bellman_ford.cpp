#include<bits/stdc++.h>
#define inf 100000
#define int long long
using namespace std;

int v,e;
vector< pair<int,int> >adj[100];

void printarr(int dis[])
{
	cout<<"Vertex distance from source\n";
	
	for(int i=1;i<=v;i++)
	{
		cout<<i<<" "<<dis[i]<<endl;
	}
}

void bellman(int src)
{
	int dis[v+1];
	
	for(int i=1;i<=v;i++)
		dis[i]=inf;
		
		dis[src]=0;
		
		for(int i=2;i<=v;i++)
		{
			for(int j=1;j<=e;j++)
			{
				int u=j;
				for(auto x: adj[u])
				{
				int v=x.first;
				int w=x.second;
				
				if(dis[u]!=inf && dis[u]+w<dis[v])
					dis[v]=dis[u]+w;
				}
			}
		}
		
		for(int j=1;j<=e;j++)
			{
				int u=j;
				
				for(auto x: adj[u])
				{
				int v=x.first;
				int w=x.second;
				
				if(dis[u]!=inf && dis[u]+w<dis[v])
					{
						cout<<"Negative cycle present"<<endl;
						return;
					}	
				}
			}
			
			printarr(dis);
		
}

signed main()
{
	cin>>v>>e;
	
	for(int i=0;i<e;i++)
	{
		cout<<"Enter the source, destination and weight of edge "<<i+1<<" :";
		int u,v,w;
		cin>>u>>v>>w;
		
		adj[u].push_back({v,w});
	}
	
	bellman(1);
}
