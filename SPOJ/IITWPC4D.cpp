#include <bits/stdc++.h>
using namespace std;
int height[100100];
int shorter[100100];
int newarr[100100];
int check[100100];
struct node	{
	int diff;
	int lazy;
	bool tocount;
}tree[600600];
int retval;
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].lazy=0;
		tree[id].diff=l - shorter[l];
		tree[id].tocount=true;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].lazy=0;
	tree[id].diff=min(tree[2*id].diff,tree[2*id+1].diff);
	tree[id].tocount=true;
	return;
}
void update_lazy(int id,int l,int r)	{
	if(tree[id].lazy != 0)	{
		tree[id].diff-=tree[id].lazy;
		if(l!=r)	{
			tree[2*id].lazy+=tree[id].lazy;
			tree[2*id+1].lazy+=tree[id].lazy;
		}
		tree[id].lazy=0;
	}
	return;
}
void update_tree(int id,int start,int end,int l,int r)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		tree[id].lazy++;
		return;
	}
	update_tree(2*id,start,(start+end)/2,l,r);
	update_tree(2*id+1,(start+end)/2+1,end,l,r);
	update_lazy(2*id,start,(start+end)/2);
	update_lazy(2*id+1,(start+end)/2+1,end);
	if(tree[2*id].tocount==true && tree[2*id+1].tocount==true)	{
		tree[id].diff=min(tree[2*id].diff,tree[2*id+1].diff);
	}
	if(tree[2*id].tocount==true && tree[2*id+1].tocount==false)	{
		tree[id].diff=tree[2*id].diff;
	}
	if(tree[2*id].tocount==false && tree[2*id+1].tocount==true)	{
		tree[id].diff=tree[2*id+1].diff;
	}
	if(tree[2*id].tocount==false && tree[2*id+1].tocount==false)	{
		tree[id].tocount=false;
	}
	return;
}
void query_tree(int id,int l,int r)	{
	update_lazy(id,l,r);
	if(l==r)	{
		retval=l;
		tree[id].tocount=false;
		return;
	}
	update_lazy(2*id,l,(l+r)/2);
	update_lazy(2*id+1,(l+r)/2+1,r);
	if(tree[2*id+1].diff == 0 && tree[2*id+1].tocount == true)	{
		query_tree(2*id+1,(l+r)/2+1,r);
	}
	else	{
		query_tree(2*id,l,(l+r)/2);
	}
	if(tree[2*id].tocount==true && tree[2*id+1].tocount==true)	{
		tree[id].diff=min(tree[2*id].diff,tree[2*id+1].diff);
	}
	if(tree[2*id].tocount==true && tree[2*id+1].tocount==false)	{
		tree[id].diff=tree[2*id].diff;
	}
	if(tree[2*id].tocount==false && tree[2*id+1].tocount==true)	{
		tree[id].diff=tree[2*id+1].diff;
	}
	if(tree[2*id].tocount==false && tree[2*id+1].tocount==false)	{
		tree[id].tocount=false;
	}
	return;
}
int main()	{
	int n,t;
	int cc=1;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		int flag=0;
		for(int i=0;i<n;i++)	{
			scanf("%d",&shorter[i]);
			if(i-shorter[i]<0)	{
				flag=1;
			}
		}
		printf("Test : %d\n",cc++);
		if(flag==1)	{
			printf("-1\n");
			continue;
		}
		build_tree(1,0,n-1);
		for(int i=0;i<n;i++)	{
			query_tree(1,0,n-1);
			newarr[retval]=i+1;
			update_tree(1,0,n-1,retval+1,n-1);
		}
		for(int i=1;i<=n;i++)	{
			check[i]=0;
		}
		for(int i=0;i<n;i++)	{
			check[newarr[i]]=1;
		}
		for(int i=0;i<n;i++)	{
			printf("%d ",newarr[i]);
		}
		printf("\n");
	}
	return 0;
}