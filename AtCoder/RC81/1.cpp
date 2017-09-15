#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int barr[100100];
int j=0;
long long getmax1(int n)	{
	int retv=-1;
	for(int i=0;i<n-1;i++)	{
		if(arr[i]==arr[i+1])	{
			retv=arr[i];
			break;
		}
	}
	int cnt=0;
	for(int	i=0;i<n;i++)	{
		if(arr[i]==retv && cnt<2)	{
			cnt++;
			continue;
		}
		barr[j]=arr[i];
		j++;
	}
	return retv;
}
long long getmax2(int n)	{
	int retv=-1;
	for(int i=0;i<n-1;i++)	{
		if(barr[i]==barr[i+1])	{
			retv=barr[i];
			break;
		}
	}
	return retv;
}
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	reverse(arr,arr+n);
	long long v1=getmax1(n);
	long long v2=getmax2(j);
	if(v1==-1 || v2==-1)	{
		cout<<"0\n";
	}
	else	{
		v1=v1*v2;
		cout<<v1<<endl;
	}
	return 0;
}