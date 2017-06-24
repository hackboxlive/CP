#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[15100];
struct node	{
	int sum;
	int index;
}prefix[15100];
int pivot[15100];
int sortedprefix[15100];
int treemin[6*15100],treemax[6*151000];
struct comp1	{
	bool operator()(const node &p1,const node &p2)	{
		return p1.sum<p2.sum;
	}
}obj1;
struct comp2	{
	bool operator()(const node &p1,const node &p2)	{
		return p1.index<p2.index;
	}
}obj2;
void build_min(int id=1,int l=0,int r=n)	{
	if(l==r)	{
		treemin[id]=1e9;
		return;
	}
	build_min(2*id,l,(l+r)/2);
	build_min(2*id+1,(l+r)/2+1,r);
	treemin[id]=1e9;
}
void update_min(int id,int start,int end,int pos,int val)	{
	if(start>pos || end<pos)	{
		return;
	}
	if(pos==start && pos==end)	{
		treemin[id]=val;
		return;
	}
	update_min(2*id,start,(start+end)/2,pos,val);
	update_min(2*id+1,(start+end)/2+1,end,pos,val);
	treemin[id]=min(treemin[2*id],treemin[2*id+1]);
}
int query_min(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return 1e9;
	}
	if(start>=l && end<=r)	{
		return treemin[id];
	}
	return min(query_min(2*id,start,(start+end)/2,l,r),query_min(2*id+1,(start+end)/2+1,end,l,r));
}
void build_max(int id=1,int l=0,int r=n)	{
	if(l==r)	{
		treemax[id]=-1e9;
		return;
	}
	build_max(2*id,l,(l+r)/2);
	build_max(2*id+1,(l+r)/2+1,r);
	treemax[id]=-1e9;
}
void update_max(int id,int start,int end,int pos,int val)	{
	if(start>pos || end<pos)	{
		return;
	}
	if(start==pos && end==pos)	{
		treemax[id]=val;
		return;
	}
	update_max(2*id,start,(start+end)/2,pos,val);
	update_max(2*id+1,(start+end)/2+1,end,pos,val);
	treemax[id]=max(treemax[2*id],treemax[2*id+1]);
}
int query_max(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return -1e9;
	}
	if(start>=l && end<=r)	{
		return treemax[id];
	}
	return max(query_max(2*id,start,(start+end)/2,l,r),query_max(2*id+1,(start+end)/2+1,end,l,r));
}
void precompute()	{
	sort(prefix,prefix+(n+1),obj1);
	for(int i=0;i<=n;i++)	{
		sortedprefix[i]=prefix[i].sum;
		pivot[prefix[i].index]=i;
	}
	sort(prefix,prefix+(n+1),obj2);
}
int search_in_sorted(int val)	{
	int lo=0;
	int hi=n;
	int mid;
	while(lo<hi)	{
		mid=(lo+hi)/2;
		if(sortedprefix[mid]<val)	{
			lo=mid+1;
		}
		else	{
			hi=mid;
		}
	}
	return lo;
}
int getmin(int m)	{
	int val,ptr;
	build_min();
	update_min(1,0,n,pivot[0],0);
	for(int i=1;i<=n;i++)	{
		val=prefix[i].sum-m;
		ptr=search_in_sorted(val);
		val=query_min(1,0,n,ptr,n);
		update_min(1,0,n,pivot[i],val+1);
	}
	return val+1;
}
int getmax(int m)	{
	int val,ptr;
	build_max();
	update_max(1,0,n,pivot[0],0);
	for(int i=1;i<=n;i++)	{
		val=prefix[i].sum-m;
		ptr=search_in_sorted(val);
		val=query_max(1,0,n,ptr,n);
		update_max(1,0,n,pivot[i],val+1);
	}
	return val+1;
}
bool possible(int m)	{
	int f=getmin(m);
	int g=getmax(m);
	if(k>=f && k<=g)	{
		return true;
	}
	return false;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d",&n,&k);
		prefix[0].sum=0;
		prefix[0].index=0;
		for(int i=1;i<=n;i++)	{
			scanf("%d",&arr[i]);
			prefix[i].sum=prefix[i-1].sum+arr[i];
			prefix[i].index=i;
		}
		precompute();
		int hi=1e9,lo=-1e9,mid;
		while(lo+1<hi)	{
			mid=(lo+hi)/2;
			if(possible(mid))	{
				hi=mid;
			}
			else	{
				lo=mid;
			}
		}
		printf("%d\n",hi);
	}
	return 0;
}