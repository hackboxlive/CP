#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int arr[26];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++)	{
		arr[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)	{
		if(arr[i]>k)	{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}