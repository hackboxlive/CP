#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int barr[1000];
int main()	{
	int n;
	int k;
	scanf("%d%d",&n,&k);
	int ssum=0;
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	barr[0]=arr[0];
	for(int i=1;i<n;i++)	{
		if(arr[i]+barr[i-1]<k)	{
			barr[i]=k-barr[i-1];
			ssum=ssum+barr[i]-arr[i];
		}
		else	{
			barr[i]=arr[i];
		}
	}
	cout<<ssum<<endl;
	for(int i=0;i<n;i++)	{
		cout<<barr[i]<<" ";
	}
	cout<<endl;
	return 0;
}