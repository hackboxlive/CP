#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()	{
	string s;
	cin>>s;
	int len=s.length();
	long long int halfans;
	long long int prevans=0;
	long long int curans;
	long long ans=90-s[len-1];
	for(int i=len-2;i>=0;i--)	{
		halfans=90-s[i+1];
		curans=90-s[i];
		ans=(ans+(curans*((prevans*26)%MOD+halfans+1)%MOD)%MOD)%MOD;
		prevans=(prevans*26)%MOD+halfans;
//		cout<<halfans<<" "<<curans<<" "<<prevans<<endl;
	}
	cout<<ans<<endl;
}