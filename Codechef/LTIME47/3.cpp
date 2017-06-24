#include <bits/stdc++.h>
using namespace std;
vector<int> maxpos,minpos;
int main()	{
	int t;
	string s;
	scanf("%d",&t);
	while(t--)	{
		maxpos.clear();
		minpos.clear();
		cin>>s;
		char charmax=s[0];
		char charmin=s[0];
		int len=s.length();
		for(int i=1;i<len;i++)	{
			if(s[i]>charmax)	{
				charmax=s[i];
			}
			if(s[i]<charmin)	{
				charmin=s[i];
			}
		}
		int cnt=0;
		while(true)	{
			for(int i=0;i<len;i++)	{
				int val=s[i]-'0';
				for(int j=i-min(i,val);j<=min(len-1,i+val);j++)	{
				//	cout<<i<<" "<<j<<endl;
//					getchar();
					if(s[j]<s[i])	{
						if(s[i]-s[j]>=abs(j-i))	{
							s[j]=s[i];
						}
					}
				}
				//cout<<s<<endl;
			}
			cnt++;
			int flag=true;
			for(int i=0;i<len;i++)	{
				if(s[i]!=charmax)	{
					flag=false;
				}
			}
			if(flag)	{
				break;
			}
//			cout<<s<<endl;
//			getchar();
		}
		printf("%d\n",cnt);
	}
	return 0;
}