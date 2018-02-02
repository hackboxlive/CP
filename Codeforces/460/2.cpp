#include <bits/stdc++.h>
using namespace std;
int get_sum(int n)	{
	if(n==0)	{
		return 0;
	}
	return n%10 + get_sum(n/10);
}
int main()	{
	vector<int> perfect;
	perfect.push_back(0);
	for(int i=19,sz=1;sz<=10000;i++)	{
		if(get_sum(i)==10)	{
			perfect.push_back(i);
			sz++;
		}
	}
	int k;
	cin>>k;
	cout<<perfect[k]<<endl;
	return 0;
}