#include <bits/stdc++.h>
using namespace std;
vector<int> deg;
int freq[20002000];
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,a,b,c,m;
		cin>>n>>a>>b>>c>>m;
		int x=0,w;
		for(int i=0;i<n;i++)	{
			w=x+c;
			deg.push_back(w);
			x=(a*x+b);
			x%=m;
		}
		sort(deg.begin(),deg.end());
		reverse(deg.begin(), deg.end())
		
	}
	return 0;
}