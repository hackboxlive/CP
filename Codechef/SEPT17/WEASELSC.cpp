#include <bits/stdc++.h>
using namespace std;
int arr[100100];
void maxrect(int n)	{
	stack<int> s;
	long long maxx=0;
	long long cur,curarea;
	int i=0;
	while(i<n)	{
		if(s.empty() || arr[s.top()]<=arr[i])	{
			s.push(i++);
		}
		else	{
			cur=s.top();
			s.pop();
			curarea=arr[cur];
			curarea*=(s.empty()?i:i-s.top()-1);
			if(maxx<curarea)	{
				maxx=curarea;
			}
		}
	}
	while(!s.empty())	{
		cur=s.top();
		s.pop();
		curarea=arr[cur];
		curarea*=(s.empty()?i:i-s.top()-1);
		maxx=max(maxx,curarea);
	}
	cout<<maxx<<endl;
}
int main()	{
	int t,n,k;
	cin>>t;
	while(t--)	{
		cin>>n>>k;
		long long minn=1e9;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
		}
		maxrect(n);
	}
	return 0;
}