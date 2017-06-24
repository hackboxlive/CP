#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long int n;
	cin>>n;
	n--;
	long long int val = log2(n);
	val++;
	cout<<val;
	return 0;
}