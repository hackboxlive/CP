#include <bits/stdc++.h>
using namespace std;
int arr[1510];
int cnt[1510];
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)	{
		cin>>arr[i];		
	}
	for(int i=1;i<=n;i++)	{
		for(int j=i+1;j<=n;j++)	{
			if(arr[j]<arr[i])	{
				ans++;
			}
		}
	}
//	cout<<ans<<endl;
	ans%=2;
	int m,l,r;
	cin>>m;
	while(m--)	{
		cin>>l>>r;
//		cout<<(((r-l)*(r-l+1))/2)<<endl;
		if(((((r-l)*(r-l+1))/2)&1)!=0)	{
			ans=!ans;
		}
		if(ans)	{
			cout<<"odd\n";
		}
		else	{
			cout<<"even\n";
		}
	}
	return 0;
}