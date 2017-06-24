#include <bits/stdc++.h>
using namespace std;
int main()	{
	int orig[]={0,0,1,1,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1};
	int arr[]={0,0,1,1,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1};
	int len=19;
	int c=0;
	int arr2[len];
	while(c++<60)	{
		for(int i=1;i<len-1;i++)	{
			arr2[i]=(arr[i-1]^arr[i]^arr[i+1]);
		}
		arr2[0]=(arr[len-1]^arr[0]^arr[1]);
		arr2[len-1]=(arr[len-2]^arr[len-1]^arr[0]);
		for(int i=0;i<len;i++)	{
			cout<<arr2[i]<<" ";
			arr[i]=arr2[i];
		}
		cout<<endl;
	}
}