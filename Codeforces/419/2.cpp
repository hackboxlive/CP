#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[100100];
int ans[100100];
int main()	{
	int t;
	cin>>t;
	int n;
	while(t--)	{
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>arr[i].first>>arr[i].second;
		}
		int an=-1;
		int minh=1e9;
		for(int i=n-1;i>=0;i--)	{
			ans[i]=an;
			if(minh>arr[i].second)	{
				minh=arr[i].second;
				an=i;
			}
		}
	}
}