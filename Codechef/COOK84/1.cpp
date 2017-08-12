#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int a,n;
		cin>>n;
		int ans=0;
		for(int i=0;i<n;i++)	{
			cin>>a;
			ans=ans|a;
		}
		cout<<ans<<endl;
	}
	return 0;
}