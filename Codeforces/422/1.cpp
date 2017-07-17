#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long a,b;
	cin>>a>>b;
	if(a>b)	{
		swap(a,b);
	}
	long long ff=1;
	for(long long i=1;i<=a;i++)	{
		ff=ff*i;
	}
	cout<<ff;
	return 0;
}