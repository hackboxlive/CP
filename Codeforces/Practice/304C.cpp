#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	if(n&1)	{
		for(int i=0;i<n;i++)	{
			cout<<i<<" ";
		}
		cout<<endl;
		for(int i=0;i<n;i++)	{
			cout<<i<<" ";
		}
		cout<<endl;
		for(int i=0;i<n;i++)	{
			cout<<(i+i)%n<<" ";
		}
		cout<<endl;
	}
	else	{
		cout<<"-1\n";
	}
	return 0;
}