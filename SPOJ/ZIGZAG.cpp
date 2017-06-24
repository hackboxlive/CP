#include <bits/stdc++.h>
using namespace std;
vector<long long int> arr;
int main()	{
	int n,k;
	scanf("%d%d",&n,&k);
	string s;
	cin>>s;
	long long int val=1;
	for(int i=1;i<=n;i++)	{
		arr.push_back(val);
		val=val+i;
	}
	for(int i=n-1;i>=1;i--)	{
		arr.push_back(val);
		val=val+i;
	}
	int r=0,c=0;
	int rc;
	long long int ssum=1,st,diff;
	for(int i=0;i<k;i++)	{
		if(s[i]=='U')	{
			r--;
		}
		if(s[i]=='D')	{
			r++;
		}
		if(s[i]=='L')	{
			c--;
		}
		if(s[i]=='R')	{
			c++;
		}
		//add value of r,c
		rc=r+c;
		st=arr[rc];
		if(rc<n)	{
			if(rc%2==0)	{
				//going up in upper diagonal
				diff=rc-r;
			}
			else	{
				//going down in upper diagonal
				diff=rc-c;
			}
		}
		else	{
			if(rc%2==0)	{
				//going up in lower diagonal
				diff=n-1-r;
			}
			else	{
				//going down in lower diagonal
				diff=n-1-c;
			}
		}
		ssum+=(st+diff);
	}
	cout<<ssum<<endl;
	return 0;
}