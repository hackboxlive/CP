#include <bits/stdc++.h>
using namespace std;
long long int arr[1001000];
pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    if(a == 0) return make_pair(b, make_pair(0, 1));
    pair<int, pair<int, int> > p;
    p = extendedEuclid(b % a, a);
    return make_pair(p.first, make_pair(p.second.second - p.second.first*(b/a), p.second.first));
}
int modInverse(int a, int m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}
void precompute()	{
	arr[0]=1;
	arr[1]=3;
	long long int firstt;
	long long int secondt;
	int mod=1000003;
	for(int i=2;i<1000000;i++)	{
		int invmod=modInverse(i,mod);
		firstt=(((3*(2*i-1))%mod)*arr[i-1])%mod;
		secondt=((i-1)*arr[i-2])%mod;
		arr[i]=((((firstt-secondt)%mod)*(invmod))%mod);
		if(arr[i]<0)	{
			arr[i]+=mod;
		}
		cout<<"For i="<<i<<"\tfirst term="<<firstt<<"\tsecond term="<<secondt<<"\tans="<<arr[i]<<endl;
	}
	return;
}
int main()	{
	precompute();
	int t;
	int n;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		printf("%lld\n",arr[n-1]);
//		n++;
	}
	return 0;
}