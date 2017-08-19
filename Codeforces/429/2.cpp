#include <bits/stdc++.h>
using namespace std;
int main()	{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int odd=0;
	int val;
	for(int i=0;i<n;i++)	{
		cin>>val;
		if(val&1)	{
			odd++;
		}
	}
	if(odd>0)	{
		cout<<"First\n";
	}
	else	{
		cout<<"Second\n";
	}
	return 0;
}