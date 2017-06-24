#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	scanf("%d",&t);
	char s[100100];
	while(t--)	{
		scanf("%s",s);
		int len=strlen(s);
		int zero=0;
		int one=0;
		for(int i=0;i<len;i++)	{
			if(s[i]=='0')	{
				zero++;
			}
			else	{
				one++;
			}
		}
		if((one==1 && zero==len-1) || (one==len-1 && zero==1))	{
			printf("Yes\n");
		}
		else	{
			printf("No\n");
		}
	}
	return 0;
}