#include <bits/stdc++.h>
using namespace std;
int main()	{
	string s;
	cin>>s;
	int u=0,r=0;
	if(s.length()%2==1)	{
		cout<<"-1\n";
		return 0;
	}
	for(int i=0;i<s.length();i++)	{
		if(s[i]=='U')	{
			u++;
		}
		if(s[i]=='L')	{
			r--;
		}
		if(s[i]=='R')	{
			r++;
		}
		if(s[i]=='D')	{
			u--;
		}
	}
	int tot=abs(r)+abs(u);
	tot=tot/2;
	cout<<tot<<"\n";
	return 0;
}