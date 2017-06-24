#include <bits/stdc++.h>
using namespace std;
int arr[1001000];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
		if(arr[i]>=1 && arr[i]<=2)	{
			arr[i]=1;
		}
		if(arr[i]>=3 && arr[i]<=5)	{
			arr[i]=2;
		}
		if(arr[i]>=6 && arr[i]<=9)	{
			arr[i]=3;
		}
		if(arr[i]>=10 && arr[i]<=14)	{
			arr[i]=4;
		}
		if(arr[i]>=15 && arr[i]<=20)	{
			arr[i]=5;
		}
		if(arr[i]>=21 && arr[i]<=27)	{
			arr[i]=6;
		}
		if(arr[i]>=28 && arr[i]<=35)	{
			arr[i]=7;
		}
		if(arr[i]>=36 && arr[i]<=44)	{
			arr[i]=8;
		}
		if(arr[i]>=45 && arr[i]<=54)	{
			arr[i]=9;
		}
		if(arr[i]>=55 && arr[i]<=60)	{
			arr[i]=10;
		}
	}
	int xx=0;
	for(int i=0;i<n;i++)	{
		xx=xx^arr[i];
	}
	if(xx!=0)	{
		cout<<"NO\n";
	}
	else	{
		cout<<"YES\n";
	}
}