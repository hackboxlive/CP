#include <bits/stdc++.h>
using namespace std;

int get_greatest_factor(int n)	{
	int ans=-1;
	while(n%2==0)	{
		ans=2;
		n/=2;
	}

	for(int i=3;i<=sqrt(n);i+=2)	{
		if(n%i==0)	{
			ans=i;
			n/=i;
		}
	}
	if(n>2)	{
		ans=n;
	}
	return ans;
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,k;
		cin>>n>>k;
		int g,temp;
		cin>>g;
		for(int i=1;i<n;i++)	{
			cin>>temp;
			g=__gcd(g,temp);
		}
		int v=get_greatest_factor(g);
		//cout<<v<<endl;
		if(v>k)	{
			cout<<"NO\n";
		}
		else	{
			cout<<"YES\n";
		}
	}
	return 0;
}