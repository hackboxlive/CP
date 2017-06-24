#include <bits/stdc++.h>
using namespace std;
long long int a[260],b[260],c[260][2];
int n,m;
int maxmatching()	{
	int cnt=0;
	for(int i=0;i<n;i++)	{
		for(int j=0;j<m;j++)	{
			if(b[j]>=c[i][0] && b[j]<=c[i][1])	{
				cnt++;
			}
		}
	}
	return cnt;
}
void printc()	{
	for(int i=0;i<n;i++)	{
		cout<<c[i][0]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)	{
		cout<<c[i][1]<<" ";
	}
	cout<<endl;
}
int main()	{
	int t;
	cin>>t;
	int e;
	while(t--)	{
		cin>>n>>m>>e;
		for(int i=0;i<n;i++)	{
			cin>>a[i];
		}
		for(int i=0;i<m;i++)	{
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++)	{
			c[i][0]=a[i]-e;
			c[i][1]=a[i]+e;
		}
		long long diff;
		int ans=maxmatching();
		int maxx;
//		cout<<ans<<endl;
		for(int i=0;i<n;i++)	{
			diff=a[i]-b[0];
			for(int j=0;j<n;j++)	{
				c[j][0]=a[j]-diff;
				c[j][1]=a[j]-diff+2*e;
			}
			printc();
			maxx=maxmatching();
			cout<<maxx<<endl;
			ans=max(ans,maxx);
			for(int j=0;j<n;j++)	{
				c[j][0]=a[j]-diff-2*e;
				c[j][1]=a[j]-diff;
			}
			printc();
			maxx=maxmatching();
			cout<<maxx<<endl;
			ans=max(ans,maxx);
		}
		cout<<ans<<endl;
	}
	return 0;
}