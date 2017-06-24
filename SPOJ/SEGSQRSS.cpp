#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long int scan()
{
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true)
	{
		r=getchar_unlocked();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
		{
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start)
		{
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
ll a[100010],lazy[400010];
struct node 
{
	ll sum,sqrsum;
}t[400010];
void build(ll low,ll high,ll nod)
{
	if(low==high)
	{
		t[nod].sum=a[low];
		t[nod].sqrsum=a[low]*a[low];
		lazy[nod]=0;
		return ;
	}
	ll mid=(low+high)/2;
	build(low,mid,nod*2);
	build(mid+1,high,nod*2+1);
	lazy[nod]=0;
	t[nod].sum=t[nod*2].sum+t[nod*2+1].sum;
	t[nod].sqrsum=t[nod*2].sqrsum+t[nod*2+1].sqrsum;
}
void update(ll low,ll high,ll nod,ll start,ll end,ll change)
{
	if(lazy[nod])
	{
		if(lazy[nod]<0)
		{
			t[nod].sum=(high-low+1)*(-lazy[nod]);
			t[nod].sqrsum=(high-low+1)*(lazy[nod]*lazy[nod]);
			if(low!=high)
			{
				lazy[nod*2]=lazy[nod*2+1]=lazy[nod];	
		    }
		    lazy[nod]=0;
		}
		else
		{
			t[nod].sqrsum+=(t[nod].sum+(high-low+1)*lazy[nod])*(t[nod].sum+(high-low+1)*lazy[nod]);
			t[nod].sqrsum-= (t[nod].sum)*(t[nod].sum);
			t[nod].sqrsum-= (2*(high-low)*(t[nod].sum)*lazy[nod] + (high-low+1)*(high-low)*lazy[nod]*lazy[nod]);
			t[nod].sum+=(high-start+1)*(lazy[nod]);
			if(low!=high)
			{
				if(lazy[nod*2]>=0)
				lazy[nod*2]+=lazy[nod];
				else
			 	lazy[nod*2]-=lazy[nod];
			 	if(lazy[nod*2+1]>=0)
			 	lazy[nod*2+1]+=lazy[nod];
			 	else
			 	lazy[nod*2+1]-=lazy[nod];
			}
		}
	}
    if(low>end || high<start)
	return ;
	if(low>=start && end>=high)
	{
		if(change<0)
	    {
	    	t[nod].sum=(high-low+1)*(-change);
			t[nod].sqrsum=(high-low+1)*(change*change);
			if(low!=high)
			{
				lazy[nod*2]=lazy[nod*2+1]=change;	
			}
		}
		else
		{
			t[nod].sqrsum+=(t[nod].sum+(high-low+1)*change)*(t[nod].sum+(high-low+1)*change);
			t[nod].sqrsum-= (t[nod].sum)*(t[nod].sum);
			t[nod].sqrsum-= (2*(high-low)*(t[nod].sum)*change + (high-low+1)*(high-low)*change*change);
			t[nod].sum+=(high-start+1)*(change);
			if(low!=high)
			{
				if(lazy[nod*2]>=0)
				lazy[nod*2]+=change;
				else
				lazy[nod*2]-=change;
				if(lazy[nod*2+1]>=0)
				lazy[nod*2+1]+=change;
				else
				lazy[nod*2+1]-=change;
			}
		}
		return ;
	}
	ll mid=(low+high)/2;
	update(low,mid,nod*2,start,end,change);
	update(mid+1,high,nod*2+1,start,end,change);
	t[nod].sum=t[nod*2].sum+t[nod*2+1].sum;
	t[nod].sqrsum=t[nod*2].sqrsum+t[nod*2+1].sqrsum;
}
ll query(ll low,ll high,ll nod,ll start,ll end)
{
	if(lazy[nod])
	{
	    if(lazy[nod]<0)
	    {
			t[nod].sum=(high-low+1)*(-lazy[nod]);
			t[nod].sqrsum=(high-low+1)*(lazy[nod]*lazy[nod]);
			if(low!=high)
			{
				lazy[nod*2]=lazy[nod*2+1]=lazy[nod];	
			}
			lazy[nod]=0;
		}
		else
		{
			t[nod].sqrsum+=(t[nod].sum+(high-low+1)*lazy[nod])*(t[nod].sum+(high-low+1)*lazy[nod]);
			t[nod].sqrsum-= (t[nod].sum)*(t[nod].sum);
			t[nod].sqrsum-= (2*(high-low)*(t[nod].sum)*lazy[nod] + (high-low+1)*(high-low)*lazy[nod]*lazy[nod]);
			t[nod].sum+=(high-start+1)*(lazy[nod]);
			if(low!=high)
			{
				if(lazy[nod*2]>=0)
				lazy[nod*2]+=lazy[nod];
				else
				lazy[nod*2]-=lazy[nod];
				if(lazy[nod*2+1]>=0)
				lazy[nod*2+1]+=lazy[nod];
				else
				lazy[nod*2+1]-=lazy[nod];
			}
		}
	}
	if(low>end || high<start)
	return 0;
	if(low>=start && high<=end)
	return t[nod].sqrsum;
	ll mid=(low+high)/2;
	return query(low,mid,nod*2,start,end)+query(mid+1,high,nod*2+1,start,end);
}
int main()
{
	int ti,u=0;
	ti=scan();
	while(ti--)
	{
		u++;
		printf("Case %d:\n",u);
		long long n,m,i,j,k,type;
		n=scan();
		m=scan();
		for(i=1;i<=n;i++)
		{
			a[i]=scan();
		}
		build(1,n,1);
		while(m--)
		{
			type=scan();
			if(type==0)
			{
				i=scan();
				j=scan();
				k=scan();
				update(1,n,1,i,j,-k);
			}
			else if(type==1)
			{
				i=scan();
				j=scan();
				k=scan();
				update(1,n,1,i,j,k);
			}
			else
			{
				i=scan();
				j=scan();
				printf("%lld\n",query(1,n,1,i,j));
			}
		}	
	}
	return 0;
}