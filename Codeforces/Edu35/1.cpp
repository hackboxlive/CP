#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int n;
	cin>>n;
	int minn=1e9+7;
	int pos=-1;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
		if(arr[i]<minn)	{
			minn=arr[i];
			pos=i;
		}
	}
	int prev=pos;
	int ans=1e9;
	for(int i=pos+1;i<n;i++)	{
		if(arr[i]==minn)	{
			if(i-prev<ans)	{
				ans=i-prev;
			}
			prev=i;
		}
	}
	cout<<ans<<endl;

	return 0;
}