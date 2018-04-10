#include <bits/stdc++.h>
using namespace std;

const int LIM=1e9+7;

int a[100100];
int b[100100];
struct node	{
	int minn;
	int maxx;
	int lazy;
}tree[600600],zero;
void build(int id,int l,int r)	{
	if(l==r)	{
		tree[id].minn=a[l];
		tree[id].maxx=b[l];
		tree[id].lazy=0;
		return;
	}
	build(2*id,l,(l+r)/2);
	build(2*id+1,(l+r)/2+1,r);
	tree[id].minn=min(tree[2*id].minn,tree[2*id+1].minn);
	tree[id].maxx=max(tree[2*id].maxx,tree[2*id+1].maxx);
	tree[id].lazy=0;
}
void update_lazy(int id,int l,int r)	{
	if(tree[id].lazy!=0)	{
		if(l!=r)	{
			tree[2*id].minn=tree[id].lazy;
			tree[2*id+1].minn=tree[id].lazy;
		}
		tree[id].lazy=0;
	}
}
node query(int id,int st,int en,int l,int r)	{
	update_lazy(id,st,en);
	if(st>r || en<l)	{
		return zero;
	}
	if(st>=l && en<=r)	{
		return tree[id];
	}
	node temp1=query(2*id,st,(st+en)/2,l,r);
	node temp2=query(2*id+1,(st+en)/2+1,en,l,r);
	temp1.minn=min(temp1.minn,temp2.minn);
	temp1.maxx=max(temp1.maxx,temp2.maxx);
	return temp1;
}
void update(int id,int st,int en,int l,int r,int val)	{
	update_lazy(id,st,en);
	if(st>r || en<l)	{
		return;
	}
	if(st>=l && en<=r)	{
		tree[id].minn=val;
		if(l!=r)	{
			tree[2*id].lazy=val;
			tree[2*id+1].lazy=val;
		}
		return;
	}
	update(2*id,st,(st+en)/2,l,r,val);
	update(2*id+1,(st+en)/2+1,en,l,r,val);
	tree[id].minn=min(tree[2*id].minn,tree[2*id+1].minn);
}
int main()	{
	zero.minn=INT_MAX;
	zero.maxx=INT_MIN;
	zero.lazy=0;
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		map<int, vector<int> > mp;
		for(int i=0;i<n;i++)	{
			cin>>a[i];
		}
		bool flag=true;
		for(int i=0;i<n;i++)	{
			cin>>b[i];
			if(b[i]>a[i])	{
				flag=false;
			}
			else if(b[i]<a[i])	{
				mp[LIM-b[i]].push_back(i);
			}
		}
		if(flag==false)	{
			cout<<"-1\n";
			continue;
		}
		build(1,0,n-1);
		int v;
		node temp;
		int ans=0;
		for(auto it=mp.begin();it!=mp.end();it++)	{
			v=it->first;
			v=LIM-v;
			int ttt=1;
			int prev=(it->second).at(0),cur;
			for(int i=1;i<(it->second).size();i++)	{
				cur=(it->second).at(i);
				temp=query(1,0,n-1,prev,cur);
				if(temp.minn<v || temp.maxx>v)	{
					ttt++;
					prev=cur;
				}
				else	{
					update(1,0,n-1,prev,cur,v);
				}
			}
			ans+=ttt;
		}
		cout<<ans<<endl;
	}
	return 0;
}