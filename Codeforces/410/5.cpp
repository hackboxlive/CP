#include <bits/stdc++.h>
using namespace std;
int arr[500500];
int revarr[500500];
int perm[500500];
int la;
int st;
void calc(int x)	{
	if(x==-1)	{
		return;
	}
	calc(arr[x]);
	perm[x]=la;
	la--;
	return;
}
int main()	{
	int n;
	scanf("%d",&n);
	la=n;
	st=1;
	for(int i=1;i<=n;i++)	{
		scanf("%d",&arr[i]);
		if(arr[i]!=-1)	{
			revarr[arr[i]]=i;
		}
	}
	int j;
	for(int i=1;i<=n;i++)	{
		if(revarr[i]==0)	{
			j=arr[i];
			perm[i]=st;
			st++;
			calc(j);
		}
	}
	for(int i=1;i<=n;i++)	{
		printf("%d ",perm[i]);
	}
	return 0;
}