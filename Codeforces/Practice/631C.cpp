#include <bits/stdc++.h>
using namespace std;
int arr[200200][2];
int finarr[200200];
int q[200200];
int main()	{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)	{
		cin>>q[i];
	}
	int qs=0,rt,type;
	for(int i=0;i<m;i++)	{
		cin>>type>>rt;
		while(qs>0 && rt>=arr[qs-1][1])	{
			qs--;
		}
		arr[qs][0]=type;
		arr[qs][1]=rt;
		qs++;
	}
	int l=0,r=arr[0][1]-1;
	for(int i=n-1;i>r;i--)	{
		finarr[i]=q[i];
	}
	sort(q,q+r+1);
	int cnt,fr=r;
	for(int i=0;i<qs-1;i++)	{
		if(arr[i][0]==1)	{
			cnt=arr[i][1]-arr[i+1][1];
			for(int j=0;j<cnt;j++)	{
				finarr[fr]=q[r];
				fr--;
				r--;
			}
		}
		else	{
			cnt=arr[i][1]-arr[i+1][1];
			for(int j=0;j<cnt;j++)	{
				finarr[fr]=q[l];
				fr--;
				l++;
			}
		}
	}
	for(int i=0;i<=fr;i++)	{
		if(arr[qs-1][0]==1)	{
			finarr[i]=q[l];
			l++;
		}
		else	{
			finarr[i]=q[r];
			r--;
		}
	}
	for(int i=0;i<n;i++)	{
		cout<<finarr[i]<<" ";
	}
	cout<<endl;
	return 0;
}