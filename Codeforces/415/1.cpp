#include <bits/stdc++.h>
using namespace std;
int arr[110];
int roundup(double val)	{
	if(val-(int)val>=0.5)	{
		return (int)val+1;
	}
	return (int)val;
}
int main()	{
	int n,k;
	cin>>n>>k;
	double curavg=0;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
		curavg+=arr[i];
	}
	int tot=curavg;
	curavg/=n;
	int cnt=0;
	int i=1;
	while(roundup(curavg)<k)	{
//		cout<<curavg<<endl;
		tot+=k;
		curavg=1.0*tot/(n+i);
		i++;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}