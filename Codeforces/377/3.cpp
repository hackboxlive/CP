#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long int a,b,c;
	cin>>a>>b>>c;
	long long int minn=min(a,min(b,c));
	long long int arr[3];
	arr[0]=a;
	arr[1]=b;
	arr[2]=c;
	a=a-minn;
	b=b-minn;
	c=c-minn;
	sort(arr,arr+3);
	if(arr[2]-arr[0]==0)	{
		cout<<"0\n";
		return 0;
	}
	if(arr[1]==arr[2])	{
		cout<<arr[1]-arr[0]-1<<endl;
		return 0;
	}
	else	{
		cout<<arr[2]-arr[1]+arr[2]-arr[0]-2<<endl;
		return 0;
	}
	return 0;
}