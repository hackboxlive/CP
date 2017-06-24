#include <bits/stdc++.h>
using namespace std;
int arr[100100];
struct node	{
	long long int tot;
	int minapple;
}tree[400100];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].tot=arr[l];
		tree[id].minapple=arr[l];
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].tot=tree[2*id].tot+tree[2*id+1].tot;
	tree[id].minapple=min(tree[2*id].minapple,tree[2*id+1].minapple);
	return;
}
void eat(int id,int start,int end,int lr,int val)	{
	if(start>lr || end<lr)	{
		return;
	}
	if(start==lr && end==lr)	{
		tree[id].tot-=val;
		tree[id].minapple=tree[id].tot;
		return;
	}
	eat(2*id,start,(start+end)/2,lr,val);
	eat(2*id+1,(start+end)/2+1,end,lr,val);
	tree[id].tot=tree[2*id].tot+tree[2*id+1].tot;
	tree[id].minapple=min(tree[2*id].minapple,tree[2*id+1].minapple);
	return;
}
void grow(int id,int start,int end,int lr,int val)	{
	if(start>lr || end<lr)	{
		return;
	}
	if(start==lr && end==lr)	{
		tree[id].tot+=val;
		tree[id].minapple=tree[id].tot;
		return;
	}
	grow(2*id,start,(start+end)/2,lr,val);
	grow(2*id+1,(start+end)/2+1,end,lr,val);
	tree[id].tot=tree[2*id].tot+tree[2*id+1].tot;
	tree[id].minapple=min(tree[2*id].minapple,tree[2*id+1].minapple);
	return;
}
node countapple(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		node k;
		k.tot=-1;
		k.minapple=-1;
		return k;
	}
//	cout<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
	if(start>=l && end<=r)	{
		return tree[id];
	}
	node p=countapple(2*id,start,(start+end)/2,l,r);
	node q=countapple(2*id+1,(start+end)/2+1,end,l,r);
	if(p.tot==-1)	{
		return q;
	}
	if(q.tot==-1)	{
		return p;
	}
	node rr;
//	cout<<start<<" "<<end<<" "<<p.tot<<" "<<p.minapple<<" "<<q.tot<<" "<<q.minapple<<endl;
	rr.tot=p.tot+q.tot;
	rr.minapple=min(p.minapple,q.minapple);
	return rr;
}
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	build_tree(1,0,n-1);
//	for(int i=0;i<2*n;i++)	{
//		cout<<tree[i].tot<<" "<<tree[i].minapple<<endl;
//	}
	int p,x,y;
	node t;
	char ch[10];
	scanf("%d",&p);
	while(p--)	{
		scanf("%s",ch);
		if(ch[0]=='E')	{
			scanf("%d%d",&x,&y);
			eat(1,0,n-1,y,x);
		}
		if(ch[0]=='G')	{
			scanf("%d%d",&x,&y);
			grow(1,0,n-1,y,x);
		}
		if(ch[0]=='C')	{
			scanf("%d%d",&x,&y);
			t=countapple(1,0,n-1,x,y);
			printf("%lld\n",t.tot-t.minapple);
		}
	}
}