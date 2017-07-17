#include <bits/stdc++.h>
using namespace std;
int mat[110][110];
int row[110];
int col[110];
int cc[110][110];
void precompute(int n,int m)	{
	for(int i=0;i<n;i++)	{
		int black=0;
		for(int j=0;j<m;j++)	{
			if(mat[i][j]=='B')	{
				black=1;
			}
		}
		if(black==1)	{
			row[i]=1;
		}
		else	{
			row[i]=0;
		}
	}
	for(int i=0;i<m;i++)	{
		int black=0;
		for(int j=0;j<n;j++)	{
			if(mat[j][i]=='B')	{
				black=1;
			}
		}
		if(black==1)	{
			col[i]=1;
		}
		else	{
			col[i]=0;
		}
	}
	memset(cc,0,sizeof(cc));
	for(int i=0;i<n;i++)	{
		for(int j=0;j<m;j++)	{
			cc[i+1][j+1]=cc[i+1][j]+cc[i][j+1]-cc[i][j];
			if(mat[i][j]=='B')	{
				cc[i+1][j+1]++;
			}
		}
	}
	// for(int i=0;i<=n;i++)	{
	// 	for(int j=0;j<=m;j++)	{
	// 		cout<<cc[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
} 
int main()	{
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=0;i<n;i++)	{
		cin>>s;
		for(int j=0;j<m;j++)	{
			mat[i][j]=s[j];
		}
	}
	int minn=1e9;
	int ans;
	precompute(n,m);
	int flag;
	for(int i=0;i<n;i++)	{
		for(int j=0;j<m;j++)	{
			for(int k=0;k<min(n-i,m-j);k++)	{
				flag=0;
				for(int l=0;l<m;l++)	{
					if((l<j || l>j+k) && col[l]==1)	{
						flag=1;
					}
				}
				for(int l=0;l<n;l++)	{
					if((l<i || l>i+k)&& row[l]==1)	{
						flag=1;
					}
				}
				if(flag==0)	{
//					cout<<"true for "<<i<<" "<<j<<" "<<" "<<k<<endl;
					ans=(k+1)*(k+1);
					ans-=(cc[i+k+1][j+k+1]-cc[i][j]);
					if(ans<minn)	{
						minn=ans;
					}
				}
			}
		}
	}
	if(minn==1e9)	{
		cout<<"-1\n";
	}
	else	{
		cout<<minn<<endl;
	}
	return 0;
}