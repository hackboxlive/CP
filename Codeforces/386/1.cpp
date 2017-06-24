#include <bits/stdc++.h>
using namespace std;
int main()	{
	int a,b,c;
	cin>>a>>b>>c;
	b=b/2;
	c=c/4;
	if(a<=b && a<=c)	{
		cout<<a+2*a+4*a;
		return 0;
	}
	if(b<=a && b<=c)	{
		cout<<b+2*b+4*b;
		return 0;
	}
	cout<<c+2*c+4*c;
	return 0;
}