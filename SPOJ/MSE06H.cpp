#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v;
int n,m,k;
int BIT[1100];
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	if(p1.first!=p2.first)	{
		return p1.first<p2.first;
	}
	else	{
		return p1.second<p2.second;
	}
}
int query(int x)	{
	int sum=0;
	for(;x>0;x=x-(x&-x))	{
		sum=sum+BIT[x];
	}
	return sum;
}
void update(int x)	{
	for(;x<=m;x=x+(x&-x))	{
		BIT[x]++;
	}
}
int main()	{
	int t,c=0,src,dest;
	scanf("%d",&t);
	while(t--)	{
		memset(BIT,0,sizeof(BIT));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;i++)	{
			scanf("%d%d",&src,&dest);
			v.push_back(make_pair(src,dest));
		}
		sort(v.begin(),v.end(),comp);
		long long int sum=0;
		for(int i=0;i<k;i++)	{
			sum=sum+query(m-v[i].second);
//			cout<<i<<" "<<query(m)<<" "<<query(v[i].second-1)<<endl;
//			cout<<"Sum"<<i<<" "<<sum<<endl;
			update(m-v[i].second+1);
//			for(int i=1;i<=m;i++)	{
//				cout<<BIT[i]<<endl;
//			}
		}
		printf("Test case %d: %lld\n",++c,sum);
		v.clear();
	}
	return 0;
}