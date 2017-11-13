#include <bits/stdc++.h>
using namespace std;
long long k,a,p,q,l,d,t;
long long f[10001000];
long long g[100100];
long long mat[2][2],base[2][2];
long long pre[100100][2][2];
void precompute()	{
	f[0]=f[1]=1;
	for(int i=2;i<=10000001;++i)	{
		f[i]=(f[i-1]*i)%p;
	}
}
long long expo(long long a,long long m)	{
	if(m==1)	{
		return a;
	}
	long long ans=expo(a,m/2);
	ans=(ans*ans)%p;
	if(m%2)	{
		ans=(ans*a)%p;
	}
	return ans;
}
long long multiplicative_inverse(long long n)	{
	return expo(n,p-2);
}
long long choose(long long n,long long r)	{
	return f[n]*((multiplicative_inverse(f[r])*multiplicative_inverse(f[n-r]))%p)%p;
}
long long choosek(long long n,long long r)	{
	return g[n]*((multiplicative_inverse(g[r])*multiplicative_inverse(g[n-r]))%p)%p;
}
void matrix_expo(int n)	{
	if(n==1)	{
		mat[0][0]=base[0][0];
		mat[0][1]=base[0][1];
		mat[1][0]=base[1][0];
		mat[1][1]=base[1][1];
		return;
	}
	matrix_expo(n/2);
	mat[0][0]=((mat[0][0]*mat[0][0])%p+(mat[0][1]*mat[1][0])%p)%p;
	mat[0][1]=((mat[0][0]*mat[0][1])%p+(mat[0][1]*mat[1][1])%p)%p;
	mat[1][0]=((mat[0][0]*mat[1][0])%p+(mat[1][0]*mat[1][1])%p)%p;
	mat[1][1]=((mat[0][1]*mat[1][0])%p+(mat[1][1]*mat[1][1])%p)%p;
	if(n%2)	{
		mat[0][0]=((mat[0][0]*base[0][0])%p+(mat[0][1]*base[1][0])%p)%p;
		mat[0][1]=((mat[0][0]*base[0][1])%p+(mat[0][1]*base[1][1])%p)%p;
		mat[1][0]=((mat[1][0]*base[0][0])%p+(mat[1][1]*base[1][0])%p)%p;
		mat[1][1]=((mat[1][0]*base[0][1])%p+(mat[1][1]*base[1][1])%p)%p;
	}
}
void precomputer()	{
	g[0]=g[1]=1;
	for(int i=2;i<=100010;++i)	{
		g[i]=(g[i-1]*i)%p;
	}
	for(int i=1;i<=100010;++i)	{
		base[0][0]=0;
		base[0][1]=a;
		base[1][0]=i;
		base[1][1]=a;
		matrix_expo(k-3);
		pre[i][0][0]=mat[0][0];
		pre[i][0][1]=mat[0][1];
		pre[i][1][0]=mat[1][0];
		pre[i][1][1]=mat[1][1];
	}
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>k>>a>>p>>q;
	if(k<=2)	{
		precompute();
		while(q--)	{
			cin>>l>>d>>t;
			long long ans=choose(d+t,l+1);
			if(d>=l+1)	{
				ans-=choose(d,l+1);
				ans+=p;
				ans%=p;
			}
			if(k==2)	{
				ans*=a;
				ans%=p;
			}
			cout<<ans<<endl;
		}
	}
	else	{		

		precomputer();
		
//		tt=clock();
//		cout<<tt<<endl;
		long long ans,term1,term2;
		while(q--)	{
//			tt=clock();
//			cout<<(tt-st)/(double)CLOCKS_PER_SEC<<endl;
			cin>>l>>d>>t;
			ans=0;
			term1=choosek(d,l);
			term2=(d+a)%p;
			if(k==3)	{
				ans=(term1*term2)%p;
				for(int i=1;i<t;i++)	{
					term1=(term1*(d+i))%p;
					term1=(term1*multiplicative_inverse(d+i-l))%p;
					term2=(d+a+i)%p;
					ans=(ans+(term1*term2)%p)%p;
				}
			}
			else	{
				ans=(term1*term2)%p;
				for(int i=1;i<t;i++)	{
					term1=(term1*(d+i))%p;
					term1=(term1*multiplicative_inverse(d+i-l))%p;
					term2=((d+i)*pre[d+i][0][0])%p;
					term2=(term2+(a*pre[d+i][1][0])%p)%p;
					term2=(term2+((d+i)*pre[d+i][0][1])%p)%p;
					term2=(term2+(a*pre[d+i][1][1])%p)%p;
					ans=(ans+term1*term2)%p;
					//printf("%lld %lld\n",term1,term2);
					//getchar();

				}
			}
			ans=(ans*a)%p;
			cout<<ans<<endl;
		}
	}
	return 0;
}