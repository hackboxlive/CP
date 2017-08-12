#include <bits/stdc++.h>
using namespace std;
string s;
char ans[100100];
int tree[26][600600];
int lazy[26][600600];
void build(int id,int l,int r,int pos)	{
	if(l==r)	{
		if('a'+pos==s[l])	{
			tree[pos][id]=1;
		}
		else	{
			tree[pos][id]=0;
		}
		return;
	}
	build(2*id,l,(l+r)/2,pos);
	build(2*id+1,(l+r)/2+1,r,pos);
	tree[pos][id]=tree[pos][2*id]+tree[pos][2*id+1];
}
void update_lazy(int id,int l,int r,int pos)	{
	if(lazy[pos][id]==1)	{
		tree[pos][id]=r-l+1;
		if(l!=r)	{
			lazy[pos][2*id]=1;
			lazy[pos][2*id+1]=1;
		}
		lazy[pos][id]=0;
	}
	else if(lazy[pos][id]==-1)	{
		tree[pos][id]=0;
		if(l!=r)	{
			lazy[pos][2*id]=-1;
			lazy[pos][2*id+1]=-1;
		}
		lazy[pos][id]=0;
	}
}
int query(int id,int start,int end,int l,int r,int pos)	{
	update_lazy(id,start,end,pos);
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[pos][id];
	}
	return query(2*id,start,(start+end)/2,l,r,pos)+query(2*id+1,(start+end)/2+1,end,l,r,pos);
}
void update(int id,int start,int end,int l,int r,int val,int pos)	{
	update_lazy(id,start,end,pos);
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		if(val==0)	{
			tree[pos][id]=0;
			if(start!=end)	{
				lazy[pos][2*id]=-1;
				lazy[pos][2*id+1]=-1;
			}
		}
		else	{
			tree[pos][id]=end-start+1;
			if(start!=end)	{
				lazy[pos][2*id]=1;
				lazy[pos][2*id+1]=1;
			}
		}
		return;
	}
	update(2*id,start,(start+end)/2,l,r,val,pos);
	update(2*id+1,(start+end)/2+1,end,l,r,val,pos);
	tree[pos][id]=tree[pos][2*id]+tree[pos][2*id+1];
}
void build_string(int id,int l,int r,int pos)	{
	update_lazy(id,l,r,pos);
	if(l==r)	{
		if(tree[pos][id]==1)	{
			ans[l]=(char)(pos+'a');
		}
		return;
	}
	build_string(2*id,l,(l+r)/2,pos);
	build_string(2*id+1,(l+r)/2+1,r,pos);
}
int main()	{
	int n,q;
	cin>>n>>q;
	cin>>s;
	for(int i=0;i<26;i++)	{
		build(1,0,n-1,i);
	}
	int l,r,k,off,cnt;
	for(int i=0;i<n;i++)	{
		ans[i]='0';
	}
	while(q--)	{
		cin>>l>>r>>k;
		if(k==1)	{
			off=0;
			for(int i=0;i<26;i++)	{
				cnt=query(1,0,n-1,l-1,r-1,i);
				if(cnt==0)	{
					continue;
				}
				update(1,0,n-1,l-1,r-1,0,i);
				update(1,0,n-1,l-1+off,l-2+off+cnt,1,i);
				off=off+cnt;
			}
		}
		else	{
			off=0;
			for(int i=25;i>=0;i--)	{
				cnt=query(1,0,n-1,l-1,r-1,i);
				if(cnt==0)	{
					continue;
				}
				update(1,0,n-1,l-1,r-1,0,i);
				update(1,0,n-1,l-1+off,l-2+off+cnt,1,i);
				off=off+cnt;
			}
		}
	}
	for(int i=0;i<26;i++)	{
		build_string(1,0,n-1,i);
	}
	for(int i=0;i<n;i++)	{
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}