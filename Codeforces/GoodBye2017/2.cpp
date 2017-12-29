#include <bits/stdc++.h>
using namespace std;
int main()	{
	int mat[55][55];
	char dir[]={'D','L','R','U'};
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=0;i<55;i++)	{
		for(int j=0;j<55;j++)	{
			mat[i][j]='#';
		}
	}
	int l,r;
	int x,y;
	for(int i=1;i<=n;i++)	{
		cin>>s;
		for(int j=1;j<=m;j++)	{
			mat[i][j]=s[j-1];
			if(s[j-1]=='S')	{
				l=i;
				r=j;
			}
			if(s[j-1]=='E')	{
				x=i;
				y=j;
			}
		}
	}
	string move;
	cin>>move;
	int ans=0;
	for(int i=0;i<24;i++)	{
		// for(int j=0;j<4;j++)	{
		// 	cout<<dir[j]<<" ";
		// }
		// cout<<endl;
		int xx=l;
		int yy=r;
		for(int j=0;j<move.length();j++)	{
			if(dir[move[j]-'0']=='U')	{
				xx--;
			}
			if(dir[move[j]-'0']=='D')	{
				xx++;
			}
			if(dir[move[j]-'0']=='L')	{
				yy--;
			}
			if(dir[move[j]-'0']=='R')	{
				yy++;
			}
			if(mat[xx][yy]=='#')	{
				break;
			}
			if(mat[xx][yy]=='E')	{
				ans++;
				break;
			}
		}
		// cout<<ans<<endl;
		next_permutation(dir,dir+4);
	}
	cout<<ans<<endl;
	return 0;
}