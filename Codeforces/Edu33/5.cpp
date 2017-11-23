#include <bits/stdc++.h>
using namespace std;
int lt=1e6;
long long modd=1e9+7;
int factor[1001000];
long long fact[1001001];
long long invfact[1001001];
vector<pair<int,int> > in;
vector<int> out;
long long powermod(int a,int b)	{
	if(b==1)	{
		return a;
	}
	if(b==0)	{
		return 1;
	}
	long long ans=1;
	ans=powermod(a,b/2);
	ans=(ans*ans)%modd;
	if(b&1)	{
		ans=(ans*a)%modd;
	}
	return ans;
}
void sieve()	{
	for(int i=2;i<=lt;i++)	{
		if(factor[i]==0)	{
			for(int j=i;j<=lt;j+=i)	{
				if(factor[j]==0)	{
					factor[j]=i;
				}
			}
		}
	}
	fact[0]=1;
	fact[1]=1;
	invfact[0]=1;
	invfact[1]=1;
	for(int i=2;i<=1001000;i++)	{
		fact[i]=fact[i-1]*i;
		fact[i]%=modd;
		invfact[i]=powermod(fact[i],modd-2);
//		cout<<invfact[i]<<endl;
	}
}
long long ncr(int n,int r)	{
	long long x=fact[n];
	x=x*invfact[r];
	x=x%modd;
	x=x*invfact[n-r];
	x=x%modd;
	return x;
}
int main()	{
	sieve();
	int t;
	cin>>t;
	int x,y;
	for(int i=0;i<t;i++)	{
		cin>>x>>y;
		in.push_back(make_pair(x,y));
	}
	int tt=t;
//	while(t--)	{
//		int x,y;
//		cin>>x>>y;
	for(int p=0;p<t;p++)	{
		long long ans=1;
		x=in[p].first;
		y=in[p].second;
		while(x!=1)	{
			int ff=factor[x];
			int numf=0;
			while(x%ff==0)	{
				numf++;
				x=x/ff;
			}
			ans=ans*(ncr(y+numf-1,y-1));
			ans%=modd;
		}

//		cout<<ans<<endl;
		ans*=powermod(2,y-1);
		ans%=modd;
//		cout<<ans<<endl;
		if(ans==0)	{
			cout<<in[p].first<<" "<<in[p].second;
			return 0;
		}
		out.push_back(ans);
	}
	for(int i=0;i<tt;i++)	{
		cout<<out[i]<<endl;
	}
	return 0;
}