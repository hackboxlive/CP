#include <bits/stdc++.h>
using namespace std;
int main()	{
	string a,b;
	cin>>a>>b;
	if(a.length() > b.length())	{
		cout<<a.length();
		return 0;
	}
	if(a.length() < b.length())	{
		cout<<b.length();
		return 0;
	}
	bool flag=true;
	for(int i=0;i<a.length();i++)	{
		if(a[i]!=b[i])	{
			flag=false;
			break;
		}
	}
	if(flag==false)	{
		cout<<a.length();
	}
	else	{
		cout<<-1;
	}
	return 0;
}