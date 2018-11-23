#include <bits/stdc++.h>
using namespace std;

long long a[2020];
long long b[2020];
long long mat[2020][2020];
long long prefix[2020][2020];

int main()	{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)	{
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++)	{
		cin >> b[i];
	}
	long long x;
	cin >> x;
	for(int i = 1; i <= n; i++)	{
		for(int j = 1; j <= m; j++)	{
			mat[i][j] = a[i] * b[j];
		}
	}
	for(int i = 1; i <= n; i++)	{
		for(int j = 1; j <= m; j++)	{
			prefix[i][j] = mat[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}
	
	return 0;
}