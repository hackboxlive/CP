#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	return p1.first<p2.first;
}
int main()	{
	int n,a,b,k;
	scanf("%d%d%d%d",&n,&a,&b,&k);
	string s;
	cin>>s;
	vector<pair<int,int> > zeros;
	int ctr=0;
	int pos;
	for(int i=0;i<n;i++)	{
		if(s[i]=='0')	{
			ctr++;
			if(ctr==1)	{
				pos=i;
			}
		}
		if(s[i]=='1')	{
			if(ctr!=0)	{
				zeros.push_back(make_pair(ctr,pos));
				ctr=0;
			}
		}
	}
	if(ctr!=0)	{
		zeros.push_back(make_pair(ctr,pos));
	}
	sort(zeros.begin(),zeros.end(),comp);
	int ans=0;
	vector<int> psn;
	for(int i=0;i<zeros.size();i++)	{
		int numfit;
		if(zeros[i].first >= a*b)	{
			numfit=a;
		}
		else	{
			numfit=zeros[i].first/b;
		}
		ans=ans+(zeros[i].first-numfit*b)/b;
		for(int j=1;j<=(zeros[i].first-numfit*b)/b;j++)	{
			psn.push_back(zeros[i].second+j*b+1);
		}
		ans++;
		psn.push_back(zeros[i].second+1+zeros[i].first-b);
	}
	cout<<ans<<endl;
	for(int i=0;i<psn.size();i++)	{
		cout<<psn[i]<<" ";
	}
	cout<<endl;
	return 0;
}