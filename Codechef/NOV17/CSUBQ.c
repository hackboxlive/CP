#include <stdio.h>
struct zo	{
	int first;
	int last;
};
struct node	{
	long long ans;
	struct zo zero;
	struct zo one;
} t1[3000300],t2[3000300],tmp1,tmp2,nn;
struct node merge(struct node a,struct node b)	{
	struct node temp;
	temp.ans=a.ans+b.ans;
	temp.ans+=(long long)a.zero.last*b.zero.first;
	if(a.one.first>=0)	{
		if(b.one.first>=0)	{
			temp.one.first=a.one.first;
			temp.one.last=b.one.last;
			temp.zero.first=a.zero.first;
			temp.zero.last=b.zero.last;
		}
		else	{
			temp.one.first=a.one.first;
			temp.one.last=a.one.last;
			temp.zero.first=a.zero.first;
			temp.zero.last=a.zero.last+b.zero.first;			
		}
	}
	else	{
		if(b.one.first>=0)	{
			temp.one.first=b.one.first;
			temp.one.last=b.one.last;
			temp.zero.first=a.zero.last+b.zero.first;
			temp.zero.last=b.zero.last;
		}
		else	{
			temp.one.first=-1;
			temp.one.last=-1;
			temp.zero.last=temp.zero.first=a.zero.last+b.zero.first;
		}
	}
	return temp;
}
void build(struct node t[],int id,int l,int r)	{
	if(l==r)	{
		t[id].ans=1;
		t[id].zero.first=t[id].zero.last=1;
		t[id].one.first=t[id].one.last=-1;
		return;
	}
	build(t,2*id,l,(l+r)/2);
	build(t,2*id+1,(l+r)/2+1,r);
	t[id]=merge(t[2*id],t[2*id+1]);
}
void update(struct node t[],int id,int st,int en,int pos,int val)	{
	if(st>pos || en<pos)	{
		return;
	}
	if(st==pos && en==pos)	{
		if(val==0)	{
			t[id].ans=1;
			t[id].zero.first=t[id].zero.last=1;
			t[id].one.first=t[id].one.last=-1;
		}
		else	{
			t[id].ans=0;
			t[id].zero.first=t[id].zero.last=0;
			t[id].one.first=t[id].one.last=pos;
		}
		return;
	}
	update(t,2*id,st,(st+en)/2,pos,val);
	update(t,2*id+1,(st+en)/2+1,en,pos,val);
	t[id]=merge(t[2*id],t[2*id+1]);
}
struct node query(struct node t[],int id,int st,int en,int l,int r)	{
	if(st>r || en<l)	{
		return nn;
	}
	if(st>=l && en<=r)	{
		return t[id];
	}
	return merge(query(t,2*id,st,(st+en)/2,l,r),query(t,2*id+1,(st+en)/2+1,en,l,r));
}
int main()	{
	int n,q;
	nn.ans=0;
	nn.zero.first=nn.zero.last=0;
	nn.one.first=nn.one.last=-1;
	scanf("%d %d",&n,&q);
	int L,R;
	long long tot;
	scanf("%d %d",&L,&R);
	build(t1,1,0,n-1);
	build(t2,1,0,n-1);
	int type,l,r;
	while(q--)	{
		scanf("%d %d %d",&type,&l,&r);
		if(type==1)	{
			if(r>=L)	{
				update(t1,1,0,n-1,l-1,1);
			}
			else	{
				update(t1,1,0,n-1,l-1,0);
			}
			if(r>R)	{
				update(t2,1,0,n-1,l-1,1);
			}
			else	{
				update(t2,1,0,n-1,l-1,0);
			}
		}
		else	{
			printf("%lld\n",query(t2,1,0,n-1,l-1,r-1).ans-query(t1,1,0,n-1,l-1,r-1).ans);
		}
	}
	return 0;
}