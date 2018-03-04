#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int main()	{
	int a,b;
	cin>>a>>b;
	int diff=abs(a-b);
	int half_a=diff/2;
	int half_b=diff-half_a;
	long long ans=0;
	ans+=half_a*(half_a+1)/2;
	ans+=half_b*(half_b+1)/2;
	cout<<ans<<endl;
	return 0;
}