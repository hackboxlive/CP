#include <bits/stdc++.h>
using namespace std;
struct node	{
	long long b;
	long long a;
}arr[100100];
bool comp(const node &p1, const node &p2)	{
	return p1.b<p2.b;
}
int main()	{
	long long n,r,avg;
	cin>>n>>r>>avg;
	avg=avg*n;
	long long curgrad=0;
	for(int i=0;i<n;i++)	{
		cin>>arr[i].a>>arr[i].b;
		curgrad+=arr[i].a;
	}
	if(curgrad>=avg)	{
		cout<<"0\n";
		return 0;
	}
	sort(arr,arr+n,comp);
	long long req=avg-curgrad;
	long long ans=0;
	for(int i=0;i<n;i++)	{
		if(arr[i].a<r)	{
			if(r-arr[i].a<=req)	{
				req-=(r-arr[i].a);
				ans+=(arr[i].b)*(r-arr[i].a);
			}
			else	{
				ans+=arr[i].b*req;
				req=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}