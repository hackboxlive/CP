#include <stdio.h>
struct node	{
	long long a0;
	long long a1;
	long long a2;
	long long a3;
}eq[100100];
long long ans[100100];
long long put[100100];
long long set_size;
void precompute(long long n)	{
	long long i,j,ind;
	long long minn,v;
	for(i=1;i<=set_size;++i)	{
		ind=-1,minn=1LL<<62;
		for(j=0;j<n;++j)	{
			v=eq[j].a0+eq[j].a1*i+eq[j].a2*i*i+eq[j].a3*i*i*i;
			if(v<minn)	{
				minn=v;
				ind=j;
			}
		}
		put[i]=ind;
	}
}
void recurse(long long n,long long l,long long r)	{
	if(l>r)	{
		return;
	}
	long long m=l+(r-l)/2;
	long long i,id1=-1,id2=-1;
	long long v1,v2,m1=1LL<<62,m2=1LL<<62;
	for(i=0;i<n;++i)	{
		v1=eq[i].a0+eq[i].a1*l+eq[i].a2*l*l+eq[i].a3*l*l*l;
		v2=eq[i].a0+eq[i].a1*r+eq[i].a2*r*r+eq[i].a3*r*r*r;
		if(v1<m1)	{
			m1=v1;
			id1=i;
		}
		if(v2<m2)	{
			m2=v2;
			id2=i;
		}
	}
	if(id1!=id2)	{
		recurse(n,l,m);
		recurse(n,m+1,r);
	}
	else	{
		for(i=l;i<=r;++i)	{
			put[i]=id1;
		}
	}
}
long long main()	{
	//no logic, only luck!! :p
	set_size=1000;
	long long t,n,q,i,v;
	scanf("%lld",&t);
	while(t--)	{
		scanf("%lld",&n);
		ans[0]=1LL<<62;
		for(i=0;i<n;++i)	{
			scanf("%lld %lld %lld %lld",&eq[i].a0,&eq[i].a1,&eq[i].a2,&eq[i].a3);
			ans[0]=eq[i].a0<ans[0]?eq[i].a0:ans[0];
		}
		precompute(n);
		scanf("%lld",&q);
		recurse(n,set_size+1,100000);
		for(i=1;i<=100000;++i)	{
			ans[i]=eq[put[i]].a0+eq[put[i]].a1*i+eq[put[i]].a2*i*i+eq[put[i]].a3*i*i*i;
		}
		while(q--)	{
			scanf("%lld",&v);
			printf("%lld\n",ans[v]);
		}
	}
	return 0;
}