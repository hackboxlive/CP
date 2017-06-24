#include <bits/stdc++.h>
using namespace std;
int arr[5100];
int xorval[5100][5100];
int lights[5100];
int dp[5100];
int check[5100];
void precompute(int n)	{
	int val;
	for(int i=0;i<n;i++)	{
		memset(check,0,sizeof(check));
		val=0;
		for(int j=i;j<n;j++)	{
			if(check[arr[j]]==0)	{
				val^=arr[j];
				check[arr[j]]=1;
			}
			xorval[i][j]=val;
		}
	}
}
int find_first(int val,int n)	{
	for(int i=0;i<n;i++)	{
		if(arr[i]==val)	{
			return i;
		}
	}
}
int find_last(int val,int n)	{
	for(int i=n-1;i>=0;i--)	{
		if(arr[i]==val)	{
			return i;
		}
	}
	return -1;
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	precompute(n);
	int ans=0;
	int firstpos,lastpos;
	int sumterm;
	int tempans;
	for(int i=0;i<n;i++)	{
		tempans=0;
		firstpos=find_first(arr[i],n);
		lastpos=find_last(arr[i],i);
		for(int j=firstpos;j>=0;j--)	{
			if(lights[j]==0)	{
				cout<<"j="<<j<<" and i="<<i<<" ";
				if(j==0)	{
					cout<<xorval[j][i]<<endl;
					if(xorval[j][i]>ans)	{
						ans=xorval[j][i];
					}
					if(xorval[j][i]>tempans)	{
						tempans=xorval[j][i];
					}
				}
				else	{
					cout<<xorval[j][i]+dp[j-1]<<endl;
					if(xorval[j][i]+dp[j-1]>ans)	{
						ans=xorval[j][i]+dp[j-1];
					}
					if(xorval[j][i]+dp[j-1]>tempans)	{
						tempans=xorval[j][i]+dp[j-1];
					}
				}
			}
		}
		dp[i]=tempans;
		if(firstpos!=i)	{
			for(int j=firstpos+1;j<=i;j++)	{
				lights[j]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}