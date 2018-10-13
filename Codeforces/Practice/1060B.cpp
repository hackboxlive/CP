#include <bits/stdc++.h>
using namespace std;

long long dig_sum(long long x)	{
	long long ans=0;
	while(x)	{
		ans += x%10;
		x /= 10;
	}
	return ans;
}

long long get_sum(long long x, long long y)	{
	return dig_sum(x) + dig_sum(y);
}
int main()	{
	long long n;
	cin >> n;
	if(n < 10)	{
		cout << n << endl;
		return 0;
	}
	long long temp = n;
	long long first_dig;
	long long val = 0;
	while(temp)	{
		first_dig = temp%10;
		val = val * 10 + 9;
		temp /= 10;
	}
	first_dig--;
	val /= 10;
	while(val)	{
		first_dig *= 10;
		first_dig += 9;
		val /= 10;
	}
	//cout << first_dig << endl;
	cout << get_sum(first_dig, n - first_dig) << endl;
	return 0;
}