#include <bits/stdc++.h>
using namespace std;
int arr[100100];
long long prefix[100100],suffix[100100];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
		}
		prefix[0]=arr[0];
		suffix[n-1]=arr[n-1];
		for(int i=1;i<n;i++)	{
			prefix[i]=prefix[i-1]+arr[i];
			suffix[n-i-1]=suffix[n-i]+arr[n-1-i];
		}
		long long minans=-1;
		int pos=-1;
		for(int i=0;i<n;i++)	{
			if(minans==-1 || minans>suffix[i]+prefix[i])	{
				minans=suffix[i]+prefix[i];
				pos=i;
			}
		}
		cout<<pos+1<<endl;
	}
	return 0;
}