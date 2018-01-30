#include <bits/stdc++.h>
using namespace std;

int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,k,s;
		cin>>n>>k>>s;
		int ans;
		if((s*k)%n==0)	{
			ans=(s*k)/n;
		}
		else	{
			ans=((s*k)/n)+1;
		}
		int num=0;
		int day=1;
		bool flag=true;
		int v=1;
		while(day<=s)	{
			if(day%7!=0 && v<=ans)	{
				num+=n;
			}
			num-=k;
			// cout<<num<<endl;
			if(num<0)	{
				flag=false;
			}
			day++;
		}
		if(flag==true)	{
			cout<<ans<<endl;
		}
		else	{
			cout<<"-1\n";
		}
	}
	return 0;
}