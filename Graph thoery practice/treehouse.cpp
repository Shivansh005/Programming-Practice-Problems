#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

vector<ll>ar[300001];
ll value[300001];
ll child[300001];
ll par[300001];
ll ans;

void numberOfNodes(ll s, ll e)
{
    child[s] = 1;
    for (auto it: ar[s]) {
        numberOfNodes(it, s);
        
        child[s] += child[it];
    }
}

void bfs(ll src,ll x)
{
    queue<ll>q;
    q.push(src);

    while(!q.empty())
    {
        priority_queue<pair<ll, ll> >pq; 
        
        while(!q.empty())
        {
            ll curr=q.front();
            q.pop();
            pq.push({child[curr],curr});
        } 
            ll j=1;
            
            while(!pq.empty())
            {
                auto it=pq.top();
                pq.pop();
                
                if(it.second==1)
                value[it.second]=x*j++;
                
                else
                value[it.second]=value[par[it.second]]*j++;
                
                for(int chi: ar[it.second])
                        q.push(chi);
            }
        
    }
}

int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
       ll n,x;
       cin>>n>>x;
     
     ans=0;
     
     for(int i=1;i<=n;i++)
         ar[i].clear();
     
     for(int i=0;i<n-1;i++)
     {
         ll a,b;
         cin>>a>>b;
         ar[a].push_back(b);
         par[b]=a;
     }

     numberOfNodes(1,0);
     bfs(1,x);
        
        for(int i=1;i<=n;i++)
            ans=(ans%mod + value[i]%mod) %mod;
        
        cout<<ans%mod<<endl;
    }
      return 0;
}
    
    
    
    
  
