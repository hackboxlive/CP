#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,m;
	cin>>n>>m;
	int ans=(n-1)*(m-1);
	if(ans<0)	{
		cout<<"0\n";
	}
	else	{
		cout<<ans<<endl;
	}
	return 0;
}