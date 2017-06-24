#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	string s;
	scanf("%d",&t);
	while(t--)	{
		cin>>s;
		long long int moves=0;
		int ones=0;
		int zeros=0;
		for(int i=0;i<s.length()-1;i++)	{
			if(s[i]=='0' && s[i+1]=='1')	{
				zeros++;
				moves+=ones*(1LL+zeros);
			}
			else if(s[i]=='0' && s[i+1]=='0')	{
				zeros++;
			}
			else	{
				ones++;
				zeros=0;
			}
//			cout<<moves<<" "<<ones<<" "<<zeros<<endl;
		}
		if(s[s.length()-1]=='0')	{
			zeros++;
			moves+=ones*(1LL+zeros);
		}
		printf("%lld\n",moves);
	}
	return 0;
}