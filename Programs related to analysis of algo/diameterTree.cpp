#include<bits/stdc++.h>
#define int long long
using namespace std;

int vis[200001];
vector<int>adj[2000001];
int maxD,maxnode;

void dfs(int src,int d)
{
    vis[src]=1;
    
    if(d>maxD)
    maxD=d;
    maxnode=src;
    
    for(int child: adj[src])
    {
        if(vis[child]==0)
        dfs(child,d+1);
    }
 
}

signed main()
{
	int n;
	cin>>n;
    memset(vis,0,sizeof(vis));
    
	for(int i=1;i<n;i++)
	{
	    int a,b;
	    cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    maxD=-1;
    dfs(1,0);
    
    memset(vis,0,sizeof(vis));
    maxD=-1;
    dfs(maxnode,0);
    
    cout<<maxD<<endl;
	return 0;
}
