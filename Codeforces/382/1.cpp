#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int g,t;
	for(int i=0;i<n;i++)	{
		if(s[i]=='T')	{
			t=i;
		}
		if(s[i]=='G')	{
			g=i;
		}
	}
	if(g<t)	{
		bool flag = true;
		bool flag2 = false;
		for(int i=g+k;i<=t;i+=k)	{
			if(s[i]=='#')	{
				flag = false;
				break;
			}
			if(i==t)	{
				flag2 = true;
			}
		}
		if(flag==false)	{
			cout<<"NO";
		}
		else	{
			if(flag2 == true)	{
				cout<<"YES";
			}
			else	{
				cout<<"NO";
			}
		}
	}
	else	{
		bool flag = true;
		bool flag2 = false;
		for(int i=g-k;i>=t;i-=k)	{
			if(s[i]=='#')	{
				flag = false;
				break;
			}
			if(i==t)	{
				flag2 = true;
			}
		}
		if(flag==false)	{
			cout<<"NO";
		}
		else	{
			if(flag2 == true)	{
				cout<<"YES";
			}
			else	{
				cout<<"NO";
			}
		}
	}
	return 0;
}