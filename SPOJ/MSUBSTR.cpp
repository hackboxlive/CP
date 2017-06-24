#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	char str[200100];
	char s[500500];
	int P[500500];
//	scanf("%d",&n);
	int t;
	scanf("%d",&t);
	while(t--)	{
		scanf("%s",str);
		n=strlen(str);
		int ctr=0;
		s[ctr]='^';
		ctr++;
		for(int i=0;i<n;)	{
			if(ctr%2==1)	{
				s[ctr]='#';
				++ctr;
			}
			else	{
				s[ctr]=str[i];
				++i;
				++ctr;
			}
		}
		s[ctr]='#';
		ctr++;
		s[ctr]='$';
		ctr++;
		int C=0;
		int R=0;
		memset(P,0,sizeof(P));
		for(int i=1;i<ctr-1;i++)	{
			int i_mirror=2*C-i;
			if(R>i)	{
				P[i]=min(R-i,P[i_mirror]);
			}
			else	{
				P[i]=0;
			}
			while(s[i+1+P[i]]==s[i-1-P[i]])	{
				P[i]++;
			}
			if(P[i]+i>R)	{
				C=i;
				R=i+P[i];
			}
		}
		int maxlen=0;
		for(int i=0;i<ctr;i++)	{
			if(maxlen<P[i])	{
				maxlen=P[i];
			}
	//		printf("%c %d\n",s[i],P[i]);
		}
		int countmax=0;
		for(int i=0;i<ctr;i++)	{
			if(P[i]==maxlen)	{
				countmax++;
			}
		}
		cout<<maxlen<<" "<<countmax<<endl;
	}
	return 0;
}