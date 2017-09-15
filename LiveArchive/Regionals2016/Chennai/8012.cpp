#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		int val;
		int freq[110];
		memset(freq,0,sizeof(freq));
		for(int i=0;i<n;i++)	{
			cin>>val;
			freq[val]++;
		}
		int ans=0;
		for(int i=1;i<=100;i++)	{
			if(freq[i]>1)	{
				ans+=(freq[i]-1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}