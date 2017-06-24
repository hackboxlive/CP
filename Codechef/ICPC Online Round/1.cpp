#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2)	{
			if(y1<y2)	{
				cout<<"up\n";
			}
			else	{
				cout<<"down\n";
			}
		}
		else if(y1==y2)	{
			if(x1<x2)	{
				cout<<"right\n";
			}
			else	{
				cout<<"left\n";
			}
		}
		else	{
			cout<<"sad\n";
		}
	}
	return 0;
}