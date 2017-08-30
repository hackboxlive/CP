#include <bits/stdc++.h>
#define MAXX 1000000000000000000LL
using namespace std;
long long arr[100100];

int main()	{
	int t;
	cin>>t;
	while(t--)	{
		long long s,x;
		int n;
		cin>>s>>n>>x;
		long long v,prev=s;
		arr[0]=s;
		for(int i=0;i<n;i++)	{
			cin>>v;
			if(prev>MAXX || prev<=0)	{
				arr[i+1]=0;
			}
			else	{
				arr[i+1]=prev+v;
				prev=prev+arr[i+1];
			}
		}
		if(x>prev)	{
			cout<<"no\n";
			continue;
		}
		for(int i=n;i>=0;i--)	{
			if(x>=arr[i])	{
				x=x-arr[i];
			}
		}
		if(x==0)	{
			cout<<"yes\n";
		}
		else	{
			cout<<"no\n";
		}
	}
	return 0;
}
