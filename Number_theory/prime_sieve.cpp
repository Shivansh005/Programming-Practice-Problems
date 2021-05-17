#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int isPrime[1000001];

void sieve()   // O(N.log(logn))
{
	ll maxN=1000000;
	
	for(int i=1;i<=maxN;i++) isPrime[i]=1;
	
	isPrime[0]=isPrime[1]=0;
	
	for(ll i=2;i*i<=maxN;i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i;j<=maxN;j+=i)
				isPrime[j]=0;
		}
	}
}

int main()
{
	sieve();
	
	ll t;
	cin>>t;
	
	while(t--)
	{
		ll n;
		cin>>n;
		
		if(isPrime[n]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
