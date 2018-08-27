#include <bits/stdc++.h>
using namespace std;

int main()	{
	string s;
	cin>>s;
	char l=s[s.length()-1];
	int n=s.length();
	s=s+s;
	if(s[0]=='b')	{
		s='b'+s;
	}
	else	{
		s='w'+s;
	}
	if(l=='w')	{
		s=s+'w';
	}
	else	{
		s=s+'b';
	}
	int prev=0;
	int ans=0;
	for(int i=0;i<s.length()-1;i++)	{
		if(s[i]==s[i+1])	{
			ans=max(ans,i-prev);
			prev=i;
		}
	}
	if(ans==2*n)	{
		ans/=2;
	}
	cout<<ans<<endl;
	return 0;
}