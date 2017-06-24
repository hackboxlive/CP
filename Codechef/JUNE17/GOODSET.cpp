#include <bits/stdc++.h>
using namespace std;
int arr[10100];
void precompute()	{
	for(int i=0;i<10100;i++)	{
		arr[i]=1;
	}
	arr[0]=0;
	arr[3]=0;
	for(int i=4;i<=500;i++)	{
		if(arr[i]==1)	{
			for(int j=1;j<i;j++)	{
				if(arr[j]==1)	{
					arr[j+i]=0;
				}
			}
		}
	}
}
int main()	{
	precompute();
	int t,n;
	cin>>t;
	while(t--)	{
		cin>>n;
		int i=1;
		while(n!=0 && i<=500)	{
			if(arr[i]!=0)	{
				cout<<i<<" ";
				n--;
			}
			i++;
		}
		cout<<endl;
	}
	return 0;
}