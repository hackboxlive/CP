#include <bits/stdc++.h>
using namespace std;
struct node	{
	int a,b,id;
}arr[100100];
// struct comp	{
// 	bool operator()(const node &p1,const node &p2)	{
// 		return p1.a+p1.b<p2.a+p2.b;
// 	}
// };
bool comp(const node &p1,const node &p2)	{
	return p1.a+p1.b<p2.a+p2.b;
}
int main()	{
	int n,d;
	cin>>n>>d;
	int lo,hi;
	cin>>lo>>hi;
	for(int i=0;i<n;i++)	{
		cin>>arr[i].a>>arr[i].b;
		arr[i].a=arr[i].a*lo;
		arr[i].b=arr[i].b*hi;
		arr[i].id=i+1;
	}
	sort(arr,arr+n,comp);
	int cnt=0;
	for(int i=0;i<n;i++)	{
		if(arr[i].a+arr[i].b<=d)	{
			cnt++;
			d=d-arr[i].a-arr[i].b;
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++)	{
		cout<<arr[i].id<<" ";
	}
	cout<<endl;
	return 0;
}