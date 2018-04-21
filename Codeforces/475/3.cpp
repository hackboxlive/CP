#include <bits/stdc++.h>
using namespace std;
const long long modd=1e9+9;
long long b_pow[100100],a_pow[100100];
long long fast_pow(long long a,long long m)	{
	if(m==0)	{
		return 1;
	}
	if(m==1)	{
		return a;
	}
	long long ans=fast_pow(a,m/2);
	ans=ans*ans;
	ans%=modd;
	if(m%2==1)	{
		ans=ans*a;
		ans%=modd;
	}
	return ans;
}
long long positive_modulo(long long i,long long n) {
    return (i % n + n) % n;
}
int main()	{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	long long n,a,b,k;
	cin>>n>>a>>b>>k;
	string s;
	cin>>s;
	long long ans=0;
	b_pow[0]=a_pow[0]=1;
	for(int i=1;i<k;i++)	{
		b_pow[i]=b_pow[i-1]*b;
		b_pow[i]=positive_modulo(b_pow[i],modd);
		a_pow[i]=a_pow[i-1]*a;
		a_pow[i]=positive_modulo(a_pow[i],modd);
	}
	if(a==b)	{
		long long temp=n+1;
		temp/=k;
		for(int i=0;i<k;i++)	{
			if(s[i]=='+')	{
				ans++;
			}
			else	{
				ans--;
			}
		}
		ans=positive_modulo(ans,modd);
		ans*=temp;
		ans=positive_modulo(ans,modd);
		ans*=fast_pow(a,n);
		ans=positive_modulo(ans,modd);
	}
	else	{
		if(a<b)	{
			swap(a,b);
		}
		long long t1=0;
		t1=fast_pow(a,n+1);
		//cout<<t1<<endl;
		//cout<<fast_pow(a,n+1)<<endl;;
		t1-=fast_pow(b,n+1);
		t1=positive_modulo(t1,modd);
		long long t2=0,temp;
		for(int i=0;i<k;i++)	{
			if(s[i]=='+')	{
				temp=a_pow[k-1-i];
				temp*=b_pow[i];
				temp=positive_modulo(temp,modd);
				t2+=temp;
				t2=positive_modulo(t2,modd);
			}
			else	{
				temp=a_pow[k-1-i];
				temp*=b_pow[i];
				temp=positive_modulo(temp,modd);
				t2-=temp;
				t2=positive_modulo(t2,modd);
			}
		}
		cout<<t2<<endl;
		long long t3=0;
		t3=fast_pow(a,k);
		t3-=fast_pow(b,k);
		t3=positive_modulo(t3,modd);
		t3=fast_pow(t3,modd-2);
		cout<<t3<<endl;
		ans=t1*t2;
		ans=positive_modulo(ans,modd);
		ans*=t3;
		ans=positive_modulo(ans,modd);
	}
	cout<<ans<<endl;
	return 0;
}