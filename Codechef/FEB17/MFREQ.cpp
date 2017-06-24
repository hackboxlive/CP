#include <bits/stdc++.h>
using namespace std;
struct node	{
	int diff;
	int val;
}tree[600600];
int arr[100100];
void build_tree(int id,int l,int r,int pos,int value)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id].diff=1;
		tree[id].val=value;
		return;
	}
	build_tree(2*id,l,(l+r)/2,pos,value);
	build_tree(2*id+1,(l+r)/2+1,r,pos,value);
	if(tree[2*id].diff==1 && tree[2*id+1].diff==1 && tree[2*id].val==tree[2*id+1].val)	{
		tree[id].diff=1;
		tree[id].val=tree[2*id].val;
		return;
	}
	tree[id].diff=2;
	tree[id].val=-1;
	return;
}
int query_left(int id,int l,int r,int pos,int value)	{
	if(l>pos)	{
		return 0;
	}
	if(r<=pos)	{
		if(tree[id].diff==1)	{
			if(tree[id].val==value)	{
				return r-l+1;
			}
			else	{
				return 0;
			}
		}
		else	{
			int rr=query_left(2*id+1,(l+r)/2+1,r,pos,value);
			if(rr < r-((l+r)/2))	{
				return rr;
			}
			int ll=query_left(2*id,l,(l+r)/2,pos,value);
			return ll+rr;
		}
	}
	return query_left(2*id,l,(l+r)/2,pos,value)+query_left(2*id+1,(l+r)/2+1,r,pos,value);
}
int query_right(int id,int l,int r,int pos,int value)	{
	if(r<pos)	{
		return 0;
	}
	if(l>=pos)	{
		if(tree[id].diff==1)	{
			if(tree[id].val==value)	{
				return r-l+1;
			}
			else	{
				return 0;
			}
		}
		else	{
			int ll=query_right(2*id,l,(l+r)/2,pos,value);
			if(ll < ((l+r)/2)-l+1)	{
				return ll;
			}
			int rr=query_right(2*id+1,(l+r)/2+1,r,pos,value);
			return ll+rr;
		}
	}
	return query_right(2*id,l,(l+r)/2,pos,value)+query_right(2*id+1,(l+r)/2+1,r,pos,value);
}
int main()	{
	int n,m;
	scanf("%d %d",&n,&m);
	int val;
	int l,r,k;
	for(int i=0;i<n;i++)	{
		scanf("%d",&val);
		arr[i]=val;
		build_tree(1,0,n-1,i,val);
	}
	int ctr=0;
	while(m--)	{
		scanf("%d%d%d",&l,&r,&k);
		l--;
		r--;
		val=arr[(l+r)/2];
		ctr=query_left(1,0,n-1,(l+r)/2,val);
		ctr+=query_right(1,0,n-1,(l+r)/2,val);
		ctr--;
		if(ctr>k)	{
			printf("%d\n",val);
		}
		else	{
			printf("-1\n");
		}
	}
	return 0;
}