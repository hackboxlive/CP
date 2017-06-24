#include <bits/stdc++.h>
using namespace std;
pair<int,int> chess[200200];
pair<int,int> programming[200200];
vector<int> ans;
bool comp1(const pair<int,int> &p1,const pair<int,int> &p2)	{
	return p1.first<p2.first;
}
bool comp2(const pair<int,int> &p1,const pair<int,int> &p2)	{
	return p1.second<p2.second;
}
int main()	{
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>chess[i].first>>chess[i].second;
	}
	cin>>m;
	for(int i=0;i<m;i++)	{
		cin>>programming[i].first>>programming[i].second;
	}
	sort(programming,programming+m,comp1);
	for(int i=0;i<n;i++)	{
		if(chess[i].second < programming[m-1].first)	{
			ans.push_back(programming[m-1].first - chess[i].second);
		}
		else	{
			ans.push_back(0);
		}
	}
	sort(programming,programming+m,comp2);
	for(int i=0;i<n;i++)	{
		if(chess[i].first > programming[0].second)	{
			ans.push_back(chess[i].first - programming[0].second);
		}
		else	{
			ans.push_back(0);
		}
	}
	int maxx = -1e9;
	for(int i=0;i<ans.size();i++)	{
		if(maxx<ans[i])	{
			maxx=ans[i];
		}
	}
	cout<<maxx<<endl;//max value of ans;
	return 0;
}