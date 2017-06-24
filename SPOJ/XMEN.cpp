#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > magneto,magneto2;
vector<pair<int,int> > wolverine;
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	return p1.first<p2.first;
}
int tree[600600];
int query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return max(query_tree(2*id,start,(start+end)/2,l,r),query_tree(2*id+1,(start+end)/2+1,end,l,r));
}
void update_tree(int id,int l,int r,int pos,int val)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id]=val;
		return;
	}
	update_tree(2*id,l,(l+r)/2,pos,val);
	update_tree(2*id+1,(l+r)/2+1,r,pos,val);
	tree[id]=max(tree[2*id],tree[2*id+1]);
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		int num;
		for(int i=0;i<n;i++)	{
			scanf("%d",&num);
			magneto.push_back(make_pair(num,i));
			magneto2.push_back(make_pair(num,i));
		}
		for(int i=0;i<n;i++)	{
			scanf("%d",&num);
			wolverine.push_back(make_pair(num,i));
		}
		sort(magneto2.begin(),magneto2.end(),comp);
		for(int i=0;i<n;i++)	{
			wolverine[i].second=magneto2[wolverine[i].first-1].second;
		}
//		for(int i=0;i<n;i++)	{
//			printf("%d %d %d %d\n",magneto[i].first,magneto[i].second,wolverine[i].first,wolverine[i].second);
//		}
		memset(tree,0,sizeof(int)*n*6);
		for(int i=0;i<n;i++)	{
			int u=wolverine[i].second;
			int ans=query_tree(1,0,n-1,0,u-1);
			ans++;
			update_tree(1,0,n-1,u,ans);
		}
		printf("%d\n",tree[1]);
		magneto.clear();
		magneto2.clear();
		wolverine.clear();
	}
	return 0;
}