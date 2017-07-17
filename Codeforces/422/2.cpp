#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s;
	cin>>t;
	int minn=1e9;
	int minpos;
	for(int i=0;i<=m-n;i++)	{
//		cout<<t[i]<<"---t"<<endl;
		//kept s's starting pos at t's ith position
		int cnt=0;
		for(int j=0;j<n;j++)	{
			if(s[j]!=t[i+j])	{
				cnt++;
			}
//			cout<<cnt<<endl;
		}
		if(cnt<minn)	{
			minpos=i;
			minn=cnt;
		}
	}
	cout<<minn<<endl;
	for(int i=0;i<n;i++)	{
		if(s[i]!=t[minpos+i])	{
			cout<<i+1<<" ";
		}
	}
	return 0;
}