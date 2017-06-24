#include <bits/stdc++.h>
using namespace std;
int arr[200200];
//int newarr[200200];
int tree[1000100];
vector<pair<int,int> > newarr;
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	return p1.first<p2.first;
}
void update_lazy(int id,int l,int r)	{
	if(tree[id]>0 && l!=r)	{
		tree[2*id]+=tree[id];
		tree[2*id+1]+=tree[id];
		tree[id]=0;
	}
	return;
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=0;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=0;
	return;
}
void update_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		tree[id]++;
		return;
	}
	update_lazy(2*id,start,(start+end)/2);
	update_lazy(2*id+1,(start+end)/2+1,end);
	update_tree(2*id,start,(start+end)/2,l,r);
	update_tree(2*id+1,(start+end)/2+1,end,l,r);
	return;
}
void complete_update(int id,int l,int r)	{
	if(l==r)	{
//		newarr[l].first=tree[id];
		newarr.push_back(make_pair(tree[id],l+1));
		return;
	}
	update_lazy(2*id,l,(l+r)/2);
	update_lazy(2*id+1,(l+r)/2+1,r);
	complete_update(2*id,l,(l+r)/2);
	complete_update(2*id+1,(l+r)/2+1,r);
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		build_tree(1,0,n-1);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
			if(arr[i]!=0)	{
				update_tree(1,0,n-1,i-arr[i],i-1);
			}
//			for(int i=1;i<=10;i++)	{
//				cout<<tree[i]<<" ";
//			}
//			cout<<endl;
		}
		complete_update(1,0,n-1);
		for(int i=0;i<n;i++)	{
			newarr[i].first=newarr[i].first+i+1-arr[i];
//			printf("%d ",newarr[i].first);
//			newarr[i].second=i+1;
		}
//		printf("\n");
		sort(newarr.begin(),newarr.end(),comp);
		for(int i=0;i<n;i++)	{
			printf("%d ",newarr[i].second);
		}
		printf("\n");
		newarr.clear();
	}
	return 0;
}