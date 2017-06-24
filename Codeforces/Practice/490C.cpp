#include <bits/stdc++.h>
using namespace std;
int digits[1001000];
long long moda[1001000],modb[1001000];
long long fastexpo(int base,int power,int mod)	{
	if(power==1)	{
		return base%mod;
	}
	if(power%2==0)	{
		long long val=fastexpo(base,power/2,mod);
		return (val*val)%mod;
	}
	else	{
		long long val=fastexpo(base,power/2,mod);
		return (val*val*base)%mod;
	}
}
int main()	{
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)	{
		digits[i]=s[i]-'0';
	}
	int a,b;
	cin>>a>>b;
	moda[0]=digits[0]%a;
	for(int i=1;i<s.length();i++)	{
		moda[i]=(moda[i-1]*10+digits[i])%a;
	}
	modb[s.length()-1]=digits[s.length()-1]%b;
	for(int i=s.length()-2;i>=0;i--)	{
		modb[i]=(digits[i]*fastexpo(10,s.length()-1-i,b)%b+modb[i+1])%b;
	}
	for(int i=0;i<s.length()-1;i++)	{
		if(moda[i]==0 && modb[i+1]==0)	{
			if(digits[i+1]!=0 && s.length()-i-1>0 && i>=0)	{
				printf("YES\n");
				for(int j=0;j<=i;j++)	{
					printf("%d",digits[j]);
				}
				printf("\n");
				for(int j=i+1;j<s.length();j++)	{
					printf("%d",digits[j]);
				}
				printf("\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}