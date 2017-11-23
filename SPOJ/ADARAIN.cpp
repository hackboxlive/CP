#include <bits/stdc++.h>
using namespace std;
int arr[1001000];
int main()	{
	int n,m,w,l,r;
	cin>>n>>m>>w;
	for(int i=0;i<n;i++)	{
		cin>>l>>r;
		if(r!=w-1)	{
			arr[r+1]--;
		}
		arr[l]++;
	}
	int v=0;
	for(int i=0;i<w;i++)	{
		v+=arr[i];
		arr[i]=v;
	}
	for(int i=0;i<m;i++)	{
		cin>>l;
		cout<<arr[l]<<endl;
	}
	return 0;
}