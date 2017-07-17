#include <bits/stdc++.h>
using namespace std;
struct n1	{
	int l;
	int r;
	int c;
}arr[200200];
struct n2	{
	int lt;
	int dur;
	int c;
}ed[200200],st[200200];
bool cp(const n2 &p1,const n2 &p2)	{
	if(p1.dur==p2.dur)	{
		return p1.lt<p2.lt;
	}
	return p1.dur<p2.dur;
}
struct n3	{
	int s;
	int e;
}ss[200200],ee[200200];
int tree1[10001000],tree2[10001000];
void build(int id,int l,int r)	{
	if(l==r)	{
		tree1[id]=st[l].c;
		tree2[id]=ed[l].c;
		return;
	}
	build(2*id,l,(l+r)/2);
	build(2*id+1,(l+r)/2+1,r);
	tree1[id]=min(tree1[2*id],tree1[2*id+1]);
	tree2[id]=min(tree2[2*id],tree2[2*id+1]);	
}
int query1(int id,int st,int en,int l,int r)	{
	if(st>r || en<l)	{
		return 1e9;
	}
	if(st>=l && en<=r)	{
		return tree1[id];
	}
	return min(query1(2*id,st,(st+en)/2,l,r),query1(2*id+1,(st+en)/2+1,en,l,r));
}
int query2(int id,int st,int en,int l,int r)	{
	if(st>r || en<l)	{
		return 1e9;
	}
	if(st>=l && en<=r)	{
		return tree2[id];
	}
	return min(query2(2*id,st,(st+en)/2,l,r),query2(2*id+1,(st+en)/2+1,en,l,r));
}
int getvall(int lo,int hi,int val)	{
	int mid;
	if(st[hi].lt<val)	{
		return hi+1;
	}
	while(lo<hi)	{
		mid=(lo+hi)/2;
		if(st[mid].lt<val)	{
			lo=mid+1;
		}
		else	{
			hi=mid;
		}
	}
	return lo;
}
int getvalr(int lo,int hi,int val)	{
	int mid;
	if(ed[lo].lt>val)	{
		return lo-1;
	}
	while(lo<hi)	{
		mid=(lo+hi+1)/2;
		if(ed[mid].lt>val)	{
			hi=mid-1;
		}
		else	{
			lo=mid;
		}
	}
	return lo;
}
int main()	{
	int n,x;
	cin>>n>>x;
	for(int i=0;i<n;i++)	{
		cin>>arr[i].l>>arr[i].r>>arr[i].c;
		ed[i].lt=arr[i].r;
		ed[i].dur=arr[i].r-arr[i].l+1;
		ed[i].c=arr[i].c;
		st[i].lt=arr[i].l;
		st[i].dur=arr[i].r-arr[i].l+1;
		st[i].c=arr[i].c;
	}
	sort(st,st+n,cp);
	sort(ed,ed+n,cp);
	for(int i=1;i<=200000;i++)	{
		ss[i].s=-1;
		ee[i].s=-1;
	}
	for(int i=0;i<n;i++)	{
		if(ss[st[i].dur].s==-1)	{
			ss[st[i].dur].s=i;
		}
		ss[st[i].dur].e=i;
		if(ee[ed[i].dur].s==-1)	{
			ee[ed[i].dur].s=i;
		}
		ee[ed[i].dur].e=i;
	}
	build(1,0,n-1);
	int minans=INT_MAX;
	int rgtlt,lftlt;
	int sv;
	int idx;
	int ans;
	int flag=0;
	for(int i=0;i<n;i++)	{
		ans=1e9;
		rgtlt=arr[i].l-1;
		lftlt=arr[i].r+1;
		sv=x-(arr[i].r-arr[i].l+1);
		if(sv<=0)	{
			continue;
		}
		if(ss[sv].s!=-1)	{
			idx=getvall(ss[sv].s,ss[sv].e,lftlt);
			ans=min(ans,query1(1,0,n-1,idx,ss[sv].e));
			flag=1;
		}
		if(ee[sv].s!=-1)	{
			idx=getvalr(ee[sv].s,ee[sv].e,rgtlt);
			ans=min(ans,query2(1,0,n-1,ee[sv].s,idx));
			flag=1;
		}
		minans=min(minans,ans+arr[i].c);
	}
	if(flag==1)	{
		cout<<minans;
	}
	else	{
		cout<<"-1";
	}
	return 0;
}