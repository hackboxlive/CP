#include <bits/stdc++.h>
using namespace std;
int x[20010];
int y[20010];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&x[i]);
		}
		for(int i=0;i<n;i++)	{
			scanf("%d",&y[i]);
		}
		int firstt=0,secc=0;
		for(int i=0;i<n;i++)	{
			if(i&1)	{
				firstt+=y[i];
				secc+=x[i];
			}
			else	{
				firstt+=x[i];
				secc+=y[i];
			}
		}
		printf("%d\n",min(firstt,secc));
	}
	return 0;
}