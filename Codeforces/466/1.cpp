#include <bits/stdc++.h>
using namespace std;

int arr[101];
int main()	{
	int n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int ans=n;
	for(int i=0;i<n;i++)	{
		int temp=i;
		int fin=n;
		for(int j=i;j<n;j++)	{
			if(arr[j]-arr[i]>d)	{
				fin=j;
				break;
			}
		}
		if(fin==n)	{
			ans=min(ans,temp);
		}
		else	{
			ans=min(ans,temp+n-fin);
		}
	}
	cout<<ans<<endl;
	return 0;
}