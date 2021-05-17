#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll power(ll a, ll n)  // O(logn)
{
	ll res=1;
	while(n)
	{
		if(n%2==1)
		res=((res%mod) * (a%mod))%mod, n--;
		
		else
		{
			a=((a%mod)* (a%mod))%mod;
			n/=2;
		}
		
	}
	return res;
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		ll a,n;
		cin>>a>>n;
		
		cout<<power(a,n)<<endl;
	}
	return 0;
}
