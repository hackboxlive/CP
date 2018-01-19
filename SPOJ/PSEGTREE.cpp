#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int version[100100];
int ctr=1;
struct node	{
	long long summ;
	int l;
	int r;
};
node tree[1200200];
void build(int id,int l,int r)	{
	if(l==r)	{
		tree[id].summ=arr[l];
		tree[id].l=-1;
		tree[id].r=-1;
		return;
	}
	ctr++;
	tree[id].l=ctr;
	ctr++;
	tree[id].r=ctr;
	build(tree[id].l,l,(l+r)/2);
	build(tree[id].r,(l+r)/2+1,r);
	tree[id].summ=tree[tree[id].l].summ+tree[tree[id].r].summ;
}
void update(int new_id,int old_id,int l,int r,int pos,int v)	{
	//cout<<new_id<<" "<<old_id<<endl;
	if(l==r)	{
		tree[new_id].summ=v+tree[old_id].summ;
		tree[new_id].l=-1;
		tree[new_id].r=-1;
		return;
	}
	if(pos>(r+l)/2)	{
		tree[new_id].l=tree[old_id].l;
		ctr++;
		tree[new_id].r=ctr;
		update(tree[new_id].r,tree[old_id].r,(l+r)/2+1,r,pos,v);		
	}
	else	{
		tree[new_id].r=tree[old_id].r;
		ctr++;
		tree[new_id].l=ctr;
		update(tree[new_id].l,tree[old_id].l,l,(l+r)/2,pos,v);
	}
	tree[new_id].summ=tree[tree[new_id].l].summ+tree[tree[new_id].r].summ;
}
long long query(int id,int st,int en,int l,int r)	{
	if(st>r || en<l)	{
		return 0;
	}
	if(st>=l && en<=r)	{
		return tree[id].summ;
	}
	return query(tree[id].l,st,(st+en)/2,l,r)+query(tree[id].r,(st+en)/2+1,en,l,r);
}
int main()	{
	int n,q;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	version[0]=1;
	int a,b,c,d;
	build(version[0],0,n-1);
	cin>>q;
	int v_num=0;
	while(q--)	{
		cin>>a>>b>>c>>d;
		if(a==1)	{
			//do thing
			v_num++;
			ctr++;
			version[v_num]=ctr;
			update(version[v_num],version[b],0,n-1,c-1,d);
//			cout<<query(version[v_num],0,n-1,1,2)<<endl;
		}
		else	{
			//do some other thing
			cout<<query(version[b],0,n-1,c-1,d-1)<<endl;
		}
	}
	return 0;
}