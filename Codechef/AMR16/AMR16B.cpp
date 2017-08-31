#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		int a[n],b[n];
		int steps=ceil(log2(n));
		cout<<steps<<endl;
		for(int i=0;i<n;i++)	{
			a[i]=i;
		}
		for(int i=0;i<steps;i++)	{
			for(int j=0;j<n;j++)	{
				cout<<a[j]+1<<" ";
			}
			cout<<endl;
			int k=0;
			for(int j=0;j<n;j+=2)	{
				b[k++]=a[j];
			}
			for(int j=1;j<n;j+=2)	{
				b[k++]=a[j];
			}
			for(int j=0;j<n;j++)	{
				a[j]=b[j];
			}
		}
	}
	return 0;
}
