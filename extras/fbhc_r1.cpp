#include <bits/stdc++.h>
using namespace std;

const long long MODD = 1e9 + 7;
char mat[5][1010];
struct node{
	long long one;
	long long two;
	long long three;
	long long four;
}dp[5][1010];

int main()	{
	for(int i = 0; i < 1010; i++)	{
		mat[0][i] = '#';
		mat[4][i] = '#';
	}
	dp[1][0].two = 1;
	dp[1][0].one = dp[1][0].three = dp[1][0].four = 0;

	int t, tt = 1;
	string s;
	cin >> t;
	while(t--)	{
		int n;
		cin >> n;
		for(int i = 1; i <= 3; i++)	{
			cin >> s;
			for(int j = 1; j <= n; j++)	{
				mat[i][j] = s[j - 1];
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++)	{
			if(mat[2][i] == '#')	{
				ans = -1;
			}
		}
		cout << "Case #" << tt << ": ";
		tt++;
		if(ans == -1)	{
			cout << "0\n";
		}
		else	{
			for(int i = 1; i <= n; i++)	{
				if(i%2 == 1)	{
					if(mat[1][i] == '#')	{
						dp[1][i].one = dp[1][i].two = dp[1][i].three = dp[1][i].four = 0;
					}
					else	{
						dp[1][i].three = dp[1][i - 1].two % MODD;
						dp[1][i].one = dp[1][i].two = dp[1][i].four = 0;
					}
					if(mat[3][i] == '#')	{
						dp[3][i].one = dp[3][i].two = dp[3][i].three = dp[3][i].four = 0;
					}
					else	{
						dp[3][i].four = dp[3][i - 1].one % MODD;
						dp[3][i].one = dp[3][i].two = dp[3][i].three = 0;
					}
					if(mat[2][i] == '#')	{
						dp[2][i].one = dp[2][i].two = dp[2][i].three = dp[2][i].four = 0;
					}
					else	{
						dp[2][i].one = dp[1][i].three % MODD;
						dp[2][i].two = dp[3][i].four % MODD;
						dp[2][i].three = dp[2][i].four = 0;
					}
				}
				else	{
					if(mat[2][i] == '#')	{
						dp[2][i].one = dp[2][i].two = dp[2][i].three = dp[2][i].four = 0;
					}
					else	{
						dp[2][i].three = dp[2][i - 1].one + dp[2][i - 1].two;
						dp[2][i].three %= MODD;
						dp[2][i].four = dp[2][i].three;
						dp[2][i].one = dp[2][i].two = 0;
					}
					if(mat[1][i] == '#')	{
						dp[1][i].one = dp[1][i].two = dp[1][i].three = dp[1][i].four = 0;
					}
					else	{
						dp[1][i].two = dp[2][i].four % MODD;
						dp[1][i].one = dp[1][i].four = dp[1][i].three = 0;
					}
					if(mat[3][i] == '#')	{
						dp[3][i].one = dp[3][i].two = dp[3][i].three = dp[3][i].four = 0;
					}
					else	{
						dp[3][i].one = dp[2][i].three % MODD;
						dp[3][i].two = dp[3][i].three = dp[3][i].four = 0;
					}
				}
			}
			ans = dp[3][n].one;
			cout << ans << endl;
		}
	}
	return 0;
}