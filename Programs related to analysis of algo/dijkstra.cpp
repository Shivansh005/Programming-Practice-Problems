#include<bits/stdc++.h>

#define inf 1e18;
using namespace std;

vector<vector<pair<int,int>>>adj;

void dijkstra(int s, vector<int>& p, vector<int>& d)
{
	int n=adj.size();
	p.assign(n+1,-1);
	d.assign(n+1,inf);
	vector<bool>u(n+1,false);
	
	d[s]=0;
	
	for(int i=1;i<=n;i++)
	{
		int v=-1;
		
		for(int j=1;j<=n;j++)
		{
			if(!u[j] && (v==-1 || d[j]<d[v]))
			v=j;
		}
		
		if(d[v]==inf)
		break;
		
		u[v]=true;
		
		for(auto edge : adj[v])
		{
			int to=edge.first;
			int len=edge.second;
			
			if(d[v]+len<d[to])
			{
				d[to]=d[v]+len;
				p[to]=v;
			}
		}
	}
	
	for(int i=1;i<n+1;i++)
	cout<<d[i]<<" ";
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<int>p;
	vector<int>d;
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		vector<pair<int,int>>t;
		t.push_back({b,w});
		adj[a].push_back(t);
	}
	
	dijkstra(1,p,d);
	
	for(int i=1;i<n+1;i++)
	cout<<d[i]<<" ";
	return 0;
}
