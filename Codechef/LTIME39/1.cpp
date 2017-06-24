#include <bits/stdc++.h>
using namespace std;
int main()	{
	string s;
	string w;
	int n;
	cin>>s;
	int arr[26];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<s.length();i++)	{
		arr[(s[i]-97)]=1;
	}
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>w;
		int flag=0;
		for(int j=0;j<w.length();j++)	{
//			cout<<w[j]-97<<" ";
			if(arr[(w[j]-97)]==0)	{
				flag=1;
				break;
			}
		}
		if(flag==1)	{
			cout<<"No\n";
		}
		else	{
			cout<<"Yes\n";
		}
	}
	return 0;
}