#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[10010];
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
 
    return r;
}
 
int LongestIncreasingSubsequenceLength(std::vector<int> &v) {
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }
    return length;
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>arr[i].second;
		}
		for(int i=0;i<n;i++)	{
			cin>>arr[i].first;
		}
		sort(arr,arr+n);
		vector<int> v;
		for(int i=0;i<n;i++)	{
			v.push_back(arr[i].second);
		}
		cout<<LongestIncreasingSubsequenceLength(v)<<endl;
	}
	return 0;
}