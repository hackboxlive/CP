#include <bits/stdc++.h>
using namespace std;

int main()	{
	long long t;
	cin>>t;
	while(t--)	{
		long long k;
		long long a,b;
		cin>>k>>a>>b;
		if(k==2)	{
			if((a+b)%3==0)	{
				cout<<"YES\n";
			}
			else	{
				cout<<"NO\n";
			}			
		}
		else if(k==3)	{
			if((a+b+((a+b)%10))%3==0)	{
				cout<<"YES\n";
			}
			else	{
				cout<<"NO\n";
			}
		}
		else	{
			long long rem=(a+b)+((a+b)%10);
			k=k-3;
			long long two=k/4;
			long long four=k/4;
			long long six=k/4;
			long long eight=k/4;
			if(k%4>=1)	{
				two++;
			}
			if(k%4>=2)	{
				four++;
			}
			if(k%4>=3)	{
				eight++;
			}
//			cout<<two<<" "<<four<<" "<<eight<<" "<<six<<endl;
			long long ans=rem;
			ans+=two*(((a+b)*2)%10);
			ans+=four*(((a+b)*4)%10);
			ans+=eight*(((a+b)*8)%10);
			ans+=six*(((a+b)*6)%10);
			if(ans%3==0)	{
				cout<<"YES\n";
			}
			else	{
				cout<<"NO\n";
			}
		}
	}
	return 0;
}