#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> VI;
typedef pair<long long,long long> PII;
vector<VI> facts1;
vector<VI> facts2;
vector<PII> factors;
long long modfact[1000100];
long long mod(long long a, long long b) {
    return ((a%b)+b)%b;
}
long long gcd(long long a, long long b) {
    long long tmp;
    while(b){
    	a%=b;
    	tmp=a;
    	a=b;
    	b=tmp;
    }
    return a;
}
long long extended_euclid(long long a, long long b, long long &x, long long &y) {  
    long long xx = y = 0;
    long long yy = x = 1;
    while (b) {
	long long q = a/b;
	long long t = b; b = a%b; a = t;
	t = xx; xx = x-q*xx; x = t;
	t = yy; yy = y-q*yy; y = t;
    }
    return a;
}
long long mod_inverse(long long a, long long n) {
    long long x, y;
    long long d = extended_euclid(a, n, x, y);
    if (d > 1) return -1;
    return mod(x,n);
}
PII chinese_remainder_theorem(long long x, long long a, long long y, long long b) {
    long long s, t;
    long long d = extended_euclid(x, y, s, t);
    if (a%d != b%d) return make_pair(0, -1);
    return make_pair(mod(s*b*x+t*a*y,x*y)/d, x*y/d);
}
PII chinese_remainder_theorem(const VI &x, const VI &a) {
    PII ret = make_pair(a[0], x[0]);
    for (long long i = 1; i < x.size(); i++) {
	ret = chinese_remainder_theorem(ret.second, ret.first, x[i], a[i]);
	if (ret.second == -1) break;
    }
    return ret;
}
long long power_mod(long long a, long long b, long long m) {
    if (b == 0) {
	return 1;
    } else if (b == 1) {
	return a % m;
    } else {
	long long tmp = power_mod(a, b >> 1, m);
	if (b % 2 == 0) {
	    return tmp * tmp % m;
	} else {
	    return tmp * tmp * a % m;
	}
    }
}
PII fact_mod(long long n, long long p, const VI& facts) {
    if (n == 0) return make_pair(1, 0);
    PII tmp = fact_mod(n / p, p, facts);
    long long a = tmp.first;
    long long e = tmp.second;
    e += n / p;
    if (n / p % 2 != 0) return make_pair(a * (p - facts[n % p]) %p, e);
    else return make_pair(a * facts[n % p] % p, e);
}
long long n_fact_fact(long long n, long long m, long long p, const VI& facts) {
    if (n == 0 || n == 1) {
	return 1;
    } else if (n < m) {
	return facts[n] * n_fact_fact(n / p, m, p, facts) % m;
    } else {
	long long a = facts[m - 1];
	long long b = facts[n % m];
	long long c = n_fact_fact(n / p, m, p, facts);
	return power_mod(a, n / m, m) * b * c % m;
    }
}
long long power(long long a, long long i) {
    if (i == 0) {
	return 1;
    } else if (i == 1) {
	return a;
    } else {
	long long tmp = power(a, i >> 1);
	if (i % 2 == 0) return tmp * tmp;
	else return tmp * tmp * a;
    }
}
long long comb_mod2(long long n, long long r, long long m, PII pa, const VI facts, const VI& tmp) {
    long long p, a;
    p = pa.first; a = pa.second;
    long long b = a;
    while (b > 0) {
	PII t1 = fact_mod(n, p, tmp);
	PII t2 = fact_mod(r, p, tmp);
	PII t3 = fact_mod(n - r, p, tmp);
	long long e1, e2, e3;
	e1 = t1.second; e2 = t2.second; e3 = t3.second;
	if (e1 >= e2 + e3 + a) return 0;
	if (e1 >= e2 + e3 + b) break;
	b = b - 1;
    }
    long long m1 = n_fact_fact(n, m, p, facts);
    long long m2 = n_fact_fact(r, m, p ,facts);
    long long m3 = n_fact_fact(n - r, m, p, facts);
    return power(p, b) * m1 * mod_inverse(m2, m) * mod_inverse(m3, m) % m;
}
long long solve(long long n, long long r) {
    VI xs(factors.size(), 0);
    VI as(factors.size(), 0);
	for (long long i = 0; i < factors.size(); ++i) {
		xs[i] = power(factors[i].first, factors[i].second);
		as[i] = comb_mod2(n, r, xs[i], factors[i], facts1[i], facts2[i]);
    }
    return chinese_remainder_theorem(xs, as).first;
}
VI gen_fact(long long m) {
    VI ret(m, 1);
    ret.push_back(1);
    for (long long i = 1; i < m; ++i) {
		if (gcd(i, m) == 1) ret[i] = ret[i - 1] * i % m;
		else ret[i] = ret[i - 1];
    }
    return ret;
}
void init(long long m) {
	factors.clear();
	facts1.clear();
	facts2.clear();
	long long prev=-1;
	long long cur;
	while(m!=1)	{
		cur=modfact[m];
		if(cur!=prev)	{
			factors.push_back(make_pair(cur,1));
		}
		else	{
			factors[factors.size()-1].second++;
		}
		prev=cur;
		m=m/cur;
	}
	for(long long i = 0; i < factors.size(); ++i) {
		long long p = factors[i].first;
		long long a = factors[i].second;
		facts1.push_back(gen_fact(power(p, a)));
		facts2.push_back(gen_fact(p));
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
int main() {
	long long T;
	long long n,k;
	long long m;
	sieve();
	scanf("%lld", &T);
	for(long long i = 0; i < T; ++i) {
		scanf("%lld %lld %lld",&n,&k,&m);
		init(m);
		if(n<=k)	{
			printf("1 1\n");
			continue;
		}
		if(n%k==0)	{
			cout<<n/k<<" 1"<<endl;
			continue;
		}
		long long newn=(n/k)-1;
		long long newk=k-(n%k);
		printf("%lld %lld\n",(newn+2),solve(newn+newk+1, newn+1));
	}
	return 0;
}