#include <bits/stdc++.h>
using namespace std;
int arr[10100];
int contain[1001000];

int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	while(t--)	{
		cin >> n;
		for(int i = 0; i < n; i++)	{
			cin >> contain[i];
			arr[contain[i]]++;
		}
		sort(contain, contain+n);
		bool flag = false;
		for(int i = 0; i < n; i++)	{
			if(arr[contain[i]] >= 4)	{
				cout << contain[i] << " " << contain[i] << " " << contain[i] << " " << contain[i] << endl;
				flag = true;
				break;
			}
		}
		if(!flag)	{
			double max_diff = 1e9;
			double temp;
			int rr=-1;
			int cx, cy;
			int prev = -1;
			for(int i = 0; i < n; i++)	{
				if(arr[contain[i]] >= 2)	{
					if(prev != contain[i] && prev != -1)	{
						temp = (double)contain[i]/prev + (double)prev/contain[i];
						if(max_diff  >= temp)	{
							cx = contain[i];
							cy = prev;
							max_diff = temp;
						}
					}
					prev = contain[i];
				}
			}
			cout << cx << " " << cx << " " << cy << " " << cy << endl;
		}
		for(int i = 0; i < n; i++)	{
			arr[contain[i]] = 0;
		}
	}
	return 0;
}