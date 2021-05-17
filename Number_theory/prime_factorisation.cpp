#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

void prime_factor(ll n) //O(sqrt(n))
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int count=0;
			while(n%i==0)
			{
				n/=i;
				count++;
			}
			cout<<i<<"^"<<count<<"*";
		}
	}
	if(n>1)
	cout<<n<<"^"<<1<<endl;
}

int main()
{
	ll t;
	cin>>t;
	
	while(t--){
		
		ll n;
		cin>>n;
		
		prime_factor(n);
	}
	return 0;
}
