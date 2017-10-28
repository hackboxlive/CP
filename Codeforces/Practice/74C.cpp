#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,m;
	cin>>n>>m;
	int g=__gcd(n-1,m-1);
	cout<<g+1<<endl;
	return 0;
}