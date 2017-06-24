#include <bits/stdc++.h>
using namespace std;
int calc_length(unsigned long long int x)	{
	int len=0;
	while(x>0)	{
		x=x/2;
		len++;
	}
	return len;
}
int main()	{
	int n;
	scanf("%d",&n);
	unsigned long long int arr[100100];
	for(int i=0;i<n;i++)	{
		scanf("%llu",&arr[i]);
	}
	int len[100100];
	for(int i=0;i<n;i++)	{
		len[i]=calc_length(arr[i]);
	}
	vector<unsigned long long int> bucket[65];
	for(int i=0;i<n;i++)	{
		bucket[len[i]].push_back(arr[i]);
	}
	vector<unsigned long long int> values;
	for(int i=64;i>0;i--)	{
		if(bucket[i].size()!=0)	{
			values.push_back(bucket[i][0]);
			for(int j=1;j<bucket[i].size();j++)	{
				int newlen=calc_length(bucket[i][0]^bucket[i][j]);
				bucket[newlen].push_back(bucket[i][0]^bucket[i][j]);
			}
		}
	}
	unsigned long long int tot=0;
	for(int i=0;i<values.size();i++)	{
		if(tot<(tot^values[i]))	{
			tot=(tot^values[i]);
		}
	}
	printf("%llu\n",tot);
	return 0;
}