#include <bits/stdc++.h>
using namespace std;
string s;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		cin>>s;
		int l=0,r=0;
		long long ans=0;
		for(int i=1;i<s.length();i++)	{
//			cout<<i<<" "<<r<<" "<<l<<endl;
			if(s[i]==s[r])	{
				ans+=(i-l);
			}
			else	{
				if(l>0 && s[i]==s[l-1])	{
					ans++;
//					cout<<i<<endl;
				}
				l=i;
			}
			r++;
		}
		cout<<ans<<endl;
	}
	return 0;
}