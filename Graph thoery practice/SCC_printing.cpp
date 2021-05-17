#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int>adj[10001],tr[10001];
int vis[10001];
vector<int> order,scc;

void dfs1(int src)
{
    vis[src]=1;
    
    for(int x: adj[src])
    {
        if(vis[x]==0)
            dfs1(x);
    }
    
    order.push_back(src);
}

void dfs2(int src)
{
    vis[src]=1;
    
    for(int x: tr[src])
    {
        if(vis[x]==0)
            dfs2(x);
    }
    
    scc.push_back(src);
}


int main() {
	// your code goes here
    int n,m;
    cin>>n>>m;
    
    memset(vis,0,sizeof(vis));
    
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        
        adj[a].push_back(b);
        tr[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dfs1(i);
    }
    
    for(int i=1;i<=n;i++)
        vis[i]=0;
    
    
    for(int i=1;i<=n;i++)
    {
        if(vis[order[n-i]]==0)
        {
            scc.clear();
            dfs2(order[n-i]);
            
            cout<<"SCC->"<<order[n-i]<<": ";
            
            for(int x: scc)
            cout<<x<<' ';
            cout<<endl;
        }
        
    }
	return 0;
}

