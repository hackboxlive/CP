#include <bits/stdc++.h>
using namespace std;
int digit;
void dfs(long long int n,long long int id)	{
//		cout<<id<<" "<<n<<endl;
	if(n<=1)	{
		if(id==1)	{
			digit=n;
		}
		return;
	}
	long long int half=floor(log2(n/2));
	half++;
	half=(long long int)pow(2,half) - 1;
	if(half+1==id)	{
		digit=n%2;
		return;
	}
	if(id<=half)	{
		dfs(n/2,id);
		return;
	}
	if(id>half+1)	{
		dfs(n/2,id-half-1);
		return;
	}
}
int main()	{
	long long int n,l,r;
	cin>>n>>l>>r;
	int ctr=0;

	for(long long int i=l;i<=r;i++)	{
		dfs(n,i);
		if(digit)	{
//			cout<<i<<endl;
			ctr++;
		}
	}
	cout<<ctr<<endl;
	return 0;
}