#include <bits/stdc++.h>
using namespace std;
struct node	{
	int val;
	int pos;
}arr[10100];
int inp[10100];
int main()	{
	int n,m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);   
	cin>>n>>m;
	for(int i=0;i<n;i++)	{
		cin>>inp[i];
	}
	int l,r,x;
	int prev;
	int ctr;
	for(int i=0;i<m;i++)	{
		cin>>l>>r>>x;
		l--;r--;x--;
		prev=inp[x];
		ctr=0;
		for(int j=l;j<=r;j++)	{
			if(inp[j]<prev)	{
				ctr++;
			}
		}
		if(x-l==ctr)	{
			cout<<"Yes\n";
		}
		else	{
			cout<<"No\n";
		}
	}
	return 0;
}