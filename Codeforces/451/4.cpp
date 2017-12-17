#include <bits/stdc++.h>
using namespace std;
int arr[200100];
int on[200200];
int main()	{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
		on[i]=1;
	}
	if(k==1)	{
		cout<<n<<endl;
		return 0;
	}
	sort(arr,arr+n);
	int ans=0;
	int l=0;int r=k-1;
	int cur=k-1;
	while(r<n)	{
		if(on[l]==0)	{
			l++;
			continue;
		}
		if(arr[r]-arr[l]<m)	{
			ans++;
			on[r]=0;
//			cout<<"Deleting "<<arr[r]<<endl;
		}
		else	{
			l++;
		}
		r++;
	}
	cout<<ans<<endl;
	return 0;
}