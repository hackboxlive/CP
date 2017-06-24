#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	int arr[]={11,7,5,3,2};
	cin>>t;
	while(t--)	{
		int a,k,n;
		cin>>a>>k>>n;
		int starting=a/k;
		int cnt=1;
		int flag;
		int val;
		for(int i=1;cnt<=n;i++)	{
			flag=0;
			val=(starting+i)*k;
			for(int j=0;arr[j]>k;j++)	{
				if(val%arr[j]==0)	{
					flag=1;
					break;
				}
			}
			cout<<"For val="<<val<<" flag="<<flag<<endl;
			if(flag==1)	{
				continue;
			}
			cnt++;
		}
		cout<<val<<endl;
	}
	return 0;
}