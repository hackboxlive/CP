#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int main()	{
	int t;
	cin>>t;
	int n;
	while(t--)	{
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
		}
		if(n%2==0)	{
			cout<<"no\n";
		}
		else	{
			int len=n/2;
			bool flag=true;
			if(!(arr[0]==1 && arr[n-1]==1))	{
				flag=false;
			}
			for(int i=0;i<len;i++)	{
				if(arr[i]+1!=arr[i+1])	{
					flag=false;
				}
				if(arr[n-1-i]+1!=arr[n-2-i])	{
					flag=false;
				}
			}
			if(flag==true)	{
				cout<<"yes\n";
			}
			else	{
				cout<<"no\n";
			}
		}
	}
	return 0;
}