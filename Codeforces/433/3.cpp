#include <bits/stdc++.h>
using namespace std;
struct node	{
	long long val;
	int pos;
	int ans;
}arr[300300];
struct comp	{
	bool operator()(const node &a,const node &b)	{
		return a.val<b.val;
	}
};
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)	{
		cin>>arr[i].val;
		arr[i].pos=i;
	}
	node temp;
	priority_queue<node,vector<node>,comp> pq;
	for(int i=0;i<k;i++)	{
		pq.push(arr[i]);
	}
	int cnt=k+1;
	for(int i=k;i<n;i++)	{
		pq.push(arr[i]);
		temp=pq.top();
		pq.pop();
		arr[temp.pos].ans=cnt;
		cnt++;
	}
	while(!pq.empty())	{
		temp=pq.top();
		pq.pop();
		arr[temp.pos].ans=cnt;
		cnt++;
	}
	long long value=0;
	for(int i=0;i<n;i++)	{
		value+=(long long)(arr[i].ans-i-1)*arr[i].val;
	}
	cout<<value<<endl;
	for(int i=0;i<n;i++)	{
		cout<<arr[i].ans<<" ";
	}
	cout<<endl;
	return 0;
}