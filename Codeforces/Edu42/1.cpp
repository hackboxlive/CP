#include <bits/stdc++.h>
using namespace std;

long long arr[200100];
int main()	{
	int n;
	cin>>n;
	long long summ=0;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
		summ+=arr[i];
	}
	long long mid;
	if(summ%2)	{
		mid=summ/2+1;
	}
	else	{
		mid=summ/2;
	}
	long long temp=0;
	for(int i=0;i<n;i++)	{
		if(temp+arr[i]>=mid)	{
			cout<<i+1<<endl;
			return 0;
		}
		else	{
			temp+=arr[i];
		}
	}
	return 0;
}