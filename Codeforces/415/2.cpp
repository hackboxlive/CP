#include <bits/stdc++.h>
using namespace std;
long long k[100100];
long long l[100100];
vector<long long> extras;
bool comp(const long long &p1,const long long &p2)	{
	return p1>p2;
}
int main()	{
	int n,f;
	cin>>n>>f;
	for(int i=0;i<n;i++)	{
		cin>>k[i]>>l[i];
	}
	long long curtot=0;
	for(int i=0;i<n;i++)	{
		curtot+=min(k[i],l[i]);
	}
	long long ee;
	for(int i=0;i<n;i++)	{
		if(k[i]<l[i])	{
			if(2*k[i]<=l[i])	{
				ee=k[i];
			}
			else	{
				ee=l[i]-k[i];
			}
			extras.push_back(ee);
		}
	}
	sort(extras.begin(),extras.end(),comp);
	for(int i=0;i<min(f,(int)extras.size());i++)	{
		curtot+=extras[i];
	}
	cout<<curtot<<endl;
	return 0;
}