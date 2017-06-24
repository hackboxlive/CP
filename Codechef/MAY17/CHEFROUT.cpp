#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	string s;
	bool flag=true;
	scanf("%d",&t);
	while(t--)	{
		cin>>s;
		flag=true;
		for(int i=1;i<s.length();i++)	{
			if(s[i]<s[i-1])	{
				printf("no\n");
				flag=false;
				break;
			}
		}
		if(flag)	{
			printf("yes\n");
		}
	}
	return 0;
}