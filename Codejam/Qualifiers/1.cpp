#include <bits/stdc++.h>
using namespace std;

int main()	{
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)	{
		int d;
		string p;
		cin>>d;
		cin>>p;
		int num_s=0;
		int cur=0;
		int fact=1;
		for(int i=0;i<p.length();i++)	{
			if(p[i]=='S')	{
				num_s++;
				cur+=fact;
			}
			else	{
				fact<<=1;
			}
		}
		cout<<"Case #"<<tt<<": ";
		if(num_s>d)	{
			cout<<"IMPOSSIBLE";
		}
		else	{
			int ans=0;
			while(cur>d)	{
				ans++;
				for(int i=p.length()-1;i>=1;i--)	{
					if(p[i]=='S' && p[i-1]=='C')	{
						swap(p[i],p[i-1]);
						break;
					}
				}
				cur=0;
				fact=1;
				for(int i=0;i<p.length();i++)	{
					if(p[i]=='S')	{
						cur+=fact;
					}
					else	{
						fact<<=1;
					}
				}				
			}
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
}