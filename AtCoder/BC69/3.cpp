#include <bits/stdc++.h>
using namespace std;
int even,odd,four;
int main()	{
	int n,v;
	cin>>n;
	even=0;
	odd=0;
	four=0;
	for(int i=0;i<n;i++)	{
		cin>>v;
		if(v%4==0)	{
			four++;
		}
		else if(v%2==0)	{
			even++;
		}
		else	{
			odd++;
		}
	}
	if(odd<=four)	{
		cout<<"Yes\n";
	}
	else	{
		if(odd==four+1 && even==0)	{
			cout<<"Yes\n";
		}
		else	{
			cout<<"No\n";
		}
	}
	return 0;
}