#include <bits/stdc++.h>
using namespace std;
int arr[1100];
int dp[1100][1100];
int solve(int l,int r)	{
	if(l>r)	{
		return 0;
	}
	if(dp[l][r]!=-1)	{
		return dp[l][r];
	}
	int p,q;
	if(arr[l+1]>=arr[r])	{
		p=arr[l]+solve(l+2,r);
	}
	else	{
		p=arr[l]+solve(l+1,r-1);
	}
	if(arr[l]>=arr[r-1])	{
		q=arr[r]+solve(l+1,r-1);
	}
	else	{
		q=arr[r]+solve(l,r-2);
	}
	dp[l][r]=max(p,q);
	return dp[l][r];
}
int main()	{
	int n;
	scanf("%d",&n);
	for(int tt=1;n!=0;tt++)	{
//		int n;
//		cout<<n;
		int tott=0;
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
			tott+=arr[i];
		}
		for(int i=0;i<n;i++)	{
			for(int j=0;j<n;j++)	{
				dp[i][j]=-1;
			}
		}
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",tt,2*solve(0,n-1)-tott);
//		cout<<tott<<" "<<solve(0,n-1)<<endl;
		scanf("%d",&n);
	}
	return 0;
}