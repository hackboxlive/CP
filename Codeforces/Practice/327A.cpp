#include <bits/stdc++.h>
using namespace std;
int arr[110];
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	int l=0,r=0;
	int zero=0;
	int finall=-1;
	int finalr=-1;
	int totzero=INT_MIN;
	while(r<n)	{
		if(arr[r]==0)	{
			zero++;
		}
		else	{
			zero--;
		}
		if(zero >= totzero)	{
			totzero=zero;
			finall=l;
			finalr=r;
		}
		r++;
		if(zero < 0)	{
			zero=0;
			l=r;
		}
	}
	int cnt=0;
	for(int i=0;i<finall;i++)	{
		if(arr[i]==1)	{
			cnt++;
		}
	}
	for(int i=finall;i<=finalr;i++)	{
		if(arr[i]==0)	{
			cnt++;
		}
	}
	for(int i=finalr+1;i<n;i++)	{
		if(arr[i]==1)	{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}