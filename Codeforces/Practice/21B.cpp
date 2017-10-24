#include <bits/stdc++.h>
using namespace std;
int main()	{
	int a,b,c,x,y,z;
	cin>>a>>b>>c>>x>>y>>z;
	int g1=__gcd(a,x);
	int g2=__gcd(b,y);
//	int g3=1;
	int g3=__gcd(c,z);
	a=a/g1;
	b=b/g2;
	c=c/g3;
	x=x/g1;
	y=y/g2;
	z=z/g3;
	if((a==b && x==y) && (b==c && y==z))	{
		cout<<"-1\n";
	}
	if((a==b && x==y) && (b!=c || y!=z))	{
		cout<<"-1\n";
	}
	cout<<"1\n";	
	return 0;
}