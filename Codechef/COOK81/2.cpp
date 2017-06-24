#include <bits/stdc++.h>
using namespace std;
vector<long long int> arr;
int main()	{
	int t;
	long long n,k;
	string s;
	scanf("%d",&t);
	while(t--)	{
		scanf("%lld %lld",&n,&k);
		cin>>s;
		int bcnt=0;
		for(int i=s.length()-1;i>=0;i--)	{
			if(s[i]=='b')	{
				bcnt++;
			}
			if(s[i]=='a')	{
				arr.push_back(bcnt);
			}
		}
		long long val=0;
		for(int i=0;i<arr.size();i++)	{
			val+=k*arr[i];
			val+=(k-1)*k*bcnt/2;
		}
		printf("%lld\n",val);
		arr.clear();
	}
	return 0;
}