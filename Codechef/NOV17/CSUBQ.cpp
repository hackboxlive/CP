//wrong answer
#include <bits/stdc++.h>
using namespace std;
struct node	{
	int ans;
	int first;
	int last;
	int sz;
}ltree[3003000],rtree[3003000];
node merge(node a,node b)	{
	node temp;
//	cout<<a.ans<<" "<<b.ans<<endl;
	temp.ans=a.ans+b.ans;
	if(a.first==-1)	{
		if(b.first==-1)	{
			temp.first=-1;
			temp.last=-1;
			temp.ans=0;
		}
		else	{
			temp.first=a.sz+b.first;
			temp.last=a.sz+b.last;
			temp.ans+=(a.sz*(b.sz-b.first+1));
		}
	}
	else	{
		if(b.first==-1)	{
			temp.first=a.first;
			temp.last=a.last;
			temp.ans+=(a.last*b.sz);
		}
		else	{
			temp.first=a.first;
			temp.last=a.sz+b.last;
			temp.ans+=(a.last*b.sz);
			temp.ans+=((a.sz-a.last)*(b.sz-b.first+1));
		}
	}
	return temp;
}
void lbuild(int id,int l,int r)	{
	if(l==r)	{
		ltree[id].ans=0;
		ltree[id].first=-1;
		ltree[id].last=-1;
		ltree[id].sz=1;
		return;
	}
	lbuild(2*id,l,(l+r)/2);
	lbuild(2*id+1,(l+r)/2+1,r);
	ltree[id].ans=0;
	ltree[id].first=-1;
	ltree[id].last=-1;
	ltree[id].sz=ltree[2*id].sz+ltree[2*id+1].sz;	
}
node lquery(int id,int st,int en,int l,int r)	{
	if(st>=l && en<=r)	{
		return ltree[id];
	}
	int mid=(st+en)/2;
	if(mid<l)	{
		return lquery(2*id+1,mid+1,en,l,r);
	}
	else if(mid>=r)	{
		return lquery(2*id,st,mid,l,r);
	}
	else	{
		return merge(lquery(2*id,st,mid,l,r),lquery(2*id+1,mid+1,en,l,r));
	}
}
void lupdate(int id,int st,int en,int pos,int val)	{
	if(st>pos || en<pos)	{
		return;
	}
	if(st==pos && en==pos)	{
		if(val==1)	{
			ltree[id].ans=1;
			ltree[id].first=1;
			ltree[id].last=1;
		}
		else	{
			ltree[id].ans=0;
			ltree[id].first=-1;
			ltree[id].last=-1;
		}
		return;
	}
	lupdate(2*id,st,(st+en)/2,pos,val);
	lupdate(2*id+1,(st+en)/2+1,en,pos,val);
	ltree[id]=merge(ltree[2*id],ltree[2*id+1]);
}
void rbuild(int id,int l,int r)	{
	if(l==r)	{
		rtree[id].ans=0;
		rtree[id].first=-1;
		rtree[id].last=-1;
		rtree[id].sz=1;
		return;
	}
	rbuild(2*id,l,(l+r)/2);
	rbuild(2*id+1,(l+r)/2+1,r);
	rtree[id].ans=0;
	rtree[id].first=-1;
	rtree[id].last=-1;
	rtree[id].sz=rtree[2*id].sz+rtree[2*id+1].sz;	
}
node rquery(int id,int st,int en,int l,int r)	{
	if(st>=l && en<=r)	{
		return rtree[id];
	}
	int mid=(st+en)/2;
	if(mid<l)	{
		return rquery(2*id+1,mid+1,en,l,r);
	}
	else if(mid>=r)	{
		return rquery(2*id,st,mid,l,r);
	}
	else	{
		return merge(rquery(2*id,st,mid,l,r),rquery(2*id+1,mid+1,en,l,r));
	}
}
void rupdate(int id,int st,int en,int pos,int val)	{
	if(st>pos || en<pos)	{
		return;
	}
	if(st==pos && en==pos)	{
		if(val==1)	{
			rtree[id].ans=1;
			rtree[id].first=1;
			rtree[id].last=1;
		}
		else	{
			rtree[id].ans=0;
			rtree[id].first=-1;
			rtree[id].last=-1;
		}
		return;
	}
	rupdate(2*id,st,(st+en)/2,pos,val);
	rupdate(2*id+1,(st+en)/2+1,en,pos,val);
	rtree[id]=merge(rtree[2*id],rtree[2*id+1]);
}
int main()	{
	int n,q,L,R;
	int t,x,y;
	node temp1,temp2;
	cin>>n>>q>>L>>R;
	lbuild(1,0,n-1);
	rbuild(1,0,n-1);
	while(q--)	{
		cin>>t>>x>>y;
		if(t==1)	{
			if(y>R)	{
				rupdate(1,0,n-1,x-1,1);
			}
			else	{
				rupdate(1,0,n-1,x-1,0);
			}
			if(y>=L)	{
				lupdate(1,0,n-1,x-1,1);
			}
			else	{
				lupdate(1,0,n-1,x-1,0);
			}
		}
		else	{
			temp1=lquery(1,0,n-1,x-1,y-1);
			temp2=rquery(1,0,n-1,x-1,y-1);
			cout<<temp1.ans-temp2.ans<<endl;
		}
	}
	return 0;
}