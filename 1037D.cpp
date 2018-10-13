//started at 23:57pm
#include <bits/stdc++.h>
using namespace std;

vector<int> g[200200];
int arr[200200];

int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	if(arr[0] != 1)	{
		cout<<"No\n";
		return 0;
	}
	queue<int> q;
	q.push(1);
	
	return 0;
}