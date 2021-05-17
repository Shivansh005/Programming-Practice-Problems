#include<bits/stdc++.h>
#define int long long
using namespace std;

int vis[200001];
vector<int>adj[2000001];

int dfs(int src,int d,int target)
{
    vis[src]=1;
   
    for(int child: adj[src])
    {
        if(vis[child]==0)
       {
         if(child==target)
           return d;
           
         d=dfs(child,d+1,target);
         
        }
    }
 return d;
}

signed main()
{
	int n,q;
	cin>>n>>q;
    memset(vis,0,sizeof(vis));
    
	for(int i=1;i<n;i++)
	{
	    int a,b;
	    cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    
    while(q--)
    {
        int a,b;
        cin>>a>>b;
            memset(vis,0,sizeof(vis));

       cout<<dfs(a,0,b)<<endl;
    }

	return 0;
}
