#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	int n,m;
	int u,v;
	while(t--)	{
		cin>>n>>m;
		for(int i=0;i<m;i++)	{
			cin>>u>>v;
		}
		if(n%2==0)	{
			cout<<"yes\n";
		}
		else	{
			cout<<"no\n";
		}
	}
	return 0;
}