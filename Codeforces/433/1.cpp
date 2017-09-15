#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	int mid=n/2;
	int j;
	for(int i=mid;i>=1;i--)	{
		j=n-i;
		if(__gcd(i,j)==1)	{
			cout<<i<<" "<<j<<endl;
			return 0;
		}
	}
	return 0;
}