#include <bits/stdc++.h>
using namespace std;
long long int arr[100100];
int main()	{
	long long int n,c;
	cin>>n>>c;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	int num=1;
	for(int i=1;i<n;i++)	{
		if(arr[i]-arr[i-1]<=c)	{
			num++;
		}
		else	{
			num=1;
		}
	}
	cout<<num<<endl;
}