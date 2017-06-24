#include <bits/stdc++.h>
using namespace std;
int arr[200100];
//int flag[200100];
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
//		flag[i]=0;
	}
	int carry=0;
	int flag=0;
	for(int i=0;i<n-1;i++)	{
		if(arr[i]==0 && carry==1)	{
			flag=1;
		}
		if((carry+arr[i])%2==0)	{
			arr[i]=0;
			carry=0;
		}
		else	{
			carry=1;
			arr[i]=0;
		}
	}
	if(flag==1)	{
		cout<<"NO";
		return 0;
	}
	if((arr[n-1]+carry)%2==0)	{
		cout<<"YES";
	}
	else	{
		cout<<"NO";
	}
	return 0;
}