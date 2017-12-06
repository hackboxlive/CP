#include <bits/stdc++.h>
using namespace std;
int arr[1010];
int main()	{
	int n,m,c;
	cin>>n>>m>>c;
	while(m--)	{
		int x;
		cin>>x;
		if(c/2>=x)	{
			for(int i=1;i<=n;i++)	{
				if(arr[i]==0 || arr[i]>x)	{
					arr[i]=x;
					cout<<i<<endl;
					fflush(stdout);
					break;
				}
			}
		}
		else	{
			for(int i=n;i>0;i--)	{
				if(arr[i]==0 || arr[i]<x)	{
					arr[i]=x;
					cout<<i<<endl;
					fflush(stdout);
					break;
				}
			}
		}
		int f=0;
		for(int i=1;i<=n;i++)	{
			if(arr[i])	{
				f++;
			}
		}
		if(f==n)	{
			break;
		}
	}
	return 0;
}