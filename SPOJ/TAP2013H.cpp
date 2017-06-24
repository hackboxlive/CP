#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > orders(1001000);
int sameord[1001000];
int lpd[1001000];
void sieve()	{
	for(int i=0;i<1001000;i++)	{
		lpd[i]=i;
	}
	for(int i=2;i<1001000;i++)	{
		if(lpd[i]==i)	{
			for(int j=2*i;j<1001000;j=j+i)	{
				if(lpd[j]==j)	{
					lpd[j]=i;
				}
			}
		}
	}
	return;
}
int main()	{
	sieve();
	int ssum,icomp,prev;
	for(int i=2;i<1001000;i++)	{
		icomp=i;
		if(lpd[icomp]!=icomp)	{
			prev=lpd[icomp];
			icomp=icomp/lpd[icomp];
			ssum=prev;
			while(icomp>1)	{
				if(prev!=lpd[icomp])	{
					ssum=ssum+lpd[icomp];
				}
				prev=lpd[icomp];
				icomp=icomp/lpd[icomp];
			}
			sameord[i]=sameord[ssum]+1;
		}
		else	{
			sameord[i]=1;
		}
	}
	for(int i=2;i<1001000;i++)	{
		orders[sameord[i]].push_back(i);
	}
	int p;
	int val;
	int ap,bp,kp;
	scanf("%d",&p);
	while(p--)	{
		scanf("%d%d%d",&ap,&bp,&kp);
		val=upper_bound(orders[kp].begin(),orders[kp].end(),bp)-lower_bound(orders[kp].begin(),orders[kp].end(),ap);
		printf("%d\n",val);
	}
//	printf("%d\n",sameord[1000000]);
//	for(int i=1;i<100;i++)	{
//		for(int j=0;j<orders[i].size() && j<10;j++)	{
//			printf("%d ",orders[i][j]);
//		}
//		printf("\n");
//	}
	return 0;
}