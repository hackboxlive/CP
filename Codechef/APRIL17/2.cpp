#include <bits/stdc++.h>
using namespace std;
int tot[100100];
int island[100100];
int main()	{
	int t,n,k,p,ingredient;
	scanf("%d",&t);
	while(t--)	{
		memset(tot,0,sizeof(tot));
		memset(island,0,sizeof(island));
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)	{
			scanf("%d",&p);
			for(int j=0;j<p;j++)	{
				scanf("%d",&ingredient);
				if(tot[ingredient]==0)	{
					island[i]=1;
				}
				tot[ingredient]=1;
			}
		}
		string result="";
		for(int i=1;i<=k;i++)	{
//			cout<<tot[i]<<" ";
			if(tot[i]==0)	{
				result="sad";
			}
		}
//		cout<<endl;
		if(result.compare("")==0)	{
			for(int i=1;i<=n;i++)	{
//				cout<<island[i]<<" ";
				if(island[i]==0)	{
					result="some";
				}
			}
//			cout<<endl;
			if(result.compare("")==0)	{
				result="all";
			}
		}
		cout<<result<<endl;
	}
	return 0;
}