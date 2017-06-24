#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int t,n,q;
	cin>>t;
	while(t--)	{
		cin>>n>>q;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		int k;
		while(q--)	{
			cin>>k;
			int hi=n,lo=0,mid;
			while(lo<hi)	{
				mid=(lo+hi)/2;
				if(arr[mid]>=k)	{
					hi=mid;
				}
				else	{
					lo=mid+1;
				}
			}
			lo--;
//			if(lo==-1)	{
//				cout<<n<<endl;
//				continue;
//			}
			int p=lo-1;
			while(true)	{
				if(p+arr[lo]>=k)	{
					p=k-arr[lo];
					lo--;
				}
				else	{
					break;
				}
			}
			cout<<n-lo-1<<endl;
		}
	}
	return 0;
}