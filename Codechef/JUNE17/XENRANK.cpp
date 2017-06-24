#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	long long u,v,sum;
	cin>>t;
	while(t--)	{
		cin>>u>>v;
		sum=u+v;
		sum=sum*(sum+1);
		sum/=2;
		sum=sum+u+1;
		cout<<sum<<endl;
	}
	return 0;
}