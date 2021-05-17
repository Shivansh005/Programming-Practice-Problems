#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[200001][2];
vector<int>adj[2000001];

void dfs(int src,int par)
{
int leaf=1;
dp[src][1]=0;
dp[src][0]=0;

	for(int child : adj[src])
	{
		if(child!=par)
		{
		    leaf=0;
		    dfs(child,src);
		}
	}
	
	if(leaf==1) return;
	
	for(auto child: adj[src])
	{
               if(child!=par)
               {
                dp[src][0]+=max(dp[child][0],dp[child][1]);

               }
        }

        for(auto child: adj[src])
        {
            if(child!=par) 
            {
                 dp[src][1]=max(dp[src][1],1+ dp[child][0]+( dp[src][0]-max(dp[child][0],dp[child][1])));
        }
        }


}

signed main()
{
	int n,count=0;
	cin>>n;

	for(int i=1;i<n;i++)
	{
	    int a,b;
	    cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1,0);

    cout<<max(dp[1][0],dp[1][1])<<endl;
	return 0;
}
