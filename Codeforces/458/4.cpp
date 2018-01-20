#include <bits/stdc++.h>
using namespace std;
int arr[500500];
int tree[3003000];
void build(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=arr[l];
		return;
	}
	build(2*id,l,(l+r)/2);
	build(2*id+1,(l+r)/2+1,r);
	tree[id]=__gcd(tree[2*id],tree[2*id+1]);
}
void update(int id,int st,int en,int pos,int v)	{
	if(st>pos || en<pos)	{
		return;
	}
	if(st==pos && en==pos)	{
		tree[id]=v;
		return;
	}
	update(2*id,st,(st+en)/2,pos,v);
	update(2*id+1,(st+en)/2+1,en,pos,v);
	tree[id]=__gcd(tree[2*id],tree[2*id+1]);
}
int query(int id,int st,int en,int l,int r,int x)	{
	if(st>r || en<l)	{
		return -1;
	}
	if(st>=l && en<=r)	{
		if(tree[id]%x==0)	{
			return -1;
		}
		if(st==en)	{
			return st;
		}
		int h1=query(2*id,st,(st+en)/2,l,r,x);
		if(h1==-1)	{
			return query(2*id+1,(st+en)/2+1,en,l,r,x);
		}
		return h1;
	}
	int h2=query(2*id,st,(st+en)/2,l,r,x);
	if(h2!=-1)	{
		return h2;
	}
	return query(2*id+1,(st+en)/2+1,en,l,r,x);;
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	build(1,0,n-1);
	int q,ch,ans1,ans2,l,r,x;
	cin>>q;
	while(q--)	{
		cin>>ch;
		if(ch==1)	{
			cin>>l>>r>>x;
			//query
			ans1=query(1,0,n-1,l-1,r-1,x);
			if(ans1==-1)	{
				cout<<"YES\n";
			}
			else	{
				ans2=query(1,0,n-1,ans1+1,r-1,x);
				if(ans2==-1)	{
					cout<<"YES\n";
				}
				else	{
					cout<<"NO\n";
				}
			}
		}
		else	{
			cin>>l>>r;
			update(1,0,n-1,l-1,r);
		}
	}
	return 0;
}