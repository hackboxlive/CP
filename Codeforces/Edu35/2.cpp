#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int n,a,b;
	cin>>n>>a>>b;
	int ans=-1;
	for(int i=1;i<n;i++)	{
		int first=i;
		int second=n-i;
		bool poss=true;
		if(first>a || second>b)	{
			poss=false;
		}
		if(poss)	{
			ans=max(ans,min(a/first,b/second));
		}
	}
	cout<<ans<<endl;
	return 0;
}