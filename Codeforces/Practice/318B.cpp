#include <bits/stdc++.h>
using namespace std;
int main()	{
	string s;
	cin>>s;
	int len=s.length();
	vector<int> heavy,metal;
	for(int i=0;i<len-4;i++)	{
		if(s[i]=='h' && s[i+1]=='e' && s[i+2]=='a' && s[i+3]=='v' && s[i+4]=='y')	{
			heavy.push_back(i);
		}
		if(s[i]=='m' && s[i+1]=='e' && s[i+2]=='t' && s[i+3]=='a' && s[i+4]=='l')	{
			metal.push_back(i);
		}
	}
	int val;
	long long tot=0;
	for(int i=0;i<heavy.size();i++)	{
		val=lower_bound(metal.begin(),metal.end(),heavy[i])-metal.begin();
		val=(int)metal.size()-val;
		tot=tot+val;
	}
	cout<<tot<<endl;
	return 0;
}
