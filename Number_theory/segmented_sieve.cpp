#include<bits/stdc++.h>
using namespace std;

vector<int>primes;

void sieve(int maxN)
{
	int isPrime[maxN+1];
	for(int i=1;i<=maxN;i++)
	isPrime[i]=1;
	
	isPrime[0]=isPrime[1]=0;
	
	for(int i=2;i<=maxN;i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i;j<=maxN;j+=i)
			isPrime[j]=0;
		}
	}
		
		for(int i=1;i<=maxN;i++)
		if(isPrime[i])
		primes.push_back(i);
}

void init(int l,int r)
{
	if(l==1) l++;
	
	int maxN=r-l+1;
	vector<int>ar(maxN,0);
	
	for(int i=0;i<primes.size();i++)
	{
		int p=primes[i];
		if(p*p<=r)
		{
			int i=(l/p)*p;
			
			if(i<l) i+=p;
			
			for(;i<=r;i+=p)
			{
				if(i!=p)
				ar[i-l]=1;
			}
		}
	}
	
	for(int i=0;i<maxN;i++)
	{
		if(ar[i]==0)
		cout<<(l+i)<<endl;
	}
}
int main(){
	
	int l,r;
	cin>>l>>r;
	
	sieve(100000);
	
	init(l,r);
}
