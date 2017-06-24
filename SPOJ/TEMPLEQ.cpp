#include <bits/stdc++.h>
using namespace std;
struct element	{
	int val;
	int pos;
}arr1[100100];
int arr2[100100];
struct node	{
	int minval;
	int maxval;
}tree[800400];
int lazy[800400];
int n;
int ini,nn;
bool comp(const element &e1,const element &e2)	{
	return e1.val<e2.val;
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].minval=tree[id].maxval=arr1[l].val;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].minval=tree[2*id].minval;
	tree[id].maxval=tree[2*id+1].maxval;
	return;
}
void update_children(int id,int l,int r)	{
	if(lazy[id]>0)	{
		tree[id].minval-=lazy[id];
		tree[id].maxval-=lazy[id];
		if(l!=r)	{
			lazy[2*id]+=lazy[id];
			lazy[2*id+1]+=lazy[id];
		}
		lazy[id]=0;
	}
	return;
}
int findlastoccurence(int id,int l,int r,int val)	{
	update_children(2*id,l,(l+r)/2);
	update_children(2*id+1,(l+r)/2+1,r);
	if(l==r)	{
		nn=l;
		return id;
	}
	if(tree[2*id+1].minval>val)	{
		return findlastoccurence(2*id,l,(l+r)/2,val);
	}
	else	{
		return findlastoccurence(2*id+1,(l+r)/2+1,r,val);
	}
}
void updatetree(int id)	{
	while(id!=1)	{
		id=id/2;
		tree[id].minval=tree[2*id].minval;
		tree[id].maxval=tree[2*id+1].maxval;
	}
	return;
}
void update_point(int id,int l,int r,int pos)	{
	update_children(2*id,l,(l+r)/2);
	update_children(2*id+1,(l+r)/2+1,r);
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		int a=findlastoccurence(1,0,n-1,tree[id].minval);
		tree[id].minval++;
		tree[id].maxval++;
		if(id!=a)	{
			int temp=tree[a].minval;
			tree[a].minval=tree[id].minval;
			tree[id].minval=temp;
			temp=tree[a].maxval;
			tree[a].maxval=tree[id].maxval;
			tree[id].maxval=temp;
			ini=l;
			temp=arr2[ini];
			arr2[ini]=arr2[nn];
			arr2[nn]=temp;
		}
		updatetree(a);
		return;
	}
	update_point(2*id,l,(l+r)/2,pos);
	update_point(2*id+1,(l+r)/2+1,r,pos);
	return;
}
int query_tree(int id,int l,int r,int val)	{
	update_children(2*id,l,(l+r)/2);
	update_children(2*id+1,(l+r)/2+1,r);
	if(l==r)	{
		if(val<=tree[id].minval)	{
			return 1;
		}
		else	{
			return 0;
		}
	}
	if(tree[2*id+1].minval>=val)	{
		return query_tree(2*id,l,(l+r)/2,val)+(r-((l+r)/2+1)+1);
	}
	else	{
		return query_tree(2*id+1,(l+r)/2+1,r,val);
	}
}
void update_lazy(int id,int l,int r,int val)	{
	if(val>tree[id].maxval)	{
		return;
	}
	update_children(2*id,l,(l+r)/2);
	update_children(2*id+1,(l+r)/2+1,r);
//	update_children(id,l,r);
	if(l==r)	{
		tree[id].minval--;
		tree[id].maxval--;
		return;
	}
	if(tree[2*id].maxval>=val)	{
		lazy[2*id+1]++;
		update_lazy(2*id,l,(l+r)/2,val);
	}
	else	{
		update_lazy(2*id+1,(l+r)/2+1,r,val);
	}
	update_children(2*id,l,(l+r)/2);
	update_children(2*id+1,(l+r)/2+1,r);
	tree[id].maxval=tree[2*id+1].maxval;
	tree[id].minval=tree[2*id].minval;
	return;
}
int main()	{
	int q;
	scanf("%d%d",&n,&q);
	memset(lazy,0,4*n*sizeof(int));
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr1[i].val);
		arr1[i].pos=i;
	}
	sort(arr1,arr1+n,comp);
	for(int i=0;i<n;i++)	{
		arr2[arr1[i].pos]=i;
	}
	int x,y;
	build_tree(1,0,n-1);
	while(q--)	{
		scanf("%d%d",&x,&y);
		if(x==1)	{
			update_children(1,0,n-1);
			update_point(1,0,n-1,arr2[y-1]);
		}
		else if(x==2)	{
			update_children(1,0,n-1);
			int sum=query_tree(1,0,n-1,y);
			cout<<sum<<endl;
		}
		else	{
			update_children(1,0,n-1);
			update_lazy(1,0,n-1,y);
		}
//		for(int i=1;i<14;i++)	{
//			cout<<tree[i].minval<<" "<<tree[i].maxval<<" "<<lazy[i]<<endl;
//		}
	}
	return 0;
}