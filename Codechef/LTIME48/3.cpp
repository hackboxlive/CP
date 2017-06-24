#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > tree(100100);
int main()	{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)	{
		cin>>val;
		tree[val].push_back(i);
	}
	return 0;
}