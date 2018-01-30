#include <bits/stdc++.h>
using namespace std;
int main()	{
	int a,b,c;
	cin>>a>>b>>c;
	int x,y,z;
	if(a<=b && b<=c)	{
		x=a;
		y=b;
		z=c;
	}
	if(a<=c && c<=b)	{
		x=a;
		y=c;
		z=b;
	}
	if(b<=a && a<=c)	{
		x=b;
		y=a;
		z=c;
	}
	if(b<=c && c<=a)	{
		x=b;
		y=c;
		z=a;
	}
	if(c<=a && a<=b)	{
		x=c;
		y=a;
		z=b;
	}
	if(c<=b && b<=a)	{
		x=c;
		y=b;
		z=a;
	}
	if(x==3 && y==3 && z==3)	{
		cout<<"YES\n";
		return 0;
	}
	if(x==1)	{
		cout<<"YES\n";
		return 0;
	}
	if(x==2 && y==2)	{
		cout<<"YES\n";
		return 0;
	}
	if(x==2 && y==4 && z==4)	{
		cout<<"YES\n";
		return 0;
	}
	cout<<"NO\n";
	return 0;
}