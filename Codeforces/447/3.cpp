#include <bits/stdc++.h>
using namespace std;
int arr[1010];
int freq[1000100];
vector<int> v;
int main()	{
	int m;
	cin>>m;
	for(int i=0;i<m;i++)	{
		cin>>arr[i];
	}
	int pp=arr[0];
	for(int i=0;i<m;i++)	{
		pp=__gcd(pp,arr[i]);
	}
	if(pp!=arr[0])	{
		cout<<"-1\n";
		return 0;
	}
	v.push_back(arr[m-1]);
	for(int i=m-2;i>=0;i--)	{
		int g=arr[i];
		int ff=0;
		for(int j=v.size()-1;j>=0;j--)	{
			g=__gcd(g,v[j]);
			if(freq[arr[i]]==1)	{
				ff=1;
				break;
			}
			freq[g]=1;
		}
		if(ff==0)	{
			v.push_back(arr[i]);
		}
	}
		cout<<(int)v.size()<<endl;
		for(int i=v.size()-1;i>=0;i--)	{
			cout<<v[i]<<" ";
		}
		cout<<endl;
	return 0;
}