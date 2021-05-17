#include<bits/stdc++.h>

using namespace std;

vector<int>ar[100001];
int in[100001];
vector<int>res;

void kahn(int n)
{
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		q.push(i);
	}
	
	while(!q.empty())
	{
		int curr=q.front();
		res.push_back(curr);
		q.pop();
		
		for(int child : ar[curr])
		{
			in[child]--;
			if(in[child]==0)
			q.push(child);
		}
	}
	cout<<"Topo sort : ";
	
	for(int node : res)
	cout<<node<<" "; 
}
int main()
{
	int n,m,a,b;
	
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		
		ar[a].push_back(b);
		in[b]++;
	}
	
	kahn(n);
	return 0;
	
}
