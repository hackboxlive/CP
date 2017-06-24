#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int arr[100100];
int actual[100100];
struct node	{
	int l,r,k,id;
}query[100100];
int block_size=310;
int freq[100100];
int tree[600600];
int ans[100100];
int inp()	{
	register int n = 0;
	char ch = getchar_unlocked();
	while(ch < '0' || ch > '9')	{
		ch = getchar_unlocked();
	}
	while(ch >= '0' && ch <= '9')	{
		n = (n<<3) + (n<<1) + (ch-'0');
		ch=getchar_unlocked();
	}
	return n;
}
/*bool comp(const node &p1,const node &p2)	{
	if(p1.l/block_size==p2.l/block_size)	{
		return p1.r<p2.r;
	}
	return p1.l<p2.l;
}*/
int comp2(const void *a,const void *b)	{
	if((((struct node *)a)->l)/block_size==(((struct node *)b)->l)/block_size)	{
		return ((struct node *)a)->r - ((struct node *)b)->r;
	}
	return ((struct node *)a)->l-((struct node *)b)->l;
}
void update_tree(int id,int l,int r,int pos,int val)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id]+=val;
		return;
	}
	update_tree(2*id,l,(l+r)/2,pos,val);
	update_tree(2*id+1,(l+r)/2+1,r,pos,val);
	tree[id]=tree[2*id]+tree[2*id+1];
	return;
}
int query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return query_tree(2*id,start,(start+end)/2,l,r)+query_tree(2*id+1,(start+end)/2+1,end,l,r);
}
void add(int pos,int n)	{
	if(freq[arr[pos]]>0)	{
		update_tree(1,1,n,freq[arr[pos]],-1);
	}
	freq[arr[pos]]++;
	update_tree(1,1,n,freq[arr[pos]],1);
	return;
}
void removee(int pos,int n)	{
	update_tree(1,1,n,freq[arr[pos]],-1);
	freq[arr[pos]]--;
	if(freq[arr[pos]]>0)	{
		update_tree(1,1,n,freq[arr[pos]],1);
	}
	return;
}
int main()	{
	int t;
	int n,q;
//	t=inp();
	int i;
	scanf("%d",&t);
	while(t--)	{
		memset(freq,0,sizeof(freq));
		memset(tree,0,sizeof(tree));
		scanf("%d %d",&n,&q);
//		n=inp();
//		q=inp();
//		block_size=sqrt(n);
		for(i=0;i<n;i++)	{
//			actual[i]=inp();
			scanf("%d",&actual[i]);
		}
		arr[0]=1;
		for(i=1;i<n;i++)	{
			if(actual[i]==actual[i-1])	{
				arr[i]=arr[i-1];
			}
			else	{
				arr[i]=arr[i-1]+1;
			}
		}
		for(i=0;i<q;i++)	{
			scanf("%d %d %d",&query[i].l,&query[i].r,&query[i].k);
//			query[i].l=inp();
//			query[i].r=inp();
//			query[i].k=inp();
			query[i].l--;
			query[i].r--;
			query[i].id=i;
		}
//		sort(query,query+q,comp);
		qsort(query,q,sizeof(struct node),comp2);
		int curl=query[0].l;
		int curr=curl;
		int L,R,K;
		for(curr=curl;curr<=query[0].r;curr++)	{
			add(curr,n);
		}
		curr--;
		ans[query[0].id]=query_tree(1,1,n,query[0].k,n);
		for(i=1;i<q;i++)	{
			L=query[i].l;
			R=query[i].r;
			K=query[i].k;
			while(curl<L)	{
				removee(curl,n);
				curl++;
			}
			while(curl>L)	{
				add(curl-1,n);
				curl--;
			}
			while(curr<R)	{
				add(curr+1,n);
				curr++;
			}
			while(curr>R)	{
				removee(curr,n);
				curr--;
			}
			ans[query[i].id]=query_tree(1,1,n,K,n);
		}
		for(i=0;i<q;i++)	{
//			cout<<ans[i]<<endl;
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}