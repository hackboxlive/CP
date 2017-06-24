#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<string,int> > > v(55);
int main()	{
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>s;
		if(i>0)	{
			if(s.length()!=v[0][0].first.length())	{
				printf("-1\n");
				return 0;
			}
		}
		v[i].push_back(make_pair(s,0));
	}
	for(int i=0;i<n;i++)	{
		for(int j=1;j<v[i][0].first.length();j++)	{
			string newstr=v[i][0].first.substr(j)+v[i][0].first.substr(0,j);
			v[i].push_back(make_pair(newstr,j));
		}
	}
	int ansmin=1e9;
	int ans;
	for(int i=0;i<v[0][0].first.length();i++)	{
		int flag=0;
		ans=v[0][i].second;
		for(int j=1;j<n;j++)	{
			flag=0;
			for(int k=0;k<v[j].size();k++)	{
				if(v[0][i].first.compare(v[j][k].first)==0)	{
					ans+=v[j][k].second;
					flag=1;
				}
			}
			if(flag==0)	{
				printf("-1\n");
				return 0;
			}
		}
		ansmin=min(ans,ansmin);
	}
	printf("%d\n",ansmin);
	return 0;
}