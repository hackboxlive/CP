#include <bits/stdc++.h>
using namespace std;
long long rev(int n)	{
	string s=to_string(n);
	int len=s.length();
	int d;
	long long ans=n;
	for(int i=len-1;i>=0;i--)	{
		d=s[i]-'0';
		ans=ans*10+d;
	}
	return ans;
}
int main()	{
	long long n,p;
	cin>>n>>p;
	long long ans=0;
	long long num;
	for(int i=1;i<=n;i++)	{
		num=rev(i);
		ans=ans+num;
		ans=ans%p;
	}
	cout<<ans<<endl;
	return 0;
}