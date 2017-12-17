#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<pair<string,bool> > str[25];
int main()	{
	int n;
	cin>>n;
	string s,p;
	int num;
	int ctr=0;
	while(n--)	{
		cin>>s;
		cin>>num;
		for(int i=0;i<num;i++)	{
			cin>>p;
			if(mp.find(s)==mp.end())	{
				mp[s]=ctr++;
			}
			str[mp[s]].push_back(make_pair(p,true));
		}
	}

	// for(int i=0;i<ctr;i++)	{
	// 	for(int j=0;j<str[i].size();j++)	{
	// 		cout<<str[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(int i=0;i<ctr;i++)	{
		for(int j=0;j<str[i].size();j++)	{
			for(int k=0;k<str[i].size();k++)	{
				if(str[i][j].second==true && str[i][k].second==true)	{
					if(k!=j)	{
						if(str[i][j].first.length()<=str[i][k].first.length())	{
							if(str[i][j].first.compare(str[i][k].first.substr(str[i][k].first.length()-str[i][j].first.length(),str[i][j].first.length()))==0)	{
								str[i][j].second=false;
							}
						}
						else	{
							if(str[i][k].first.compare(str[i][j].first.substr(str[i][j].first.length()-str[i][k].first.length(),str[i][k].first.length()))==0)	{
								str[i][k].second=false;
							}
						}
					}
				}
			}
		}
	}
	cout<<ctr<<endl;
//	int pp=0;
	// for(auto it=mp.begin();it!=mp.end();it++)	{
	// 	cout<<it->first<<" "<<it->second<<endl;
	// }
	for(auto it=mp.begin();it!=mp.end();it++)	{

		cout<<it->first<<" ";
		int c=0;
		for(int i=0;i<str[it->second].size();i++)	{
			if(str[it->second][i].second==true)	{
				c++;
			}
		}
		cout<<c;
		for(int i=0;i<str[it->second].size();i++)	{
			if(str[it->second][i].second==true)	{
				cout<<" "<<str[it->second][i].first;
			}
		}
		cout<<endl;
	}
	return 0;
}