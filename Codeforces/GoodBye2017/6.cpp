#include <bits/stdc++.h>
using namespace std;
vector<long long> g,r,b;
vector<pair<long long,char> > rb;
int main()	{
	int n;
	cin>>n;
	int p;
	string s;
	long long inf=1LL<<60;
	r.push_back(-inf);
	g.push_back(-inf);
	b.push_back(-inf);
	for(int i=0;i<n;i++)	{
		cin>>p>>s;
		if(s[0]=='R')	{
			r.push_back(p);
			rb.push_back(make_pair(p,'R'));
		}
		if(s[0]=='B')	{
			b.push_back(p);
			rb.push_back(make_pair(p,'B'));
		}
		if(s[0]=='G')	{
			g.push_back(p);
		}
	}
	r.push_back(inf);
	b.push_back(inf);
	g.push_back(inf);
	long long ans=0;
	// for(int i=0;i<g.size();i++)	{
	// 	cout<<g[i]<<" ";
	// }
	// cout<<endl;
	if(g.size()==2)	{
		//special case
		if(r.size()!=2)	{
			ans+=(r[r.size()-2]-r[1]);
		}
		if(b.size()!=2)	{
			ans+=(long long)(b[b.size()-2]-b[1]);
		}//connect red and blue
		long long mindis=inf;
		for(int i=0;i<rb.size()-1;i++)	{
			if(rb[i].second!=rb[i+1].second)	{
				mindis=min(mindis,abs(rb[i+1].first-rb[i].first));
			}
		}
		ans+=mindis;
//		cout<<"ans = "<<ans<<endl;
	}
	else	{
		ans+=(g[g.size()-2]-g[1]);
//		cout<<ans<<endl;
		long long mindis;
		int pos;
		for(int i=1;i<r.size()-1;i++)	{
			pos=lower_bound(g.begin(),g.end(),r[i])-g.begin();
			mindis=min(mindis,g[pos]-r[i]);
			mindis=min(mindis,r[i]-g[pos-1]);
			ans+=mindis;
		}
		
		for(int i=1;i<b.size()-1;i++)	{
			mindis=min(b[i]-b[i-1],b[i+1]-b[i]);
			pos=lower_bound(g.begin(),g.end(),b[i])-g.begin();
			mindis=min(mindis,g[pos]-b[i]);
			mindis=min(mindis,b[i]-g[pos-1]);
//			cout<<mindis<<endl;
			ans+=mindis;
		}
	}
	cout<<ans<<endl;
	return 0;
}