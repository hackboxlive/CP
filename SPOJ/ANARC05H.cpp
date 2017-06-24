#include <bits/stdc++.h>
using namespace std;
char s[50];
int cnt=0;
void dp_func(int cg,int lg,int i)	{
	if(cg>lg)	{
		return;
	}
	if(i==0)	{
		cnt++;
		return;
	}
	char ch=s[i-1];
	int val=(int)ch-48;
	dp_func(val,cg,i-1);
	dp_func(val+cg,lg,i-1);
	return;
}
int main()	{
	scanf("%s",s);
	int ctr=1;
	while(s[0]!='b')	{
		int len=strlen(s);
		char ch=s[len-1];
		int val=(int)ch-48;
		dp_func(val,10000000,len-1);
		printf("%d. %d\n",ctr++,cnt);
		cnt=0;
		scanf("%s",s);
	}
	return 0;
}