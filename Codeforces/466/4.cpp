#include <bits/stdc++.h>
using namespace std;
int a[100100];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	string b;
	cin>>b;
	int l=-1e9;
	int r=1e9;
	int temp;
	for(int i=4;i<n;i++)	{
		if(b[i]=='0')	{
			if(b[i-1]=='1' && b[i-2]=='1' && b[i-3]=='1' && b[i-4]=='1')	{
				temp=INT_MAX;
				for(int j=0;j<5;j++)	{
					temp=min(temp,a[i-j]);
				}
				r=min(r,temp-1);
			}			
		}
		if(b[i]=='1')	{
			if(b[i-1]=='0' && b[i-2]=='0' && b[i-3]=='0' && b[i-4]=='0')	{
				temp=INT_MIN;
				for(int j=0;j<5;j++)	{
					temp=max(temp,a[i-j]);
				}
				l=max(l,temp+1);
			}		
		}
	}
	cout<<l<<" "<<r<<endl;
	return 0;
}