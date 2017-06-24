#include <bits/stdc++.h>
using namespace std;
int arr[26];
bool comp(const int &p1,const int &p2)	{
	return p1<p2;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		string s;
		memset(arr,0,sizeof(arr));
		cin>>s;
		int k;
		cin>>k;
		for(int i=0;i<s.length();i++)	{
			arr[s[i]-'a']++;
		}
//		for(int i=0;i<26;i++)	{
//			cout<<(char)(i+97)<<" "<<arr[i]<<endl;
//		}
		int ctr=0;
		for(int i=0;i<26;i++)	{
			ctr=ctr+(arr[i]/k);
			arr[i]=arr[i]%k;
		}
//		for(int i=0;i<26;i++)	{
//			cout<<(char)(i+97)<<" "<<arr[i]<<endl;
//		}
		sort(arr,arr+26,comp);
//		for(int i=0;i<26;i++)	{
//			cout<<(char)(i+97)<<" "<<arr[i]<<endl;
//		}
		int distinct=0;
		for(int i=0;i<26;i++)	{
			if(arr[i])	{
				distinct++;
			}
		}
		int i;
		for(i=0;i<26;i++)	{
			if(arr[i])	{
				break;
			}
		}
		for(;i<26;)	{
			if(k<=distinct)	{
				ctr=ctr+arr[i+k-1];
				i=i+k;
				distinct=distinct-k;
			}
			else	{
				ctr+=(arr[25]>distinct?distinct:arr[25]);
				break;
			}
		}
		cout<<ctr<<endl;
	}
	return 0;
}