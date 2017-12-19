#include <bits/stdc++.h>
using namespace std;
int arr[200100];
long long ss[200100];
vector<int> v;
int par[200100];
int main()	{
	int n;
	cin>>n;
	bool flag=true;
	cin>>arr[0];
	ss[0]=arr[0];
	for(int i=1;i<=n;i++)	{
		cin>>arr[i];
//		cout<<arr[i]<<endl;
		if(arr[i]!=1)	{
			v.push_back(i);
		}
		ss[i]=ss[i-1]+arr[i];
//		cout<<ss[i]<<endl;
	}
	for(int i=1;i<v.size();i++)	{
//		cout<<v[i]<<endl;
		if(v[i]==v[i-1]+1)	{
			flag=false;
		}
	}
	if(flag==true)	{
		cout<<"perfect\n";
		return 0;
	}
	cout<<"ambiguous\n";
	int cur=1;
	par[1]=0;
	for(int i=1;i<=n;i++)	{
		for(int j=ss[i-1]+1;j<=ss[i];j++)	{
//			cout<<j<<endl;
			par[j]=cur;
		}
		cur=ss[i-1]+1;
//		cout<<endl;
	}
	for(int i=1;i<=ss[n];i++)	{
		cout<<par[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)	{
		if(arr[i]!=1 && arr[i-1]!=1)	{
			par[ss[i-1]+2]=ss[i-2]+2;
			break;
		}
	}
	for(int i=1;i<=ss[n];i++)	{
		cout<<par[i]<<" ";
	}
	cout<<endl;
	return 0;
}