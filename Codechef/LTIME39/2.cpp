#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > parr;
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	if(p1.first==p2.first)	{
		return p1.second>p2.second;
	}
	return p1.first>p2.first;
}
int main()	{
	int t;
	int arr[1001000];
	int ind[1001000];
	scanf("%d",&t);
	while(t--)	{
		int n;
		int c=0,d=0;
		int totnum=0;
		for(int i=0;i<n;i++)	{
			scanf("%d",&ind[c++]);
			totnum=totnum+ind[c-1];
			for(int j=0;j<ind[c-1];j++)	{
				scanf("%d",&arr[d++]);
			}
		}
		int num;
		for(int i=0;i<totnum;i++)	{
			scanf("%d",&num);
			parr.push_back(make_pair(num,i));
		}
		sort(parr.begin(),parr.end(),comp);
		int d=1;
		for(int i=0;i<n;i++)	{
			for(int j=1;j<ind[i];j++)	{
				if()
			}
		}
	}
	return 0;
}