#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,k;
	cin>>n>>k;
	int a[1010];
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)	{
		int j;
		for(j=0;j<n;j++)	{
			if(!a[j])	{
				break;
			}
		}
		cout<<j+1<<" ";
		a[j]=-1;
		for(int p=0;p<=j-k;p++)	{
			a[p]--;

		}
	}
	return 0;
}