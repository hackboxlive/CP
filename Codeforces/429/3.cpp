#include <bits/stdc++.h>
using namespace std;
int a[200200];
int b[200200];
struct node	{
	int dv;
	int id;
	int val;
}arr[200200];
bool comp1(const int &p1,const int &p2)	{
	return p1>p2;
}
bool comp2(const node &p1,const node &p2)	{
	return p1.dv<p2.dv;
}
bool comp3(const node &p1,const node &p2)	{
	return p1.id<p2.id;
}
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)	{
		cin>>b[i];
		arr[i].dv=b[i];
		arr[i].id=i;
	}
	sort(a,a+n,comp1);
	sort(arr,arr+n,comp2);
	for(int i=0;i<n;i++)	{
		arr[i].val=a[i];
	}
	sort(arr,arr+n,comp3);
	for(int i=0;i<n;i++)	{
		cout<<arr[i].val<<" ";
	}
	cout<<endl;
	return 0;
}