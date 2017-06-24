#include <bits/stdc++.h>
using namespace std;
int main()	{
	string s;
	cin>>s;
	s=s+"0";
	int last;
	for(int i=0;i<s.length();i++)	{
		if(s[i]=='1')	{
			last=i;
		}
	}
	int ctr=0;
	for(int i=0;i<=last;i++)	{
		if(s[i]!=s[i+1])	{
			ctr++;
		}
	}
	cout<<ctr<<endl;
}