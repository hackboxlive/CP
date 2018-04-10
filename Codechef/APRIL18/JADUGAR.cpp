#include <bits/stdc++.h>
using namespace std;

const long long m=1e9+7;

long long pow_a[10001000];
long long pow_bk[10001000];
long long inv_k[10001000];

int main()	{
	long long n,k,a,b;
	cin>>n>>k>>a>>b;
	k%=m;
	a%=m;
	b%=m;
	if(n==1)	{
		cout<<k<<endl;
		return 0;
	}
	if(n==2)	{
		long long ans=a+b*k;
		ans%=m;
		ans*=k;
		ans%=m;
		cout<<ans<<endl;
		return 0;
	}
	if(n==3)	{
		long long ans=a+b*k;
		ans%=m;
		ans*=k;
		ans%=m;
		ans*=(a+2*b*k);
		ans%=m;
		cout<<ans<<endl;
		return 0;
	}
	inv_k[1]=1;
	for(int i=2;i<=n;i++)	{
		inv_k[i]=(inv_k[m%i]*(m-m/i))%m;
	}
	pow_a[0]=1;
	pow_bk[0]=1;
	long long bk=b*k;
	bk%=m;
	for(int i=1;i<=n-2;i++)	{
		pow_a[i]=pow_a[i-1]*a;
		pow_a[i]%=m;
		pow_bk[i]=pow_bk[i-1]*bk;
		pow_bk[i]%=m;
	}
	long long term;
	long long coeff=1;
	long long ans=0;
	long long p=n+1;
	for(int i=0;i<=n-2;i++)	{
		term=pow_a[n-2-i];
		term*=pow_bk[i];
		term%=m;
		term*=coeff;
		term%=m;
		ans+=term;
		ans%=m;
		coeff*=(p+i);
		coeff%=m;
		coeff*=(p-i-3);
		coeff%=m;
		coeff*=inv_k[i+2];
		coeff%=m;
		coeff*=inv_k[i+1];
		coeff%=m;
	}
	ans*=k;
	ans%=m;
	ans*=((a+bk)%m);
	ans%=m;
	cout<<ans<<endl;
	return 0;
}