#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[200200];
long long pre[200200];
unordered_map<long long,vector<long long> > store;
long long find_freq(int l,int r,int v)	{
	long long a=lower_bound(store[v].begin(),store[v].end(),l)-store[v].begin();
	long long b=upper_bound(store[v].begin(),store[v].end(),r)-store[v].begin();
	return b-a;
}
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
int main()	{
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
		store[arr[i]].push_back(i);
	}
	pre[0]=arr[0];
	for(int i=1;i<n;i++)	{
		pre[i]=pre[i-1]+arr[i];
	}
	long long v,f,f1,f2,f3;
	long long tot=0;
	long long temp;
	string t,s="0";
	for(int i=0;i<n-1;i++)	{
		v=arr[i];
		temp=pre[n-1]-pre[i];
//		cout<<temp<<endl;
		f1=find_freq(i+1,n-1,v);
		temp-=(v*f1);
//		cout<<temp<<endl;
		v=arr[i]+1;
		f2=find_freq(i+1,n-1,v);
//		cout<<f<<endl;
		temp-=(v*f2);
		v=arr[i]-1;
		f3=find_freq(i+1,n-1,v);
//		cout<<f<<endl;
		temp-=(v*f3);
//		cout<<temp<<endl;
		temp-=((n-1-i-(f1+f2+f3))*arr[i]);
//		cout<<to_string(temp);
		s=findSum(s,to_string(temp));

//		tot+=temp;
//		cout<<temp<<endl;
//		cout<<s<<endl;
	}
	cout<<s<<endl;
	return 0;
}