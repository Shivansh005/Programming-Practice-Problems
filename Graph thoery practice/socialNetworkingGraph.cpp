#include<bits/stdc++.h>

using namespace std;

vector<int>ar[10001];
int vis[10001],dist[10001],level[10001];

void bfs(int src)
{
	queue<int>q;
	q.push(src);
	vis[src]=1;
	dist[src]=0;
	
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		
		for(int child : ar[curr])
		{
			if(vis[child]==0)
			{
				dist[child]=dist[curr]+1;
				q.push(child);
				vis[child]=1;
				level[dist[child]]++;	
			}	
		}	
	}	
}

int main()
{
	int q,n,m,a,b,src,d;
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		
		for(int i=0;i<m;i++)
		{
			ar[a].push_back(b);
			ar[b].push_back(a);
		}
	}
	
	cin>>q;

	while(q--)
	{	
	cin>>src>>d;
	
		for(int i=0;i<n;i++)
		{
			vis[i]=0;
			level[i]=0;	
		}
		
		bfs(src);
		
		cout<<level[d]<<endl;	
	}
	return 0;
}
