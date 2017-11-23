#include <bits/stdc++.h>
using namespace std;
int main()	{
	int k=2;
	vector<int> v;
	for(int num=1;num<=100000;k++)	{
		v.push_back(num);
		num=((1<<k)-1)*(1<<(k-1));
//		cout<<num<<endl;
	}
	int n;
	cin>>n;
	int ans=1;
	for(int i=1;i<v.size();i++)	{
		if(n%v[i]==0)	{
			ans=v[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}