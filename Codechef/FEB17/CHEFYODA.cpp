#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	long double val,ans;
	int n,m,k,p;
	int ctr;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d%d%d",&n,&m,&p,&k);
		if(n%2==0 && m%2==0)	{
			printf("1.000000\n");
			continue;
		}
		if(n%2==1 && m%2==1)	{
			if(p==0)	{
				printf("1.000000\n");
				continue;
			}
			printf("0.000000\n");
			continue;
		}
		val=0.5;
		ans=0.5;
		p=k-p;
		ctr=1;
		for(int i=1;i<=p;i++)	{
			val=val*(k-i+1);
			val=val/i;
			ans=ans+val;
			while(val>=1.0 && ctr<k)	{
				val=val*0.5;
				ans=ans*0.5;
				ctr++;
			}
		}
		while(ctr<k)	{
			ans=ans*0.5;
			ctr++;
		}
		printf("%.10Lf\n",ans);
	}
	return 0;
}