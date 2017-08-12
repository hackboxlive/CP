#include <bits/stdc++.h>
using namespace std;
long long sq[10001000];
int main()	{
	int a,b;
	cin>>a>>b;
	long long ans=0;
	for(long long i=1;i<=10000000;i++)	{
		sq[i]=(long long)i*i;
	}
	int lid,hid;
	long long low,hi;
	for(int i=1;i<=a;i++)	{
		low=(long long)i*i;
		low+=1;
		hi=(long long)i*i;
		hi+=b;
		lid=lower_bound(sq,sq+10000001,low)-sq;
		hid=upper_bound(sq,sq+10000001,hi)-sq;
		ans+=(hid-lid);
	}
	cout<<ans<<endl;
	return 0;
}