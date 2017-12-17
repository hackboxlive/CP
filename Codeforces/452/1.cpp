#include <bits/stdc++.h>
using namespace std;
int arr[200100];
int main()	{
	int n;
	cin>>n;
	int two=0;
	int one=0;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
		if(arr[i]==2)	{
			two++;
		}
		else	{
			one++;
		}
	}
	int ans=0;
	if(two<=one)	{
		ans=two;
		one-=two;
		ans+=(one/3);
	}
	else	{
		ans=one;
	}
	cout<<ans<<endl;
	return 0;
}