#include <bits/stdc++.h>
using namespace std;

int main()	{
	long long n;
	cin>>n;
	if(n<=4)	{
		cout<<(n*(n-1))/2<<endl;
		return 0;
	}
	long long summ=2*n-1;
	int x;
	long long f=1;
	while(f-1<summ)	{
		f=f*10;
	}
	//141 => summ=281 & f=1000
	//150 => summ=299 & f=1000
	//500 => summ=999 & f=1000
	if(f-1==summ)	{
		x=1;
	}
	else	{
		f/=10;
		int y=1;
		while(y*f-1<summ)	{
			y++;
		}
		if(y*f-1==summ)	{
			x=y;
		}
		else	{
			x=y-1;
		}
	}
	//141 => summ=281 & f=100  & x=2
	//150 => summ=299 & f=100  & x=3
	//500 => summ=999 & f=1000 & x=1
//	cout<<summ<<" "<<f<<" "<<x<<endl;
	long long ans=0;
	long long i;
	for(i=1;(i*f-1)<=n;i++)	{
		ans+=(((i*f)-1)/2);
	}
	long long temp;//=(n+1-(x*f)/2);
	for(;i<=x;i++)	{
		ans+=(n+1-((i*f)/2));
		//cout<<temp<<endl;
	}
	cout<<ans<<endl;
	return 0;
}