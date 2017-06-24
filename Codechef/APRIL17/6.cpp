#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int actual[100100];
struct node	{
	int l,r,k,id;
}query[100100];
int block_size;
int freq[100100];
int tree[100100];
int ans[100100];
bool comp(const node &p1,const node &p2)	{
	if(p1.l/block_size==p2.l/block_size)	{
		return p1.r<p2.r;
	}
	return p1.l<p2.l;
}
void add(int pos,int n)	{
	freq[arr[pos]]++;
	tree[freq[arr[pos]]]++;
	return;
}
void remove(int pos,int n)	{
	tree[freq[arr[pos]]]--;
	freq[arr[pos]]--;
	return;
}
int main()	{
	int t;
	int n,q;
	scanf("%d",&t);
	while(t--)	{
		memset(freq,0,sizeof(freq));
		memset(tree,0,sizeof(tree));
		scanf("%d %d",&n,&q);
		block_size=sqrt(n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&actual[i]);
		}
		arr[0]=1;
		for(int i=1;i<n;i++)	{
			if(actual[i]==actual[i-1])	{
				arr[i]=arr[i-1];
			}
			else	{
				arr[i]=arr[i-1]+1;
			}
		}
		for(int i=0;i<q;i++)	{
			scanf("%d %d %d",&query[i].l,&query[i].r,&query[i].k);
			query[i].l--;
			query[i].r--;
			query[i].id=i;
		}
		sort(query,query+q,comp);
		int curl=query[0].l;
		int curr=curl;
		int L,R,K;
		for(curr=curl;curr<=query[0].r;curr++)	{
			add(curr,n);
		}
		curr--;
		ans[query[0].id]=tree[query[0].k];
		for(int i=1;i<q;i++)	{
			L=query[i].l;
			R=query[i].r;
			K=query[i].k;
			while(curl<L)	{
				remove(curl,n);
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
				remove(curr,n);
				curr--;
			}
			ans[query[i].id]=tree[K];
		}
		for(int i=0;i<q;i++)	{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}