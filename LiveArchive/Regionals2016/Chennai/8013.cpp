#include <bits/stdc++.h>
using namespace std;
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)	{
		int n,m,ct;
		cin>>n>>m;
		int mat[n][m];
		cin>>ct;
		int arr[ct];
		int tot=0;
		for(int i=0;i<ct;i++)	{
			cin>>arr[i];
			tot+=arr[i];
		}
		int dir=1;
		int r=0;
		int c=0;
		int team=0;
		while(tot--)	{
			mat[r][c]=team+1;
			arr[team]--;
			if(arr[team]==0)	{
				team++;
			}
			if(dir==1)	{
				c++;
				if(c==m)	{
					c=m-1;
					r++;
					dir*=-1;
				}
			}
			else	{
				c--;
				if(c==-1)	{
					c=0;
					r++;
					dir*=-1;
				}
			}
		}
		for(int i=0;i<n;i++)	{
			for(int j=0;j<m;j++)	{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}