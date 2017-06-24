#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int lft[100100];
int rgt[100100];
int main()	{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	lft[0]=0;
	rgt[n-1]=0;
	for(int i=1;i<n;i++)	{
		if(arr[i]==arr[i-1])	{
			lft[i]=lft[i-1]+1;
		}
		else	{
			lft[i]=0;
		}
		if(arr[n-i-1]==arr[n-i])	{
			rgt[n-i-1]=rgt[n-i]+1;
		}
		else	{
			rgt[n-i-1]=0;
		}
	}
	int val;
	int ctr;
	int l,r,k,mid;
	while(m--)	{
		scanf("%d%d%d",&l,&r,&k);
		l--;
		r--;
		ctr=1;
		mid=(l+r)/2;
		val=arr[(l+r)/2];
		ctr+=min(lft[mid],mid-l);
		ctr+=min(rgt[mid],r-mid);
		if(ctr>=k)	{
			printf("%d\n",val);
		}
		else	{
			printf("-1\n");
		}
	}
	return 0;
}