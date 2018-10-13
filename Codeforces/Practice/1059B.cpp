#include <bits/stdc++.h>
using namespace std;

int mat[1010][1010];
bool filled[1010][1010];

bool check(int x, int y)	{
	if(mat[x - 1][y - 1] == '.')	{
		return false;
	}
	if(mat[x - 1][y] == '.')	{
		return false;
	}
	if(mat[x - 1][y + 1] == '.')	{
		return false;
	}
	if(mat[x][y - 1] == '.')	{
		return false;
	}
	if(mat[x][y + 1] == '.')	{
		return false;
	}
	if(mat[x + 1][y - 1] == '.')	{
		return false;
	}
	if(mat[x + 1][y] == '.')	{
		return false;
	}
	if(mat[x + 1][y + 1] == '.')	{
		return false;
	}
	return true;
}

void fill_mat(int x, int y)	{
	filled[x - 1][y - 1] = true;
	filled[x - 1][y] = true;
	filled[x - 1][y + 1] = true;
	filled[x][y - 1] = true;
	filled[x][y + 1] = true;
	filled[x + 1][y - 1] = true;
	filled[x + 1][y] = true;
	filled[x + 1][y + 1] = true;
}

int main()	{
	int n, m;
	cin >> n >> m;
	string s;
	for(int i = 0; i < n; i++)	{
		cin >> s;
		for(int j = 0; j < m; j++)	{
			mat[i][j] = s[j];
		}
	}
	for(int i = 1; i < n - 1; i++)	{
		for(int j = 1; j < m - 1; j++)	{
			if(check(i, j))	{
				fill_mat(i, j);
			}
		}
	}
	bool ans = true;
	for(int i = 0; i < n; i++)	{
		for(int j = 0; j < m; j++)	{
			if(mat[i][j] == '#' && !filled[i][j])	{
				cout << "NO\n";
				return 0;
			}
			if(mat[i][j] == '.' && filled[i][j])	{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}
