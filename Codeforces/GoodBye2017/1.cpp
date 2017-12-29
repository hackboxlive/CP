#include <bits/stdc++.h>
using namespace std;
int arr[500500];
int main()	{
	// int n;
	// cin>>n;
	// for(int i=0;i<n;i++)	{
	// 	cin>>arr[i];
	// }
	string s;
	cin>>s;
	int ans=0;
	char ch[]={'a','e','i','o','u'};
	char chh[]={'1','3','5','7','9'};

	for(int i=0;i<s.length();i++)	{
		if(s[i]>='a' && s[i]<='z')	{
			bool flag=true;
			for(int j=0;j<5;j++)	{
				if(s[i]==ch[j])	{
					flag=false;
					break;
				}
			}
			if(flag==false)	{
				ans++;
			}
		}
		else	{
			bool flag=true;
			for(int j=0;j<5;j++)	{
				if(s[i]==chh[j])	{
					flag=false;
					break;
				}
			}
			if(flag==false)	{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}