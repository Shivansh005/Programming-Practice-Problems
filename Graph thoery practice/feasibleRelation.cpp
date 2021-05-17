#include<bits/stdc++.h>

using namespace std;

vector<int>ar[100001];
pair<int,int>p;

vector<pair<int,int>>edgeList;
int vis[100001],cc[100001];
int curr_cc=0;

void dfs(int n)
{
	vis[n]=1;
	cc[n]=curr_cc;
	
	for(int child : ar[n])
	{
		if(vis[child]==0)
			dfs(child);
	}
}

int main()
{
	int t,n,m,a,b;
	string op;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		
		for(int i=1;i<=n;i++)
		{
			ar[i].clear();
			vis[i]=0;
		}
	
	
	for(int i=1;i<=m;i++)
	{
		cin>>a>>op>>b;
		
		if(op=="=")
		{
			ar[a].push_back(b);
			ar[b].push_back(a);
		}
		
		else
		{
			edgeList.push_back(make_pair(a,b));
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			curr_cc++;
			dfs(i);
		}
	}

	for(int i=0;i<edgeList.size();i++)
	{
		int p=edgeList[i].first;
		int q=edgeList[i].second;
		
		bool flag=true;
		
		if(cc[p]==c[q])
		{
			flag=false;
			break;
		}
	}
	
	if(flag)
	cout<<"YES\n";
	
	else
	cout<<"NO\n";
	}
}
