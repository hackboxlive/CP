#include <bits/stdc++.h>
using namespace std;
long long lt=2*1e9;
vector<long long> sq;
int lengthof(long long n)	{
	int ans=0;
	while(n>0)	{
		n/=10;
		ans++;
	}
	return ans;
}
bool exists(long long n,long long m)	{
	string mm=to_string(m);
	string nn=to_string(n);
	int ans=0;
	int l=0;int r=0;
	while(r<mm.length())	{
		if(mm[r]==nn[l])	{
			r++;
			ans++;
		}
		l++;
		if(l==nn.length())	{
			break;
		}
	}
	if(ans==mm.length())	{
		return true;
	}
	return false;
}
int main()	{
	for(long long i=1;i*i<=lt;i++)	{
		sq.push_back(i*i);
	}
	long long n;
	cin>>n;
	int ans=15;
	long long temp;
	for(int i=sq.size()-1;i>=0;i--)	{
		temp=sq[i];
		if(exists(n,temp))	{
			ans=min(ans,lengthof(n)-lengthof(temp));
		}
	}
	if(ans==15)	{
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}