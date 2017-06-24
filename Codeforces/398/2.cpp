#include <bits/stdc++.h>
using namespace std;
long long int arr[100100];
long long int en[100100];
long long int wait[100100];
int main()	{
	long long int ts,tf,t,n;
	cin>>ts>>tf>>t;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	en[0]=ts+t;
	for(int i=1;i<n;i++)	{
		if(arr[i]>=en[i-1])	{
			en[i]=arr[i]+t;
		}
		else	{
			en[i]=en[i-1]+t;
		}
	}
	if(n==0)	{
		cout<<ts<<endl;
		return 0;
	}
	if(arr[0]>ts)	{
		cout<<ts<<endl;
		return 0;
	}
	long long int val;
	wait[0]=ts-arr[0]+1;
	long long int miinn=1e18;
	long long int tt;
	for(int i=1;i<n;i++)	{
		val=arr[i]-1;
		if(en[i-1]>tf-t)	{
			continue;
		}
		if(val<en[i-1])	{
			wait[i]=en[i-1]-val;
		}
		else	{
			wait[i]=0;
		}
		if(miinn>wait[i])	{
			miinn=wait[i];
			tt=val;
		}
	}
	if(en[n-1]<=tf-t)	{
		cout<<en[n-1]<<endl;
		return 0;
	}
	if(ts>0 && arr[0]>0)	{
		if(wait[0]<miinn)	{
			tt=arr[0]-1;
		}
	}
	cout<<tt<<endl;
	return 0;
}