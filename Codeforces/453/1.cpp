#include <bits/stdc++.h>
using namespace std;

int main()	{
	int n,m;
	cin>>n>>m;
	int f[110]={0};
	int l,r;
	int curx=0,cury=0;
	for(int i=0;i<n;i++)	{
		cin>>l>>r;
		if(l<=cury)	{
			if(r>=cury)	{
				cury=r;
			}
		}
//		cout<<cury<<endl;
	}
	if(m<=cury)	{
		cout<<"YES\n";
	}
	else	{
		cout<<"NO\n";
	}
	return 0;
}