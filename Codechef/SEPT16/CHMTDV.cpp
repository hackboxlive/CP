#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,p;
	scanf("%d%d",&n,&p);
	int mat[510][510];
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			scanf("%d",&mat[i][j]);
		}
	}
	int vertical[510];
	int horizontal[510];
	memset(vertical,0,sizeof(vertical));
	memset(horizontal,0,sizeof(horizontal));
	int ctr=1;
	srand(time(NULL));
	while(ctr<p)	{
		int num=rand()%(n-2)+1;
		if(vertical[num]==0)	{
			vertical[num]=1;
			ctr++;
		}
	}
	ctr=1;
	while(ctr<p)	{
		int num=rand()%(n-2)+1;
		if(horizontal[num]==0)	{
			horizontal[num]=1;
			ctr++;
		}
	}
	for(int i=1;i<n;i++)	{
		if(horizontal[i]==1)	{
			cout<<i<<" ";
		}
	}
	cout<<endl;
	for(int i=1;i<n;i++)	{
		if(vertical[i]==1)	{
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}