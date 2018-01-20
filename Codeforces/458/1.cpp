#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	int ans=-1e9;
	int v;
	for(int i=0;i<n;i++)	{
		cin>>v;
		if(v>=0)	{
			int c=sqrt(v);
			if(c*c!=v)	{
				ans=max(ans,v);
			}
		}
		else	{
			ans=max(ans,v);
		}
	}
	cout<<ans<<endl;
	return 0;
}