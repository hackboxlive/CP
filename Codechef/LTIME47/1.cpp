#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	string s;
	scanf("%d",&t);
	while(t--)	{
		cin>>s;
		bool flag=true;
		int onefirst=s.length();
		for(int i=0;i<s.length();i++)	{
			if(s[i]=='1')	{
				onefirst=i;
				break;
			}
		}
		int lastone=-1;
		for(int i=s.length()-1;i>=0;i--)	{
			if(s[i]=='1')	{
				lastone=i;
				break;
			}
		}
		for(int i=onefirst;i<=lastone;i++)	{
			if(s[i]=='0')	{
				flag=false;
				break;
			}
		}
		if(flag==false || lastone<onefirst)	{
			printf("NO\n");
		}
		else	{
			printf("YES\n");
		}
	}
	return 0;
}