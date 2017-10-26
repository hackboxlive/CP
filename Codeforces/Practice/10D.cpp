#include <bits/stdc++.h>
using namespace std;
int tab[505],a[505],b[505],par[505];
void print(int cur)	{
	if(cur==-1)	{
		return;
	}
	print(par[cur]);
	cout<<b[cur]<<" ";
}
int main()	{
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<m;i++)	{
		cin>>b[i];
		tab[i]=0;
		par[i]=-1;
	}
	for(int i=0;i<n;i++)	{
		int cur=0;
		int p=-1;
		for(int j=0;j<m;j++)	{
			if(a[i]==b[j] && tab[j]<cur+1)	{
				tab[j]=cur+1;
				par[j]=p;
			}
			if(a[i]>b[j] && tab[j]>cur)	{
				cur=tab[j];
				p=j;
			}
		}
	}
	int ans=0;
	bool f=false;
	if(tab[0]!=0)	{
		f=true;
	}
	for(int i=0;i<m;i++)	{
		if(tab[i]>tab[ans])	{
			ans=i;
			f=true;
		}
	}
	if(f==false)	{
		cout<<"0\n";
		return 0;
	}
	cout<<tab[ans]<<endl;
	print(ans);
	cout<<endl;
	return 0;
}