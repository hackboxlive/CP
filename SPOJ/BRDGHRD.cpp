#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[100100];
vector<int> lis;
bool comp(pair<int,int> &p1,pair<int,int> &p2)	{
	if(p1.first!=p2.first)	{
		return p1.first<p2.first;
	}
	return p1.second<p2.second;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i].first);
		}
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i].second);
		}
		sort(arr,arr+n,comp);
		lis.push_back(arr[0].second);
//		lis[0]=arr[0].second;
//		int maxlen=1;
		vector<int>::iterator it;
		for(int i=1;i<n;i++)	{
			it=upper_bound(lis.begin(),lis.end(),arr[i].second);
			if(it==lis.end())	{
				lis.push_back(arr[i].second);
			}
			else	{
				*it=arr[i].second;
			}
		}
		cout<<lis.size()<<endl;
		lis.clear();
	}
	return 0;
}