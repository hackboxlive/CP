#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int getmex()	{
	int mex=(int)arr.size();
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();i++)	{
		if(arr[i]!=i)	{
			mex=i;
			break;
		}
	}
	return mex;
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,x,v;
	cin>>n>>x;
	for(int i=0;i<n;i++)	{
		cin>>v;
		arr.push_back(v);
	}
	int mex=getmex();
	int ctr=0;
	while(mex!=x)	{
//		cout<<mex<<endl;
		if(mex<x)	{
			arr.push_back(mex);
			mex=getmex();
			ctr++;
		}
		else if(mex>x)	{
			arr.erase(arr.begin()+mex-1);
			mex=getmex();
			ctr++;
		}
	}
	cout<<ctr<<endl;
	return 0;
}