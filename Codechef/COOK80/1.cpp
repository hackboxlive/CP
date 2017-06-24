#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	int n,m;
	string s;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d",&n,&m);
		cin>>s;
		int flag=0;
		int ctr=0;
		int r,c;
		for(int i=0;i<n;i++)	{
			for(int j=0;j<m;j++)	{
				r=i;
				c=j;
				flag=0;
				for(int k=0;k<s.length();k++)	{
					if(s[k]=='L')	{
						c--;
					}
					if(s[k]=='R')	{
						c++;
					}
					if(s[k]=='U')	{
						r--;
					}
					if(s[k]=='D')	{
						r++;
					}
					if(c<0 || c>m-1 || r<0 || r>n-1)	{
						flag=1;
						break;
					}
				}
				if(flag==0)	{
					ctr++;
				}
			}
		}
		if(ctr!=0)	{
			printf("safe\n");
		}
		else	{
			printf("unsafe\n");
		}
	}
	return 0;
}