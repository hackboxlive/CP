#include <bits/stdc++.h>
using namespace std;
long long a[100100],b[100100],c[100100];
long long pa[100100],pc[100100];
const int mod=1e9+7;
int p,q,r;
pair<long long,long long> search(int val)	{
	long long p1=upper_bound(a+1,a+p+1,val)-a;
	long long p2=upper_bound(c+1,c+r+1,val)-c;
	p1--;
	p2--;
	return make_pair(p1,p2);
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	pair<long long,long long> pos;
	while(t--)	{
		cin>>p>>q>>r;
		for(int i=1;i<=p;i++)	{
			cin>>a[i];
		}
		for(int i=1;i<=q;i++)	{
			cin>>b[i];
		}
		for(int i=1;i<=r;i++)	{
			cin>>c[i];
		}
		sort(a+1,a+p+1);
		sort(b+1,b+q+1);
		sort(c+1,c+r+1);
		pa[0]=pc[0]=0;
		for(int i=1;i<=p;i++)	{
			pa[i]=(pa[i-1]+a[i])%mod;
		}
		for(int i=1;i<=r;i++)	{
			pc[i]=(pc[i-1]+c[i])%mod;
		}
		long long ans=0;
		long long ff;
		long long xy,yz,xz,y2;
		for(int i=1;i<=q;i++)	{
			pos=search(b[i]);
			if(pos.first>0 && pos.second>0)	{
				ff=(pos.first*pos.second)%mod;
				y2=b[i]*b[i];
				y2%=mod;
				y2=ff*y2;
				y2%=mod;
				xy=b[i]*pa[pos.first];
				xy=xy%mod;
				xy=xy*pos.second;
				xy=xy%mod;
				yz=b[i]*pc[pos.second];
				yz%=mod;
				yz=yz*pos.first;
				yz%=mod;
				xz=pa[pos.first]*pc[pos.second];
				xz%=mod;
				ans=ans+y2;
				ans=ans%mod;
				ans=ans+xy;
				ans=ans%mod;
				ans=ans+yz;
				ans=ans%mod;
				ans=ans+xz;
				ans=ans%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}