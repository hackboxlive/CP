#include <bits/stdc++.h>
using namespace std;

int main()	{
	int n;
	cin>>n;
	if(n==1)	{
		cout<<"1\n";
		return 0;
	}
	int ans[1001];
	ans[2]=2;
	ans[3]=4;
	for(int i=4;i<=n;i++)	{
		ans[i]=i+ans[i-2];
	}
	cout<<ans[n]<<endl;
	return 0;
}