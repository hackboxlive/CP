#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,p;
		cin>>n>>p;
		if(p==1 || p==2)	{
			cout<<"impossible\n";
			continue;
		}
		string a="a";
		for(int i=1;i<p-1;i++)	{
			a+="b";
		}
		a+="a";
		string ans="";
		for(int i=0;i<n/p;i++)	{
			ans+=a;
		}
		cout<<ans<<endl;
	}
	return 0;
}