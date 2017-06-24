#include <bits/stdc++.h>
using namespace std;
long long int get_lcm(long long int a,long long int b)	{
	return (long long int)((a/__gcd(a,b))*b);
}
int main()	{
	int n;
	scanf("%d",&n);
	if(n==1)	{
		cout<<"2\n";
		return 0;
	}
	cout<<"2\n";
	long long int lcm=2;
	long long int newlcm;
	for(int i=2;i<=n;i++)	{
		newlcm=get_lcm(lcm,i+1);
		cout<<(newlcm*newlcm-lcm)/i<<endl;
		lcm=newlcm;
	}
	return 0;
}