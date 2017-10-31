#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long a,b;
	cin>>a>>b;
	long long g=__gcd(a,b);
	long long l=a*b;
	l/=g;
	if(b>a)	{
		long long b1=l/b;
		long long a1=l/a;
		a1--;
		if(a1>b1)	{
			cout<<"Dasha\n";
		}
		if(a1<b1)	{
			cout<<"Masha\n";
		}
		if(a1==b1)	{
			cout<<"Equal\n";
		}
	}
	if(b<a)	{
		long long b1=l/b;
		long long a1=l/a;
		b1--;
		if(a1>b1)	{
			cout<<"Dasha\n";
		}
		if(a1<b1)	{
			cout<<"Masha\n";
		}
		if(a1==b1)	{
			cout<<"Equal\n";
		}
	}
	return 0;
}