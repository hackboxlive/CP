#include <bits/stdc++.h>
using namespace std;
int arr[25];
int c;
//int ord[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int l1[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int l2[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int l3[]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int l4[]={31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int l5[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
bool find_pattern(int n)	{
	for(int i=0;i<49-n;i++)	{
		bool flag=true;
		for(int j=0;j<n;j++)	{
			if(arr[j]!=l1[i+j])	{
				flag=false;
			}
		}
		if(flag==true)	{
			return true;
		}
	}
	for(int i=0;i<49-n;i++)	{
		bool flag=true;
		for(int j=0;j<n;j++)	{
			if(arr[j]!=l2[i+j])	{
				flag=false;
			}
		}
		if(flag==true)	{
			return true;
		}
	}
	for(int i=0;i<49-n;i++)	{
		bool flag=true;
		for(int j=0;j<n;j++)	{
			if(arr[j]!=l3[i+j])	{
				flag=false;
			}
		}
		if(flag==true)	{
			return true;
		}
	}
	for(int i=0;i<49-n;i++)	{
		bool flag=true;
		for(int j=0;j<n;j++)	{
			if(arr[j]!=l4[i+j])	{
				flag=false;
			}
		}
		if(flag==true)	{
			return true;
		}
	}
	for(int i=0;i<49-n;i++)	{
		bool flag=true;
		for(int j=0;j<n;j++)	{
			if(arr[j]!=l5[i+j])	{
				flag=false;
			}
		}
		if(flag==true)	{
			return true;
		}
	}
	return false;
}
int main()	{
	cout<<INT_MAX<<endl;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	if(find_pattern(n))	{
		cout<<"YES\n";
	}
	else	{
		cout<<"NO\n";
	}
	return 0;
}