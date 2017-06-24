#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	long long int pos;
	cin>>n;
	cin>>pos;
	int val=n;
	long long int lo=1;
	long long int hi=(long long int)pow(2,n)-1;
	long long int mid;
	while(lo<=hi)	{
//		cout<<lo<<" "<<hi<<endl;
		mid=lo+(hi-lo)/2;
		if(mid>pos)	{
			hi=mid-1;
			val--;
		}
		else if(mid<pos)	{
			lo=mid+1;
			val--;
		}
		else	{
			cout<<val;
			return 0;
		}
	}
	return 0;
}