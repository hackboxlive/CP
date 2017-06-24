#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	char s[100100];
	scanf("%d",&t);
	while(t--)	{
		scanf("%s",s);
		int len=strlen(s);
		int flag=0;
		for(int i=0;i<(len+1)/2;i++)	{
			if(s[i]!='.' && s[len-1-i]!='.')	{
				if(s[i]==s[len-i-1])	{
					continue;
				}
				else	{
					flag=1;
					break;
				}
			}
			else if(s[i]=='.' && s[len-1-i]!='.')	{
				s[i]=s[len-1-i];
			}
			else if(s[i]!='.' && s[len-1-i]=='.')	{
				s[len-1-i]=s[i];
			}
			else	{
				s[i]='a';
				s[len-1-i]='a';
			}
		}
		if(flag==1)	{
			printf("-1\n");
		}
		else	{
			printf("%s\n",s);
		}
	}
	return 0;
}