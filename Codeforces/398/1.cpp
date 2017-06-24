#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int vis[100100];
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	int ctr=n;
	for(int i=0;i<n;i++)	{
		if(arr[i]==ctr)	{
			vis[arr[i]]=1;
			while(true)	{
				if(vis[ctr]==1)	{
					cout<<ctr<<" ";
					ctr--;
				}
				else	{
					break;
				}
			}
			cout<<endl;
		}
		else	{
			cout<<endl;
			vis[arr[i]]=1;
		}
	}
	return 0;
}