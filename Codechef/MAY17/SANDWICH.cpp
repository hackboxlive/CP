#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > f1,f2;
vector<pair<long long,long long> > ff;
long long modfact[1000100];
long long modulo(long long a,long long b)	{
	a=a%b;
	a=a+b;
	a=a%b;
	return a;
}
long long gcd(long long a,long long b)	{
	if(a==0)	{
		return b;
	}
	return gcd(b%a,a);
}
long long power(long long a,long long i)	{
	if(i==0)	{
		return 1;
	}
	if(i==1)	{
		return a;
	}
	long long temp=power(a,i>>1);
	if(i%2==0)	{
		return temp*temp;
	}
	else	{
		return temp*temp*a;
	}
}
vector<long long> generatefactors(long long m)	{
	vector<long long> retval(m,1);
	retval.push_back(1);
	for(int i=1;i<m;i++)	{
		if(gcd(i,m)==1)	{
			retval[i]=retval[i-1]*i%m;
		}
		else	{
			retval[i]=retval[i-1];
		}
	}
	return retval;
}
void init(long long m)	{
	ff.clear();
	f1.clear();
	f2.clear();
	long long prev=m,cur;
	while(m!=1)	{
		cur=modfact[m];
		if(cur!=prev)	{
			ff.push_back(make_pair(cur,1));
		}
		else	{
			ff[ff.size()-1].second++;
		}
		prev=cur;
		m=m/cur;
	}
	for(int i=0;i<ff.size();i++)	{
		long long p=ff[i].first;
		long long a=ff[i].second;
		f1.push_back(generatefactors(power(p,a)));
		f2.push_back(generatefactors(p));
	}
}
void sieve()	{
	for(long long i=2;i<1000100;i++)	{
		if(!(modfact[i]))	{
			for(long long j=i;j<1000100;j+=i)	{
				if(!(modfact[j]))	{
					modfact[j]=i;
				}
			}
		}
	}
}
pair<long long> factorial_mod(long long n,long long p,const vector<long long>& f3)	{
	if(n==0)	{
		return make_pair(1,0);
	}
	pair<long long> temp=factorial_mod(n/p,p,f3);
	long long a=temp.first;
	long long e=temp.second;
	e+=n/p;
	if(n/p%2!=0)	{
		return make_pair(a*(p-f3[n%p])%p,e);
	}
	else	{
		return make_pair(a*f3[n%p]%p,e);
	}
}
long long power_modulo(long long a,long long b,long long m)	{
	if(b==0)	{
		return 1;
	}
	else if(b==1)	{
		return a%m;
	}
	else	{
		long long temp=power_modulo(a,b>>1,m);
		if(b%2==0)	{
			return temp*temp%m;
		}
		else	{
			return temp*temp*a%m;
		}
	}
}
long long factorial(long long n,long long m,long long p,const vector<int>& f3)	{
	if(n==0 || n==1)	{
		return 1;
	}
	else if(n<m)	{
		return f3[n]*factorial(n/p,m,p,f3)%m;
	}
	else	{
		long long a=f3[m-1];
		long long b=f3[n%m];
		long long c=factorial(n/p,m,p,f3);
		return power_modulo(a,n/m,m)*b*c%m;
	}
}
long long inverse_modulo(long long a,long long n)	{
	long long x,y;
	long long d=extendedeuclid(a,n,x,y);
	if(d>1)	{
		return -1;
	}
	return modulo(x,n);
}
long long choosemodulo(long long n,long long k,long long m,pair<long long> pa,const vector<long long> f3,const vector<long long>& temp)	{
	long long p,a;
	p=pa.first;
	a=pa.second;
	long long b=a;
	while(b>0)	{
		pair<long long,long long> t1=factorial_mod(n,p,temp);
		pair<long long,long long> t2=factorial_mod(r,p,temp);
		pair<long long,long long> t3=factorial_mod(n-r,p,temp);
		long long e1,e2,e3;
		e1=t1.second;
		e2=t2.second;
		e3=t3.second;
		if(e1>=e2+e3+a)	{
			return 0;
		}
		if(e1>=e2+e3+b)	{
			break;
		}
		b--;
	}
	long long m1=factorial(n,m,p,ff3);
	long long m2=factorial(r,m,p,ff3);
	long long m3=factorial(n-r,m,p,ff3);
	return power(p,b)*m1*inverse_modulo(m2,m)*inverse_modulo(m3,m)%m;
}
long long extendedeuclid(long long a,long long b,long long &x,long long &y)	{
	long long xx=y=0;
	long long yy=y=1;
	while(b)	{
		long long q=a/b;
		long long t=b;
		b=a%b;
		a=t;
		t=xx;
		xx=x-q*xx;
		x=t;
		t=yy;
		yy=y-q*yy;
		y=t;
	}
	return a;
}
pair<long long,long long> crt2(long long x,long long a,long long y,long long b)	{
	long long s,tl;
	long long d=extendedeuclid(x,y,s,t);
	if(a%d!=b%d)	{
		return make_pair(0,-1);
	}
	return make_pair(modulo(s*b*x+t*a*y,x*y)/d,x*y/d);
}
pair<long long,long long> crt1(const vector<long long> &x,const vector<long long> &a)	{
	pair<long long> retval=make_pair(a[0],x[0]);
	for(int i=1;i<x.size();i++)	{
		retval=crt2(retval.second,retval.first,x[i],a[i]);
		if(retval.second==-1)	{
			break;
		}
	}
	return retval;
}
long long solve(long long n,long long k)	{
	vector<vector<long long> > excess(ff.size(),0);
	vector<vector<long long> > assess(ff.size(),0);
	for(int i=0;i<ff.size();i++)	{
		excess[i]=power(ff[i].first,ff[i].second);
		assess[i]=choosemodulo(n,k,excess[i],ff[i],f1[i],f2[i]);
	}
	return crt1(excess,assess).first;
}
int main()	{
	int t;
	long long n,k,m;
	sieve();
	scanf("%d",&t);
	while(t--)	{
		scanf("%lld %lld %lld",&n,&k,&m);
		init(m);
		if(n%k==0)	{
			printf("%lld 1\n",n/k);
			continue;
		}
		long long newn=(n/k)-1;
		long long newk=k-(n%k);
		printf("%lld %lld\n",newn+2,solve(newn+newk+1,newn+1));
	}
	return 0;
}