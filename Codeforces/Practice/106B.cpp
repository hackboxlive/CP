#include <bits/stdc++.h>
using namespace std;
struct node	{
	int s;
	int r;
	int h;
	int c;
	int f;
}a[101];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>a[i].s>>a[i].r>>a[i].h>>a[i].c;
		a[i].f=1;
	}
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n;j++)	{
			if(a[i].s<a[j].s && a[i].r<a[j].r && a[i].h<a[j].h)	{
				a[i].f=0;
				break;
			}
		}
	}
	int ans=-1;
	for(int i=0;i<n;i++)	{
		if(a[i].f==1)	{
			if(ans==-1 || a[i].c<a[ans].c)	{
				ans=i;
			}
		}
	}
	cout<<ans+1<<endl;
	return 0;
}