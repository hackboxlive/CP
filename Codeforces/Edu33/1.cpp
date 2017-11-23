#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	int f=1;
	int s=2;
	int t=3;
	int v;
	while(n--)	{
		cin>>v;
		if(v==t)	{
			cout<<"NO\n";
			return 0;
		}
		if(v==f)	{
			swap(s,t);
		}
		else	{
			swap(f,t);
		}
	}
	cout<<"YES\n";
	return 0;
}