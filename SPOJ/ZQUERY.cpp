#include <bits/stdc++.h>
using namespace std;
struct node	{
	int l,r,i,ans;
}query[50500];
int arr[50500];
int block_size;
int neg,pos;
bool comp(const node &p1,const node &p2)	{
	if(p1.l/block_size==p2.l/block_size)	{
		return p1.r<p2.r;
	}
	return p1.l<p2.l;
}
bool comp2(const node &p1,const node &p2)	{
	return p1.i<p2.i;
}
void add(int position)	{
	if(arr[position]==1)	{
		pos++;
	}
	else	{
		neg++;
	}
	return;
}
void remove(int position)	{
	if(arr[position]==1)	{
		pos--;
	}
	else	{
		neg--;
	}
	return;
}
int main()	{
	int n,m;
	scanf("%d %d",&n,&m);
	block_size=(int)sqrt(n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<m;i++)	{
		scanf("%d %d",&query[i].l,&query[i].r);
		query[i].l--;
		query[i].r--;
		query[i].i=i;
	}
	sort(query,query+m,comp);
	int L,R;
	int ans;
	int curl=0,curr=-1;
	neg=0;
	pos=0;
	for(int i=0;i<m;i++)	{
		L=query[i].l;
		R=query[i].r;
		while(curl<L)	{
			remove(curl);
			curl++;
		}
		while(curl>L)	{
			add(curl-1);
			curl--;
		}
		while(curr<R)	{
			add(curr+1);
			curr++;
		}
		while(curr>R)	{
			remove(curr);
			curr--;
		}
		ans=min(neg,pos)*2;
		query[i].ans=ans;
	}
	sort(query,query+m,comp2);
	for(int i=0;i<m;i++)	{
		printf("%d\n",query[i].ans);
	}
	return 0;
}