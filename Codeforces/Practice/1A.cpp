#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long int r,c,a,l1,l2;
	cin>>r>>c>>a;
	if(r%a == 0)	{
		l1=r/a;
	}
	else	{
		l1=r/a + 1;
	}
	if(c%a == 0)	{
		l2=c/a;
	}
	else	{
		l2=c/a +1;
	}
	l1=l1*l2;
	cout<<l1;
	return 0;
}