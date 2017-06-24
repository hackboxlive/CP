#include <bits/stdc++.h>
using namespace std;
struct node	{
	int v;
};
int weights[1001000];
vector<vector<node> >tree(1001000); 
int cumw[1001000];
int nn1,nn2;
int mainsrc;
void dfs1(int src)	{
//	cout<<"AT src= "<<src<<"\n";
	for(int i=0;i<tree[src].size();i++)	{
		dfs1(tree[src][i].v);
	}
	int vv;
	cumw[src]=weights[src];
	for(int i=0;i<tree[src].size();i++)	{
		vv=tree[src][i].v;
		cumw[src]+=cumw[vv];
	}
//	cout<<"cumw="<<cumw[src];
	return;
}
void dfs2(int src,int cc)	{
	if(cumw[src]==cc && src!=mainsrc)	{
		nn1=src;
	}
	for(int i=0;i<tree[src].size();i++)	{
		dfs2(tree[src][i].v,cc);
	}
	return;
}
void dfsupdate(int src)	{
	if(src==nn1)	{
		cumw[src]=0;
		return;
	}
	for(int i=0;i<tree[src].size();i++)	{
		dfsupdate(tree[src][i].v);
	}
	int vv;
	cumw[src]=weights[src];
	for(int i=0;i<tree[src].size();i++)	{
		vv=tree[src][i].v;
		cumw[src]+=cumw[vv];
	}
	return;
}
void dfs3(int src,int cc)	{
	if(src==nn1)	{
		return;
	}
	if(cumw[src]==cc && src!=mainsrc)	{
		nn2=src;
	}
	for(int i=0;i<tree[src].size();i++)	{
		dfs3(tree[src][i].v,cc);
	}
	return;
}
int main()	{
	int n;
	node temp;
	scanf("%d",&n);
	int v,w;
	for(int i=1;i<=n;i++)	{
		scanf("%d%d",&v,&w);
		if(v==0)	{
			mainsrc=i;
		}
		temp.v=i;
//		temp.w=w;
		weights[i]=w;
		tree[v].push_back(temp);
	}
	dfs1(mainsrc);
//	for(int i=0;i<=n;i++)	{
//		cout<<cumw[i]<<" ";
//	}
	if(cumw[mainsrc]%3!=0)	{
		cout<<"-1\n";
		return 0;
	}
	int cc=cumw[mainsrc]/3;
	nn1=-1;
	dfs2(mainsrc,cc);
//	cout<<nn1<<endl;
	if(nn1!=-1)	{
		dfsupdate(mainsrc);
//		for(int i=0;i<=n;i++)	{
//			cout<<cumw[i]<<" ";
//		}
		nn2=-1;
		dfs3(mainsrc,cc);
		if(nn2!=-1)	{
			cout<<nn1<<" "<<nn2<<"\n";
		}
		else	{
			cout<<"-1\n";
		}
	}
	else	{
		cout<<"-1\n";
	}
	return 0;
}