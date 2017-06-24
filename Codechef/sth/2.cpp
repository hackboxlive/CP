#include <bits/stdc++.h>
using namespace std;
long long int powermod(int i)	{
	long long int powe=1;
	for(int j=1;j<=i;j++)	{
		powe=powe*2;
		powe%=1000000007;
	}
	return powe-1;
}
int main()	{
	int t;
	scanf("%d",&t);
	string s;
	while(t--)	{
		cin>>s;
		int arr[26]={0};
		int ctr=1;
		for(int i=0;i<s.length();i++)	{
			arr[s[i]-97]++;
		}
		long long int sum=0;
		for(int i=0;i<26;i++)	{
			sum=(long long int)(sum+powermod(arr[i]))%1000000007;
		}
		printf("%lld\n",sum);
	}
	return 0;
}