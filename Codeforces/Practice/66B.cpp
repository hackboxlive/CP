#include <bits/stdc++.h>
using namespace std;
int arr[1010];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	int ans=0,id;
	for(int i=0;i<n;i++)	{
		int temp=1;
		for(int j=i+1;j<n;j++)	{
			if(arr[j]<=arr[j-1])	{
				temp++;
			}
			else	{
				break;
			}
		}
//		cout<<i<<" "<<temp<<endl;
		for(int j=i-1;j>=0;j--)	{
			if(arr[j]<=arr[j+1])	{
				temp++;
			}
			else	{
				break;
			}
		}
		if(temp>ans)	{
			id=i;
			ans=temp;
		}
	}
	cout<<ans<<endl;//<<" "<<id<<endl;
	return 0;
}