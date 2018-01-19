#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> > bits;
int main()	{
	long long n,k;
	cin>>n>>k;
	long long t=n;
	long long b=0;
	while(t>0)	{
		bits.push_back(make_pair(t%2,b));
		b++;
		t/=2;
	}
	reverse(bits.begin(),bits.end());
	for(long long i=-1;i>=-20;i--)	{
		bits.push_back(make_pair(0,i));
	}
	long long cur=0;
	for(long long i=0;i<bits.size();i++)	{
		// cout<<bits[i].first<<" "<<bits[i].second<<endl;
		cur+=bits[i].first;
	}
	b=cur;
	if(k<b)	{
		cout<<"No\n";
		return 0;
	}
	// cout<<b<<endl;
	// getchar();
	// getchar();
	// getchar();
	// getchar();
	// getchar();
	// getchar();
	while(b<k)	{
		cur=b;
		for(long long i=0;i<bits.size();i++)	{
//			t=k-b;
			if(cur==k)	{
				break;
			}
			if(bits[i].first==0)	{
				continue;
			}
			if(bits[i].first+cur<=k)	{
				bits[i+1].first+=(bits[i].first*2);
				cur=cur+bits[i].first;
				bits[i].first=0;
			}
			else	{
				bits[i+1].first+=2*(k-cur);
				bits[i].first-=(k-cur);
				cur=k;
			}
		}
		b=cur;
		// for(long long i=0;i<bits.size();i++)	{
		// 	cout<<bits[i].first<<" "<<bits[i].second<<endl;
		// 	//cur+=bits[i].first;
		// }
		// getchar();
	}
	vector<long long> ans;
	for(long long i=0;i<bits.size();i++)	{
		for(long long j=0;j<bits[i].first;j++)	{
			ans.push_back(bits[i].second);
		}
	}
	cout<<"Yes\n";
	for(long long i=0;i<k;i++)	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}