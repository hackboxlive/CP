#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> arr[300300];
multiset<long long> bags;
bool comp(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.second > b.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n, comp);
	long long temp;
	for(int i = 0; i < k; i++)
	{
		cin >> temp;
		bags.insert(temp);
	}
	multiset<long long>::iterator it;
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		it = bags.lower_bound(arr[i].first);
		if(it != bags.end())
		{
			bags.erase(it);
			ans += arr[i].second;
		}
	}
	cout << ans << endl;
	return 0;
}
