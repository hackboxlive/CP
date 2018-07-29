#include <bits/stdc++.h>
using namespace std;
const long long modd=998244353;
const long long lt=1e6;
long long fact[lt];
long long inv_fact[lt];
long long fast_expo(long long a,long long m)	{
	if(m==1)	{
		return a;
	}
	if(m==0)	{
		return 1;
	}
	long long ans=fast_expo(a,m/2);
	ans=ans*ans;
	ans%=modd;
	if(m&1)	{
		ans*=a;
		ans%=modd;
	}
	return ans;
}
void precompute()	{
	fact[0]=1;
	for(int i=1;i<=lt;i++)	{
		fact[i]=fact[i-1]*i;
		fact[i]%=modd;
	}
	inv_fact[lt]=fast_expo(fact[lt],modd-2);
	for(int i=lt-1;i>=0;i--)	{
		inv_fact[i]=inv_fact[i+1];
		inv_fact[i]*=(i+1);
		inv_fact[i]%=modd;
	}
}
int main()	{
	precompute();
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		vector<long long> arr(n);
		vector<long long> mp(n+1);
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
			mp[arr[i]]++;
		}
		long long ans=1,temp;
		for(int i=1;i<=n;i++)	{
			if(mp[i]%i!=0)	{
				ans=0;
				break;
			}
			else	{
				ans=ans*inv_fact[mp[i]/i];
				ans%=modd;
				temp=fast_expo(i,modd-2);
				for(int j=i;j<=mp[i];j+=i)	{
					ans*=temp;
					ans%=modd;
					ans*=fact[j];
					ans%=modd;
					ans*=inv_fact[j-i];
					ans%=modd;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}