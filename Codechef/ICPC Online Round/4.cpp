#include <bits/stdc++.h>
using namespace std;
//vector<vector<int> > g(110);
int g2[110][110];
int deg2[110];
int main()	{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	cin>>t;
	int n,m,d,D;
	while(t--)	{
		cin>>n>>m>>d>>D;
		for(int i=1;i<=n;i++)	{
//			g[i].clear();
			deg2[i]=0;
			for(int j=1;j<=n;j++)	{
				g2[i][j]=0;
			}
		}
		if(m<n*d || m>n*D)	{
			cout<<"-1\n";
			continue;
		}
		int ind=1;
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=d;j++)	{
				g2[i][ind]=1;
				deg2[ind]++;
				ind++;
				if(ind>n)	{
					ind=1;
				}
			}
		}
		m=m-n*d;
		int ind1=1;
		while(m)	{
//			cout<<m<<endl;
			int minind=-1;
			int mini=10000000;
			for(int i=1;i<=n;i++)	{
				if(g2[ind1][i]==0 && deg2[i]<mini && deg2[i]<D)	{
					mini=deg2[i];
					minind=i;
				}
			}
//			cout<<mini<<" "<<minind<<endl;
			if(minind==-1)	{
				ind1++;
			}
			else	{
//				g[ind1].push_back(minind);
				deg2[minind]++;
				m--;
				g2[ind1][minind]=1;
				ind1++;
			}
			if(ind1>n)	{
				ind1=1;
			}
		}
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=n;j++)	{
				if(g2[i][j])	{
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	return 0;
}