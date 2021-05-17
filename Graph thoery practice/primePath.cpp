#include <bits/stdc++.h>
using namespace std;

vector<int>ar[1000001];
vector<int>primes;

int dist[1000001],vis[1000001];


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
        
        for(int child : ar[src])
        {
            if(vis[child]==0)
            {
                vis[child]=1;
                q.push(child);
                dist[child]=dist[curr]+1;
            }
        }
    }
}
bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    if(n%i==0)
    return false;
    
    return true;
}

bool isValid(int a,int b)
{
    int count=0;
    
    while(a>0)
    {
        if(a%10!=b%10)
        count++;
        
        a/=10;
        b/=10;
    }
    if(count==1)
        return true;
        
        return false;
}

void buildGraph()
{
    for(int i=1000;i<=9999;i++)
    {
        if(isPrime(i))
        {
            primes.push_back(i);
        }
    }
    
    for(int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size();j++)
        {
            int a=primes[i];
            int b=primes[j];
            
            if(isValid(a,b))
            {
                ar[a].push_back(b);
                ar[b].push_back(a);
            }
        }
    }
}

int main() {
    int t,a,b;
    cin>>t;
    
    buildGraph();
    
    while(t--)
    {
        cin>>a>>b;
        
        for(int i=1000;i<=9999;i++)
        vis[i]=0;
        
        for(int i=1000;i<=9999;i++)
        {
            dist[i]=-1;
        }
        
        bfs(a);
        
        if(dist[b]==-1)
        cout<<"Impossible"<<endl;
        
        else
        cout<<dist[b]<<endl;
    }
	return 0;
}
