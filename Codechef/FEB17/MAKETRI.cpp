#include <bits/stdc++.h>
using namespace std;
vector<long long int> strands;
vector<pair<long long int,long long int> > range;
bool comp(const pair<long long int,long long int> &p1,const pair<long long int,long long int> &p2)	{
	if(p1.first==p2.first)	{
		return p1.second<p2.second;
	}
	return p1.first<p2.first;
}
int main()	{
	long long int n,l,r;
	long long int li,ri;
	scanf("%lld%lld%lld",&n,&l,&r);
	for(int i=0;i<n;i++)	{
		scanf("%lld",&li);
		strands.push_back(li);
	}
	sort(strands.begin(),strands.end());
	for(int i=0;i<n-1;i++)	{
		li=strands[i+1]-strands[i]+1;
		li=max(li,l);
		ri=strands[i+1]+strands[i]-1;
		ri=min(ri,r);
		if(li<=ri)	{
			range.push_back(make_pair(li,ri));
		}
	}
	sort(range.begin(),range.end(),comp);
	long long int ctr=0;
	li=range[0].first;
	ri=range[0].second;
	ctr=ri-li+1;
	for(int i=1;i<range.size();i++)	{
		if(range[i].first>ri)	{
			li=range[i].first;
			ri=range[i].second;
			ctr+=ri-li+1;
			continue;
		}
		if(range[i].second>ri)	{
			ctr+=(range[i].second-ri);
			ri=range[i].second;
			continue;
		}
	}
	printf("%lld\n",ctr);;
	return 0;
}