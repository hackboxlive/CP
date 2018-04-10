#include <bits/stdc++.h>
using namespace std;
long long a[10010],p[10010];
long long d[10010];
int main()	{
	long long n,m,k;
	srand(time(NULL));
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)	{
		cin>>p[i];
		d[i]=rand()%k;
		a[i]+=d[i];
	}
	for(int i=0;i<n;i++)	{
		cout<<a[i]<<" ";
	}
	return 0;
}