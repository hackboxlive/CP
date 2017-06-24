#include <bits/stdc++.h>
using namespace std;
int main()	{
	int arr[110];
	int n;
	cin>>n;
	for(int i=1;i<n;i++)	{
		cin>>arr[i];
	}
	int a,b;
	cin>>a>>b;
	int ss=0;
	for(int i=a;i<b;i++)	{
		ss+=arr[i];
	}
	cout<<ss;
	return 0;
}