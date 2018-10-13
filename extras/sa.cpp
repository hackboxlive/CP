#include <bits/stdc++.h>
using namespace std;
long long ans;
int arr[100100];
int main()
{
	int n;
	cin>>n;
	ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<32;i++)
	{
		long long temp=0;
		long long prev=0;
		for(int j=0;j<n;j++)
		{
			if((arr[j]>>i) & 1)
			{
				prev=j+1;
			}
			temp+=prev;
			//cout<<prev<<" ";
		}
		//cout<<endl;
		ans += (1LL<<i) * temp;
	}
	cout<<ans<<endl;
	return 0;
}