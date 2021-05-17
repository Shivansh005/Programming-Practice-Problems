// ax + by = c              Linear Diophantine Equation

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b, int & x, int & y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	
	int x1,y1;
	
	int d=gcd(b,a%b,x1,y1);
	x=y1;
	y=x1 - y1* (a/b);
	
	return d;
}

int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c;
	
	if(a==0 && b==0)
	{
		if(c==0)
		cout<<"INFINITY"<<endl;
		
		else
		cout<<0<<endl;
	}
	
	else{
		int GCD=gcd(a,b,x,y);
	
	x=x*(c/GCD);
	y=y*(c/GCD);
	
	cout<<"The value of x and y is  : ";
	cout<<a<<" * "<<x<<" + "<<b<<" * "<<y<<" = "<<c<<endl;
	}
	
	return 0;
}

