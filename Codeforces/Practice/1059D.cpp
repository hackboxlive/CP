#include <bits/stdc++.h>
using namespace std;

struct node	{
	int x, y;
}point[100100];

int main()	{
	int n;
	cin >> n;
	bool pos = false;
	bool neg = false;
	for(int i = 0; i < n; i++)	{
		cin >> point[i].x >> point[i].y;
		if(point[i].y > 0)	{
			pos = true;
		}
		else	{
			neg = true;
			point[i].y *= -1;
		}
	}
	if(pos && neg)	{
		cout << "-1\n";
		return 0;
	}
	double lo = 0;
	double hi = 1e15;
	double mid;
	double x1, x2;
	int ctr = 0;
	while(hi - lo >= 1e-8 && ctr < 200)	{
		mid = (lo + hi)/2.0;
		x1 = -1e16, x2 = 1e16;
		bool temp_ans = true;
		//cout << setprecision(13) << std::fixed << mid << endl;
		for(int i = 0; i < n; i++)	{
			double chh = 2 * mid - point[i].y;
			chh *= point[i].y;
			if(chh < 0)	{
				temp_ans = false;
				break;
			}
			double v2 = (double)sqrt(chh);
			double v1 = v2 * -1;
			v1 += point[i].x;
			v2 += point[i].x;
			if(v1 > x2 || v2 < x1)	{
				temp_ans = false;
				break;
			}
			x1 = max(x1, v1);
			x2 = min(x2, v2);
		}
		if(temp_ans)	{
			hi = mid;
			//cout << "True\n";
		}
		else	{
			lo = mid + 1e-8;
			//cout << "False\n";
		}
		ctr++;
	}
	if(lo != 1e16)	{
		cout << setprecision(13) << std::fixed << lo << endl;
	}
	else	{
		cout << "-1" << endl;
	}
	return 0;
}