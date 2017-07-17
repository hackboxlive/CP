#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >graph(26);
int main()	{
	int n;
	string s;
	cin>>n;
	for(int t=0;t<n;t++)	{
		cin>>s;
		for(int i=0;i<s.length();i++)	{
			graph[(int)s[i]-'a'].push_back()
		}
	}
}