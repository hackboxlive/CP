#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,k;
		cin>>n>>k;
		int l=INT_MIN;
		int r=INT_MAX;
		int v,z;
		cin>>v;
		bool flag=true;
		for(int i=1;i<n;i++)	{
			cin>>z;
			if(z<v)	{
				if(z<l)	{
					flag=false;
				}
				else	{
					r=v;
				}
			}
			else	{
				if(z>r)	{
					flag=false;
				}
				else	{
					l=v;
				}
			}
			v=z;
		}
		if(flag==true)	{
			cout<<"YES\n";
		}
		else	{
			cout<<"NO\n";
		}
	}
	return 0;
}