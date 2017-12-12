#include <bits/stdc++.h>
using namespace std;
string arr[5050];
int main()	{
	int k,n;
	cin>>k>>n;
	for(int i=0;i<k;i++)	{
		cin>>arr[i];
	}
	if(k==1)	{
		swap(arr[0][0],arr[0][1]);
		cout<<arr[0]<<endl;
		return 0;
	}
	vector<int> diff;
	for(int i=0;i<n;i++)	{
		if(arr[0][i]!=arr[1][i])	{
			diff.push_back(i);
		}
	}
	if(diff.size()==0)	{
		cout<<arr[0]<<endl;
		return 0;
	}
	int p,q;
	vector<string> ans;
	if(diff.size()==3)	{
		p=diff[0];
		q=diff[1];
		swap(arr[0][p],arr[0][q]);
		ans.push_back(arr[0]);
		swap(arr[0][p],arr[0][q]);
		p=diff[0];
		q=diff[2];
		swap(arr[0][p],arr[0][q]);
		ans.push_back(arr[0]);
		swap(arr[0][p],arr[0][q]);
		p=diff[1];
		q=diff[2];
		swap(arr[0][p],arr[0][q]);
		ans.push_back(arr[0]);
		swap(arr[0][p],arr[0][q]);
	}
	else if(diff.size()==4)	{
		p=diff[0];
		q=diff[1];
		swap(arr[0][p],arr[0][q]);
		ans.push_back(arr[0]);
		swap(arr[0][p],arr[0][q]);
		p=diff[0];
		q=diff[2];
		swap(arr[0][p],arr[0][q]);
		ans.push_back(arr[0]);
		swap(arr[0][p],arr[0][q]);
		p=diff[0];
		q=diff[3];
		swap(arr[0][p],arr[0][q]);
		ans.push_back(arr[0]);
		swap(arr[0][p],arr[0][q]);
		p=diff[1];
		q=diff[2];
		swap(arr[0][p],arr[0][q]);
		ans.push_back(arr[0]);
		swap(arr[0][p],arr[0][q]);
		p=diff[1];
		q=diff[3];
		swap(arr[0][p],arr[0][q]);
		ans.push_back(arr[0]);
		swap(arr[0][p],arr[0][q]);
		p=diff[2];
		q=diff[3];
		swap(arr[0][p],arr[0][q]);
		ans.push_back(arr[0]);
		swap(arr[0][p],arr[0][q]);
	}
	return 0;
}