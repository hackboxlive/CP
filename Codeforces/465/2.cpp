#include <bits/stdc++.h>
using namespace std;

int main()	{
	string s;
	int n;
	cin>>n;
	cin>>s;
	int ans=0;
	int prev=0;
	int curx=0;
	int cury=0;
	for(int i=0;i<n;i++)	{
		if(s[i]=='U')	{
			cury++;
		}
		else	{
			curx++;
		}
		if(prev==1 && cury>curx)	{
			ans++;
		}
		if(prev==2 && cury<curx)	{
			ans++;
		}
		if(cury>curx)	{
			prev=2;
		}
		if(cury<curx)	{
			prev=1;
		}
		//cout<<prev<<" "<<curx<<" "<<cury<<endl;
	}
	cout<<ans<<endl;
	return 0;
}