#include <bits/stdc++.h>
using namespace std;
int arr[5050];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	int mx=-1;
	for(int i=0;i<n;i++)	{
		int cnt=0;
		for(int j=0;j<n;j++)	{
			if(arr[i]==arr[j])	{
				cnt++;
			}
		}
		mx=max(mx,cnt);
	}
	cout<<mx<<endl;
	return 0;
}