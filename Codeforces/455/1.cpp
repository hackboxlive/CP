#include <bits/stdc++.h>
using namespace std;

int main()	{
	string a,b;
	cin>>a>>b;
	int v=a.length();
	// for(int i=1;i<a.length();i++)	{
	// 	if(a[i]<a[i-1])	{
	// 		v=i+1;
	// 	}
	// 	else	{
	// 		break;
	// 	}
	// }
	// cout<<a.substr(0,v)<<b[0]<<endl;
	vector<string> str;
	for(int i=1;i<=a.length();i++)	{
		for(int j=1;j<=b.length();j++)	{
			str.push_back(a.substr(0,i)+b.substr(0,j));
		}
	}
	sort(str.begin(),str.end());
	cout<<str[0]<<endl;
	return 0;
}