#include <bits/stdc++.h>
using namespace std;

int diffs[1010];

int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)	{
		string s;
		int n;
		cin>>s;
		cin>>n;
		long long ans=0;
		int t_one=0,t_two=0;
		for(int i=0;i<s.length();i++)	{
			if(s[i]=='a')	{
				t_one++;
			}
			else	{
				t_two++;
			}
			diffs[i]=t_one-t_two;
			if(t_one>t_two)	{
				ans++;
			}
		}
		if(t_one==t_two)	{
			ans=ans*n;
		}
		if(t_one>t_two)	{
			int rem=t_one-t_two;
			int loop=1;
			bool flag=true;
			while(loop<n && flag)	{
				loop++;
				flag=false;
				for(int i=0;i<s.length();i++)	{
					diffs[i]+=rem;
					if(diffs[i]<=0)	{
						flag=true;
					}
					if(diffs[i]>0)	{
						ans++;
					}
				}
			}
			ans+=(n-loop)*(long long)s.length();
		}
		if(t_one<t_two)	{
			int rem=t_two-t_one;
			int loop=1;
			bool flag=true;
			while(loop<n && flag)	{
				loop++;
				flag=false;
				for(int i=0;i<s.length();i++)	{
					diffs[i]-=rem;
					if(diffs[i]>0)	{
						flag=true;
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}