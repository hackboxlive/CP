#include <bits/stdc++.h>
using namespace std;
long long int lcm[300100];
int arr[100100];
long long small[300100];
void sieve() {
	int mod=1000000007;
	lcm[0]=0,lcm[1]=1;
	for(int i=2;i<300100;++i)	{
		if(!small[i]){
			for(int j=i;j<300100;j+=i)	{
				small[j]=i;
			}
		}
		int p=small[i],j;
		for(j=i;j%p==0;j/=p);
		if(j==1)
			lcm[i]=(lcm[i-1]*(long long)p)%mod;
		else
			lcm[i]=lcm[i-1];
	}
	return;
}
struct node	{
	int maxim;
	int minim;
	int lazy;
}tree[600600];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].maxim=arr[l];
		tree[id].minim=arr[l];
		tree[id].lazy=0;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].maxim=max(tree[2*id].maxim,tree[2*id+1].maxim);
	tree[id].minim=min(tree[2*id].minim,tree[2*id+1].minim);
	tree[id].lazy=0;
	return;
}
void update_lazy(int id,int l,int r)	{
	if(tree[id].lazy>0)	{
		tree[id].maxim+=tree[id].lazy;
		tree[id].minim+=tree[id].lazy;
		if(l!=r)	{
			tree[2*id].lazy+=tree[id].lazy;
			tree[2*id+1].lazy+=tree[id].lazy;
		}
		tree[id].lazy=0;
	}
	return;
}
void update_tree(int id,int start,int end,int l,int r,int val)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		tree[id].maxim+=val;
		tree[id].minim+=val;
		if(start!=end)	{
			tree[2*id].lazy+=val;
			tree[2*id+1].lazy+=val;
		}
		return;
	}
	update_tree(2*id,start,(start+end)/2,l,r,val);
	update_tree(2*id+1,(start+end)/2+1,end,l,r,val);
	tree[id].maxim=max(tree[2*id].maxim,tree[2*id+1].maxim);
	tree[id].minim=min(tree[2*id].minim,tree[2*id+1].minim);
	return;
}
node query_tree(int id,int start,int end,int l,int r)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		node nullnode;
		nullnode.minim=1000000000;
		nullnode.maxim=-1000000000;
		return nullnode;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	node p=query_tree(2*id,start,(start+end)/2,l,r);
	node q=query_tree(2*id+1,(start+end)/2+1,end,l,r);
	node rr;
	rr.maxim=max(p.maxim,q.maxim);
	rr.minim=min(p.minim,q.minim);
	return rr;
}
int main()	{
	sieve();
	int n,q;
	int ch,l,r,p;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	build_tree(1,0,n-1);
	while(q--)	{
		scanf("%d",&ch);
		if(ch==0)	{
			scanf("%d%d%d",&l,&r,&p);
			update_tree(1,0,n-1,l,r,p);
		}
		else	{
			scanf("%d%d",&l,&r);
			node ans=query_tree(1,0,n-1,l,r);
			if(ch==1)	{
				printf("%lld\n",lcm[ans.maxim]);
			}
			else	{
				printf("%lld\n",lcm[ans.minim]);
			}
		}
	}
	return 0;
}