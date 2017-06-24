#include <bits/stdc++.h>
using namespace std;
vector<pair<string,int> > inp;
vector<pair<string,int> > lis;
int main()	{
	int n;
	string name;
	int point;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		cin>>name>>point;
		inp.push_back(make_pair(name,point));
	}
	for(int i=0;i<n;i++)	{
		name=inp[i].first;
		point=inp[i].second;
		int flag=0;
		int pos;
		for(int j=0;j<lis.size();j++)	{
			if((lis[j].first).compare(name)==0)	{
				flag=1;
				pos=j;
			}
		}
		if(flag==0)	{
			lis.push_back(make_pair(name,point));
		}
		else	{
			lis[pos].second+=point;
		}
	}
	int max_point=INT_MIN;
	for(int i=0;i<lis.size();i++)	{
		if(max_point < lis[i].second)	{
			max_point = lis[i].second;
		}
	}
	vector<pair<string,int> > fin;
	for(int i=0;i<lis.size();i++)	{
		if(lis[i].second == max_point)	{
			fin.push_back(make_pair(lis[i].first,0));
		}
	}
	string max_name;
	int flag=0;
	for(int i=0;i<n;i++)	{
		for(int j=0;j<fin.size();j++)	{
			if((fin[j].first).compare(inp[i].first)==0)	{
				fin[j].second+=inp[i].second;
			}
			if(fin[j].second >= max_point)	{
				flag=1;
				max_name = fin[j].first;
				break;
			}
		}
		if(flag==1)	{
			break;
		}
	}
	cout<<max_name;
	return 0;
}