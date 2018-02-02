#include <bits/stdc++.h>
using namespace std;
int arr[300300];
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	string s;
	cin>>s;
	int l=10000;
	vector<pair<int,int> > v;
	for(int i=0;i<s.length();i++)	{
		if(s[i]=='1')	{
			l=i;
			break;
		}
	}
	for(int i=0;i<s.length();i++)	{
		if(s[i]=='0')	{
			if(i>l)	{
				v.push_back(make_pair(l,i-1));
				l=i+1;
			}
		}
	}
	if(l<s.length())	{
		v.push_back(make_pair(l,s.length()-1));
	}
	for(int i=0;i<v.size();i++)	{
		//cout<<v[i].first<<" "<<v[i].second;
		sort(arr+v[i].first,arr+v[i].second+2);
	}
	for(int i=0;i<n;i++)	{
		//cout<<arr[i]<<endl;
		if(arr[i]!=i+1)	{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}