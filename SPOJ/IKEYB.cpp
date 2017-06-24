#include <bits/stdc++.h>
using namespace std;
int weights[100];
int mat[100][100];
vector<int> vv;
vector<int> st;
int main()	{
	int t;
	string kk,ll;
	int k,l;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)	{
		scanf("%d%d",&k,&l);
		cin>>kk;
		cin>>ll;
		for(int i=1;i<=l;i++)	{
			scanf("%d",&weights[i]);
		}
		mat[1][1]=weights[1];
		for(int i=2;i<=l;i++)	{
			mat[1][i]=mat[1][i-1]+weights[i]*i;
		}
		for(int i=2;i<=k;i++)	{
			mat[i][1]=mat[i-1][1];
		}
//		int ctr=0;
		for(int i=2;i<=k;i++)	{
			for(int j=2;j<=l;j++)	{
				int cum_sum=0;
				int minn=1e9;
				int ccc=0;
				int pos;
				for(int p=j;p>1;p--)	{
					cum_sum=cum_sum+weights[p];
					ccc=ccc+cum_sum;
					if(mat[i-1][p-1]+ccc<minn)	{
						minn=mat[i-1][p-1]+ccc;
						pos=p-1;
					}
				}
				mat[i][j]=minn;
				vv.push_back(pos);
			}
		}
		int sd=l;
		st.push_back(l);
		for(int i=vv.size()-1;i>=0;)	{
			st.push_back(vv[i-(l-sd)]);
			sd=vv[i-(l-sd)];
			i=i-(l-1);
		}
		printf("Keypad #%d:\n",tt);
		int ctr=0;
		for(int i=st.size()-1;i>=0;i--)	{
			printf("%c: ",kk[st.size()-1-i]);
			for(int j=ctr;j<st[i];j++)	{
				printf("%c",ll[j]);
			}
			ctr=st[i];
			printf("\n");
		}
		st.clear();
		vv.clear();
		cout<<endl;
	}
	return 0;
}