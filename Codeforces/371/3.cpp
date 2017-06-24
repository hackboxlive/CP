#include <bits/stdc++.h>
using namespace std;
int ctr[5000000];
void add_integer(long long int n)	{
	string bitstring="";
	while(n!=0)	{
		int rem=n%10;
		if(rem%2==0)	{
			bitstring=bitstring+"0";
		}
		else	{
			bitstring=bitstring+"1";
		}
		n=n/10;
	}
	reverse(bitstring.begin(),bitstring.end());
	int pos=0;
	int val=1;
	for(int i=bitstring.length()-1;i>=0;i--)	{
		pos+=(bitstring[i]-48)*val;
		val=val*2;
	}
//	cout<<pos<<endl;
	ctr[pos]++;
	return;
}
void remove_integer(long long int n)	{
	string bitstring="";
	while(n!=0)	{
		int rem=n%10;
		if(rem%2==0)	{
			bitstring=bitstring+"0";
		}
		else	{
			bitstring=bitstring+"1";
		}
		n=n/10;
	}
	reverse(bitstring.begin(),bitstring.end());
	int pos=0;
	int val=1;
	for(int i=bitstring.length()-1;i>=0;i--)	{
		pos+=(bitstring[i]-48)*val;
		val=val*2;
	}
	ctr[pos]--;
	return;
}
int query_integer(long long int n)	{
	int val=1;
	int pos=0;
	while(n!=0)	{
		int rem=n%10;
		pos+=rem*val;
		val=val*2;
		n=n/10;
	}
	return ctr[pos];
}
int main()	{
	int t;
	string s;
	long long int n;
	scanf("%d",&t);
	memset(ctr,0,sizeof(ctr));
	while(t--)	{
		cin>>s;
		cin>>n;
		if(s[0]=='+')	{
			add_integer(n);
		}
		if(s[0]=='-')	{
			remove_integer(n);
		}
		if(s[0]=='?')	{
			int ans=query_integer(n);
			cout<<ans<<endl;
		}
	}
	return 0;
}