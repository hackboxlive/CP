#include <bits/stdc++.h>
using namespace std;
map<char,vector<string> > mp;
int main()	{
	string s;
	cin>>s;
	double ans=0;
	string temp;
	for(int i=0;i<s.length();i++)	{
		temp=s.substr(i)+s.substr(0,i);
		mp[temp[0]].push_back(temp);
	}
	for(auto it=mp.begin();it!=mp.end();it++)	{
		for(int i=1;i<s.length();i++)	{
			for(int j=0;j<(*it).size();j++)	{
				
			}
		}
	}
	return 0;
}