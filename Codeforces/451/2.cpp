#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	int a,b;
	cin>>a>>b;
	for(int i=0;i*a<=n;i++)	{
		if((n-a*i)%b==0)	{
			cout<<"YES\n";
			cout<<i<<" "<<(n-a*i)/b<<endl;
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}