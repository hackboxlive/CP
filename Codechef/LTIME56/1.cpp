#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		int arr[101];
		int odd=0,even=0;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
			if(arr[i]&1)	{
				odd++;
			}
			else	{
				even++;
			}
		}
		int cnt=0;
		if(odd&1)	{
			cnt++;
			odd--;
		}
		even+=odd/2;
		cout<<1+cnt<<endl;
	}
	return 0;
}