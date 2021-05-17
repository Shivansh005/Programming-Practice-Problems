#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll phi(ll n) // O(sqrt(n))
{
	ll res=n;
	
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			res/=i;
			res*=(i-1);
			
			while(n%i==0)
			n/=i;
		}
	}
	
	if(n>1)
	res*=(n-1), res/=n;
	
	return res;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		ll n;
		cin>>n;
		
		cout<<phi(n)<<endl;
	}
	return 0;
}
