#include <bits/stdc++.h>
using namespace std;
int arr[110];
int votes[110];
int main()	{
	int t,n;
	scanf("%d",&t);
	while(t--)	{
		memset(votes,0,sizeof(votes));
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
			votes[arr[i]]++;
		}
		int cnt=0;
		for(int i=1;i<=100;i++)	{
			if(votes[i]>1)	{
				cnt+=(votes[i]-1);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}