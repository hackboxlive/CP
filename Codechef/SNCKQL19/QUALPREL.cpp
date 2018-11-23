#include <bits/stdc++.h>
using namespace std;

int main()	{
	int t;
	cin >> t;
	while(t--)	{
		int n, k;
		cin >> n >> k;
		vector<int> arr;
		int temp;
		for(int i = 0; i < n; i++)	{
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());
		if(n <= k)	cout << n << endl;
		else	{
			int index = n - k;
			for(int i = n - k - 1; i >= 0; i--)	{
				if(arr[i] != arr[n - k])	{
					break;
				}
				index--;
			}
			cout << n - index << endl;
		}
	}
	return 0;
}
