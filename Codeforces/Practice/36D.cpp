#include <bits/stdc++.h>
using namespace std;
int main()	{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,k;
	int n,m;
	cin>>t>>k;
	while(t--)	{
		cin>>n>>m;
		if(n>m)	{
			swap(n,m);
		}
		if(k==1)	{
			if(n%2==0)	{
				cout<<"+\n";
			}
			else	{
				if(m%2==0)	{
					cout<<"+\n";
				}
				else	{
					cout<<"-\n";
				}
			}
			continue;
		}
		if(n%(k+1)==0)	{
			cout<<"+\n";
			continue;
		}
		int st=n/(k+1);
		int ch;
		if(st%2==0)	{
			ch=0;
		}
		else	{
			ch=1;
		}
		if((n%2+m%2)%2==0)	{
			if(ch==0)	{
				cout<<"-\n";
			}
			else	{
				cout<<"+\n";
			}
		}
		else	{
			if(ch==0)	{
				cout<<"+\n";
			}
			else	{
				cout<<"-\n";
			}
		}
	}
	return 0;
}