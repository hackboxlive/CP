#include <bits/stdc++.h>
using namespace std;
long long arr[150100];
int main()	{
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++)	{
		cin>>arr[i];
	}
	map<long long,set<long long> > mp;
	for(long long i=0;i<n;i++)	{
		mp[arr[i]].insert(i);
	}
	for(auto it=mp.begin();it!=mp.end();it++)	{
		while((it->second).size()>1)	{
			auto first_it=(it->second).begin();
			auto second_it=(it->second).begin();
			second_it++;
			mp[2*(it->first)].insert(*second_it);
			(it->second).erase(first_it);
			(it->second).erase(second_it);
		}
	}
	memset(arr,0,sizeof(arr));
	for(auto it=mp.begin();it!=mp.end();it++)	{
		for(auto it2=(it->second).begin();it2!=(it->second).end();it2++)	{
			arr[*it2]=it->first;
		}
	}
	vector<long long> vv;
	long long aa=0;
	for(long long i=0;i<n;i++)	{
		if(arr[i]!=0)	{
			vv.push_back(arr[i]);
			aa++;
		}
	}
	cout<<aa<<endl;
	for(long long i=0;i<vv.size();i++)	{
		cout<<vv[i]<<" ";
	}
	cout<<endl;
	return 0;
}