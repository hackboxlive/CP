#include <bits/stdc++.h>
using namespace std;
int arr[100];
bool comp(const int &p1,const int &p2)	{
	return p1>p2;
}
int main()	{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,comp);
	int val=arr[k-1];
	if(val==0)	{
		int count=0;
		for(int i=0;i<k;i++)	{
			if(arr[i]>0)	{
				count++;
			}
		}
		cout<<count;
	}
	else	{
		int count=0;
		for(int i=0;i<n;i++)	{
			if(arr[i]>=val)	{
				count++;
			}
		}
		cout<<count;
	}
	return 0;
}