#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int cnt[100100];
int ans[100100];

int main()	{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)	{
		cin >> arr[i];
		cnt[arr[i]] = i;
	}
	for(int i = n; i >= 1; i--)	{
		int pos = cnt[i];
		int temp = 0;
		for(int j = pos - i; j >= 1; j -= i)	{
			temp |= ans[j];
		}
		for(int j = pos + i; j <= n; j += i)	{
			temp |= ans[j];
		}
		if(temp == 0)	{
			ans[pos] = 1;
		}
	}
	for(int i = 1; i <= n; i++)	{
		if(ans[i] == 1)	{
			cout << "B";
		}
		else	{
			cout << "A";
		}
	}
	cout << endl;
}