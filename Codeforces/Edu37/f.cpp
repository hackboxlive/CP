#include <bits/stdc++.h>
using namespace std;
int pre[1000100];
int arr[300300];
void precompute()	{
	for(int i=1;i<=1000000;i++)	{
		for(int j=i;j<=1000000;j+=i)	{
			pre[j]++;
		}
	}
}
struct node	{
	long long summ;
	int maxx;
}tree[1200200];
void build(int id,int l,int r)	{
	if(l==r)	{
		tree[id].summ=arr[l];
		tree[id].maxx=arr[l];
		return;
	}
	build(2*id,l,(l+r)/2);
	build(2*id+1,(l+r)/2+1,r);
	tree[id].maxx=max(tree[2*id].maxx,tree[2*id+1].maxx);
	tree[id].summ=tree[2*id].summ+tree[2*id+1].summ;
}
void update(int id,int st,int en,int l, int r)	{
	if(st>r || en<l)	{
		return;
	}
	if(st==en)	{
		tree[id].maxx=pre[tree[id].maxx];
		tree[id].summ=tree[id].maxx;
		return;
	}
	if(st>=l && en<=r && tree[id].maxx<=2)	{
		return;
	}
	update(2*id,st,(st+en)/2,l,r);
	update(2*id+1,(st+en)/2+1,en,l,r);
	tree[id].maxx=max(tree[2*id].maxx,tree[2*id+1].maxx);
	tree[id].summ=tree[2*id].summ+tree[2*id+1].summ;	
}
long long query(int id,int st,int en,int l,int r)	{
	if(st>r || en<l)	{
		return 0;
	}
	if(st>=l && en<=r)	{
		return tree[id].summ;
	}
	return query(2*id,st,(st+en)/2,l,r)+query(2*id+1,(st+en)/2+1,en,l,r);
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	precompute();
	// for(int i=1;i<=100;i++)	{
	// 	cout<<pre[i]<<" ";
	// }
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	build(1,0,n-1);
	int ch,l,r;
	while(m--)	{
		cin>>ch>>l>>r;
		if(ch==1)	{
			update(1,0,n-1,l-1,r-1);
		}
		else	{
			cout<<query(1,0,n-1,l-1,r-1)<<endl;
		}
	}
	return 0;
}