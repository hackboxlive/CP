#include <bits/stdc++.h>
using namespace std;
long long modu=1e9+7;
long long a[100100],b[100100];
long long power_expo(long long a,long long m)	{
	if(m==0)	{
		return 1;
	}
	if(m==1)	{
		return a;
	}
	long long ans=power_expo(a,m/2);
	ans=ans*ans;
	ans=ans%modu;
	if(m%2==1)	{
		ans=ans*a;
		ans=ans%modu;
	}
	return ans;
}
long long inv(long long a)	{
	return power_expo(a,modu-2);
}
int main()	{
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)	{
		cin>>b[i];
	}
	if(m==1)	{
		cout<<"0\n";
		return 0;
	}
	int last=n;
	int cz=0;
	for(int i=0;i<n;i++)	{
		if(a[i]!=0 && b[i]!=0 && a[i]!=b[i])	{
			last=i;
			break;
		}
		if(a[i]==0 || b[i]==0)	{
			cz++;
		}
	}
	if(cz==0 && last<n && a[last]>b[last])	{
		cout<<"1\n";
		return 0;
	}
	else if(cz==0 && last<n && a[last]<b[last])	{
		cout<<"0\n";
		return 0;
	}
	else if(last==n && cz==0)	{
		cout<<"0\n";
		return 0;
	}
	long long ans=0,temp,pre=0;
	for(int i=1;i<=m-1;i++)	{
		temp=i*(m-i);
		temp%=modu;
		temp*=inv(m);
		temp%=modu;
		temp*=inv(m);
		pre+=temp;
		pre%=modu;
	}
	if(last<n && a[last]>b[last])	{
		ans=1;
	}
	for(int i=last-1;i>=0;i--)	{
		if(a[i]==0 && b[i]!=0)	{
			ans=ans*inv(m);
			ans=ans%modu;
			temp=m-b[i];
			temp=temp*inv(m);
			ans=ans+temp;
			ans=ans%modu;
		}
		if(a[i]!=0 && b[i]==0)	{
			ans=ans*inv(m);
			ans=ans%modu;
			temp=a[i]-1;
			temp=temp*inv(m);
			ans=ans+temp;
			ans=ans%modu;
		}
		if(a[i]==0 && b[i]==0)	{
			ans=ans*inv(m);
			ans=ans%modu;
			temp=pre;
			ans=ans+temp;
			ans=ans%modu;
		}
	}
	cout<<ans<<endl;
	return 0;
}