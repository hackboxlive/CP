#include <bits/stdc++.h>
using namespace std;

int main()	{
	int n;
	cin>>n;
	while(n--)	{
		int x;	
		cin>>x;
		bool flag=false;
		for(int i=0;i<=x;i+=3)	{
			if((x-i)%7==0)	{
				flag=true;
				break;
			}
		}
		if(flag)	{
			cout<<"YES\n";
		}
		else	{
			cout<<"NO\n";
		}
	}
	return 0;
}