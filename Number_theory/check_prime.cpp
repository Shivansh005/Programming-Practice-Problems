#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

bool checkPrime(ll n)  //O(sqrt(n))
{
	if(n==1) return false;
	
	for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			return false;
		}
		
		return true;
}
int main()
{
	ll t;
	cin>>t;
	
	while(t--)
	{
		ll n;
		cin>>n;
		
		if(checkPrime(n)) cout<<"Yes it is prime"<<endl;
		
		else cout<<"It is not prime"<<endl;
	}
	return 0;
}
