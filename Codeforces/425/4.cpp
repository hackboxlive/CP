#include <bits/stdc++.h>
using namespace std;
vector<int> tree[100100];
int par[100100];
int P[100100][40];
int L[100100];
void dfs(int src,int pr,int level)	{
//	cout<<src<<" "<<pr<<endl;
	par[src]=pr;
	L[src]=level;
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=pr)	{
			dfs(tree[src][i],src,level+1);
		}
	}
}
void preprocess(int n)	{
	for(int i=1;i<=n;i++)	{
		for(int j=0;1<<j<n;j++)	{
			P[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++)	{
		P[i][0]=par[i];
	}
	for(int j=1;1<<j<n;j++)	{
		for(int i=1;i<=n;i++)	{
			if(P[i][j-1]!=-1)	{
				P[i][j]=P[P[i][j-1]][j-1];
			}
		}
	}
}
int query(int p,int q)	{
	if(L[p]<L[q])	{
		int temp=p;
		p=q;
		q=temp;
	}
	int logp;
	for(logp=1;1<<logp<=L[p];logp++);
	logp--;
	for(int i=logp;i>=0;i--)	{
		if(L[p]-(1<<i)>=L[q])	{
			p=P[p][i];
		}
	}
	if(p==q)	{
		return p;
	}
	for(int i=logp;i>=0;i--)	{
		if(P[p][i]!=-1 && P[p][i]!=P[q][i])	{
			p=P[p][i];
			q=P[q][i];
		}
	}
	return par[p];
}
int getdist(int s,int t,int lst)	{
	return L[s]+L[t]-2*L[lst]+1;
}
int getval(int s,int f,int t)	{
	int lst=query(s,t);
	int lsf=query(s,f);
	int ltf=query(t,f);
	if(lsf==f && ltf==t && lst==t)	{
		return 1;
	}
	if(lsf==f && lft!=f && lft!=t && query(lft,s)==lft)	{
		return 1;
	}
	if(lsf==f && lft==f && lst==f)	{
		return 1;
	}
	if(lsf!=s && lsf!=f && lft==f)	{
		return 1;
	}
	if(lsf==s && lst==s && ltf==s)	{
		return 1;
	}
}
int main()	{
	int n,q;
	cin>>n>>q;
	int u;
	for(int i=2;i<=n;i++)	{
		cin>>u;
		tree[u].push_back(i);
		tree[i].push_back(u);
	}
	dfs(1,1,0);
	preprocess(n);
	int a,b,c;
	int lab,lbc,lca;
	int labc,lbca,lcab;
	int d1,d2,d3;
	int s,f,t;
	while(q--)	{
		cin>>a>>b>>c;
		//for s,f,t
		s=a;f=b;t=c;
		d1=getval(s,f,t);
	}
	return 0;
}