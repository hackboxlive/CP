#include <bits/stdc++.h>
using namespace std;
int mat[2600][2600];
int main()	{
	int t;
	cin>>t;
	int n,k,len;
	int val;
	int ctr;
	int ans;
	while(t--)	{
		cin>>n>>k;
		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;i++)	{
			cin>>len;
			for(int j=0;j<len;j++)	{
				cin>>val;
				mat[i][val-1]=1;
			}
		}
		ans=0;
		for(int i=0;i<n-1;i++)	{
			for(int j=i+1;j<n;j++)	{
				ctr=0;
				for(int m=0;m<k;m++)	{
					if(mat[i][m]==1 || mat[j][m]==1)	{
						ctr++;
					}
					else	{
						break;
					}
				}
				if(ctr==k)	{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}