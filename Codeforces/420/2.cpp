#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long m,b;
	cin>>m>>b;
	long long ans;
	long long sterm;
	long long maxans=-1;
	for(long long i=0;i<=b;i++)	{
		ans=0;
		for(long long j=0;j<=i;j++)	{
			ans+=j*(m*(b-i)+1);
			//cout<<"First term="<<ans<<endl;
			sterm=m*(b-i);
			sterm=sterm*(sterm+1)/2;
			ans+=sterm;
			// cout<<"Second term="<<sterm<<endl;
			// cout<<"Finally="<<ans<<endl;
		}
//		cout<<ans<<endl;
		if(maxans<ans)	{
			maxans=ans;
		}
	}
	cout<<maxans<<endl;
	return 0;
}