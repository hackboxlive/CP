#include <bits/stdc++.h>
using namespace std;
int arr[202];
const int inf=10007;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,k;
		cin>>n>>k;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<k;i++)	{
			int v;
			cin>>v;
			arr[v]=1;
		}
		int ans=0;

		int water[202];
		//memset(water,inf,sizeof(water));
		for(int i=1;i<=n;i++)	{
			water[i]=100000;
			//cout<<water[i]<<" ";
		}

		for(int i=1;i<=n;i++)	{
			if(arr[i])	{
				for(int j=1;j<=n;j++)	{
					water[j]=min(water[j],abs(j-i)+1);
				}
			}
		}
		for(int i=1;i<=n;i++)	{
			ans=max(ans,water[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}