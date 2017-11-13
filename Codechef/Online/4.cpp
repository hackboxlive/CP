#include <bits/stdc++.h>
using namespace std;
pair<long long,long long> a[500500];
bool comp(const pair<long long,long long> &p1, const pair<long long,long long> &p2)	{
	return p1.first<p2.first;
}
int main()	{
	int t;
	long long n;
	scanf("%d",&t);
	while(t--)	{
		scanf("%lld",&n);
		for(int i=0;i<n;i++)	{
			scanf("%lld",&a[i].first);
		}
		long long bm=1LL<<60;
		for(int i=0;i<n;i++)	{
			scanf("%lld",&a[i].second);
			bm=min(a[i].second,bm);
		}
		long long ans=0;
		for(int i=0;i<n;i++)	{
			a[i].first%=a[i].second;
			if(a[i].first>=bm)	{
				ans+=(a[i].second-a[i].first);
				a[i].first=0;
			}
		}
		sort(a,a+n,comp);
		long long minn=0;
		vector<int> dis;
		dis.push_back(0);
		long long summ=a[0].second;
		vector<long long> bb;
		for(int i=1;i<n;i++)	{
			if(a[i].first!=a[i-1].first)	{
				dis.push_back(i);
				bb.push_back(summ);
				summ=a[i].second;
			}
			else	{
				summ+=a[i].second;
			}
		}
		bb.push_back(summ);
		for(int i=1;i<n;i++)	{
			if(a[i].first!=a[0].first)	{
				minn+=(a[i].second-(a[i].first-a[0].first));
			}
		}
		long long temp=minn;
		long long fin=minn;
		for(int i=1;i<dis.size();i++)	{
			temp+=(n*(a[dis[i]].first-a[dis[i-1]].first));
			temp-=bb[i];
			fin=min(temp,fin);
		}
		ans=ans+fin;
		printf("%lld\n",ans);
	}
	return 0;
}