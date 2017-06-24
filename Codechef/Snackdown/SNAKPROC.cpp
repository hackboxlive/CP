#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	int len;
	string s;
	while(t--)	{
		cin>>len;
		cin>>s;
		int head=0;
		int tail=0;
		bool flag=true;
		for(int i=0;i<len;i++)	{
			if(s[i]=='H')	{
				head++;
			}
			if(s[i]=='T')	{
				head--;
			}
			if(head>1)	{
				flag=false;
			}
			if(head<0)	{
				flag=false;
			}
		}
		if(head>0)	{
			flag=false;
		}
		if(flag)	{
			cout<<"Valid\n";
		}
		else	{
			cout<<"Invalid\n";
		}
	}
	return 0;
}	