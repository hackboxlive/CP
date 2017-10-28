#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int main()	{
	for(long long i=1;i<=1e5;i++)	{
		a.push_back(i*i);
	}
	int t;
	long long y;
	scanf("%d",&t);
	long long ans;
	int i;
	while(t--)	{
//		cin>>y;
		scanf("%lld",&y);
		ans=0;
		for(i=1;i<=700;i++)	{
			ans+=(upper_bound(a.begin(),a.end(),y-i)-a.begin());
		}
		//cout<<ans<<endl;
	}
	return 0;
}