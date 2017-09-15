#include <bits/stdc++.h>
using namespace std;
vector<int> tree[100100];
int tr[100100];
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,k;
		cin>>n>>k;
		int v;
		for(int i=2;i<=n;i++)	{
			cint<<v;
			tree[i].push_back(v);
			tree[v].push_back(i);
		}
		int x;
		for(int i=0;i<k;i++)	{
			cin>>v;
			for(int j=0;j<v;j++)	{
				cin>>x;
				tr[x]=j;
			}
		}
	
