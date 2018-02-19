#include <bits/stdc++.h>
using namespace std;

int main()	{
	int n;
	cin>>n;
	while(n--)	{
		int v=0;int va;
		for(int i=0;i<5;i++)	{
			cin>>va;
			v=v+va;
		}
		if(v==0)	{
			cout<<"Beginner\n";
		}
		if(v==1)	{
			cout<<"Junior Developer\n";
		}
		if(v==2)	{
			cout<<"Middle Developer\n";
		}
		if(v==3)	{
			cout<<"Senior Developer\n";
		}
		if(v==4)	{
			cout<<"Hacker\n";
		}
		if(v==5)	{
			cout<<"Jeff Dean\n";
		}
	}
	return 0;
}