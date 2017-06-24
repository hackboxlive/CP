#include <bits/stdc++.h>
using namespace std;
int arr[200200];
pair<int,bool> tree[2002000];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].first=arr[l];
		tree[id].second=false;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	if(tree[2*id].second==false)	{
		tree[id].first=tree[2*id].first|tree[2*id+1].first;
		tree[id].second=true;
	}
	else	{
		tree[id].first=tree[2*id].first^tree[2*id+1].first;
		tree[id].second=false;
	}
	return;
}
void update_tree(int id,int start,int end,int pos,int val)	{
	if(start>pos || end<pos)	{
		return;
	}
	if(start==pos && end==pos)	{
		tree[id].first=val;
		return;
	}
	update_tree(2*id,start,(start+end)/2,pos,val);
	update_tree(2*id+1,(start+end)/2+1,end,pos,val);
	if(tree[2*id].second==false)	{
		tree[id].first=tree[2*id].first|tree[2*id+1].first;
		tree[id].second=true;
	}
	else	{
		tree[id].first=tree[2*id].first^tree[2*id+1].first;
		tree[id].second=false;
	}
	return;
}
int main()	{
	int n,q;
	scanf("%d%d",&n,&q);
	int num=1<<n;
	for(int i=0;i<num;i++)	{
		scanf("%d",&arr[i]);
	}
	build_tree(1,0,num-1);
	int l,r;
	for(int i=0;i<q;i++)	{
		scanf("%d%d",&l,&r);
		update_tree(1,0,num-1,l-1,r);
		cout<<tree[1].first<<endl;
	}
	return 0;
}