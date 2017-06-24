#include <bits/stdc++.h>
using namespace std;
int l[100100];
int r[100100];
int main()	{
	int n;
	long long int lsum=0;
	long long int rsum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d %d",&l[i],&r[i]);
		lsum=lsum+l[i];
		rsum=rsum+r[i];
	}
	long long int newl;
	long long int newr;
	long long int newb;
	int ans=0;
	long long int beauty=abs(lsum-rsum);
	for(int i=0;i<n;i++)	{
		newl=lsum-l[i]+r[i];
		newr=rsum-r[i]+l[i];
		newb=abs(newl-newr);
		if(newb>beauty)	{
			ans=i+1;
			beauty=newb;
		}
	}
	cout<<ans;
	return 0;
}