#include <bits/stdc++.h>
using namespace std;
int arr[1001000];
void sieve()	{
	memset(arr,0,sizeof(arr));
	for(int i=2;i<1001000;i++)	{
		if(arr[i]==0)	{
			for(int j=2*i;j<1001000;j+=i)	{
				arr[j]=1;
			}
		}
	}
	return;
}
int main()	{
	sieve();
	int n;
	cin>>n;
	long long int num;
	long long int ca;
	for(int i=0;i<n;i++)	{
		cin>>num;
		ca=sqrt(num);
		if(num==1)	{
			cout<<"NO\n";
			continue;
		}
		if((long long int)ca*ca!=num)	{
			cout<<"NO\n";
		}
		else	{
			if(arr[ca]==0)	{
				cout<<"YES\n";
			}
			else	{
				cout<<"NO\n";
			}
		}
	}
	return 0;
}