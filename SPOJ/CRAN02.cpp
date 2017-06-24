#include <bits/stdc++.h>
using namespace std;
long long int arr[1001000];
int main()	{
	int t,n;
	long long int ctr;
	scanf("%d",&t);
	while(t--)	{
		ctr=0;
		scanf("%d",&n);
		scanf("%lld",&arr[0]);
		if(arr[0]==0)	{
			ctr++;
		}
		for(int i=1;i<n;i++)	{
			scanf("%lld",&arr[i]);
			arr[i]=arr[i-1]+arr[i];
			if(arr[i]==0)	{
				ctr++;
			}
		}
		sort(arr,arr+n);
		long long int sv=1;
		int j=0;
		for(int i=1;i<n;i++)	{
			if(arr[i]==arr[j])	{
				sv++;
			}
			else	{
				ctr=ctr+(long long int)((sv-1)*sv)/2;
				sv=1;
				j=i;
			}
		}
		ctr=ctr+(long long int)((sv-1)*sv)/2;
		printf("%lld\n",ctr);
	}
	return 0;
}