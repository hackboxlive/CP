#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n1,n2;
	string s;
	scanf("%d%d",&n1,&n2);
	int arr1[11000];
	int arr2[11000];
	for(int i=0;i<n1;i++)	{
		cin>>s;
		for(int j=0;j<s.length();j++)	{
			arr1[i]=arr1[i]|(1<<(s[j]-'A'));
		}
//		cout<<arr1[i]<<endl;
	}
	for(int i=0;i<n2;i++)	{
		cin>>s;
		for(int j=0;j<s.length();j++)	{
			arr2[i]=arr2[i]|(1<<(s[j]-'A'));
		}
//		cout<<arr2[i]<<endl;
	}
	int ctr=0;
	int ans=67108863;
	for(int i=0;i<n1;i++)	{
		for(int j=0;j<n2;j++)	{
			if((arr1[i]|arr2[j])==ans)	{
				++ctr;
			}
		}
	}
	printf("%d\n",ctr);
	return 0;
}