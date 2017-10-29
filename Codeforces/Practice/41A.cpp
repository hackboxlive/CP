#include <bits/stdc++.h>
using namespace std;
int main()	{
	string p;
	cin>>p;
	string q;
	cin>>q;
	if(p.length()!=q.length())	{
		cout<<"NO\n";
//		cout<<"asd";
	}
	else	{
		int flag=0;
		for(int i=0;i<p.length();i++)	{
			if(p[p.length()-1-i]!=q[i])	{
				flag=1;
			}
		}
		if(flag==0)	{
			cout<<"YES\n";
		}
		else	{
			cout<<"NO\n";
		}
	}
	return 0;
}