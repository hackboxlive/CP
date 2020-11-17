#include <iostream>
#include <random>
#include <algorithm>

template<typename T>
void read(T& _val)
{
    std::cin >> _val;
}

template<typename T, typename... Args>
void read(T& _val, Args&... _args)
{
    std::cin >> _val;
    read(_args...);
}

template<typename T>
void print(const T& _val)
{
    std::cout << _val << std::endl;
}

template<typename T, typename... Args>
void print(const T& _val, const Args&... _args)
{
    std::cout << _val << " ";
    print(_args...);
}

template<typename T>
void permuteVector(std::vector<T>& v, int _seed = 10)
{
	shuffle(v.begin(), v.end(), std::default_random_engine(_seed));
}

/*
*   Main starts below
*/


int mat[111][111];

struct move
{
	int x[3];
	int y[3];
};
std::vector<move> ans;

void make_move_except(int st, int en, int x, int y)
{
	int xx[4] = {st, st, st + 1, st + 1};
	int yy[4] = {en, en + 1, en, en + 1};
	for(int i = 0; i < 4; ++i)
	{
		if(xx[i] == x && yy[i] == y)
		{
			move mv;
			int dd = 0;
			for(int j = 0; j < 4; ++j)
			{
				if(j != i)
				{
					mv.x[dd] = xx[j];
					mv.y[dd++] = yy[j];
					if(mat[xx[j]][yy[j]] == 1)
					{
						mat[xx[j]][yy[j]] = 0;
					}
					else
					{
						mat[xx[j]][yy[j]] = 1;
					}
				}
			}
			ans.push_back(mv);
		}
	}
}

void get_last_moves(int n, int m)
{
	int r1 = n - 2;
	int r2 = n - 1;
	int c1 = m - 2;
	int c2 = m - 1;
	int ones = 0;
	for(int i = r1; i <= r2; ++i)
	{
		for(int j = c1; j <= c2; ++j)
		{
			ones += mat[i][j];
		}
	}
	if(ones == 0)
	{
		return;
	}
	else if(ones == 3)
	{
		move mv; int dd = 0;
		for(int i = r1; i <= r2; ++i)
		{
			for(int j = c1; j <= c2; ++j)
			{
				if(mat[i][j] == 0)
				{
					make_move_except(r1, c1, i, j);
					return;
				}
			}
		}
	}
	else if(ones == 2)
	{
		for(int i = r1; i <= r2; ++i)
		{
			for(int j = c1; j <= c2; ++j)
			{
				if(mat[i][j] == 1)
				{
					make_move_except(r1, c1, i, j);
					get_last_moves(n, m);
					return;
				}
			}
		}
	}
	else
	{
		for(int i = r1; i <= r2; ++i)
		{
			for(int j = c1; j <= c2; ++j)
			{
				if(mat[i][j] == 1)
				{
					if(i == r1 && j == c1)
					{
						make_move_except(r1, c1, r1, c2);
						get_last_moves(n, m);
						return;
					}
					else
					{
						make_move_except(r1, c1, r1, c1);
						get_last_moves(n, m);
						return;
					}
				}
			}
		}
	}
}

int main()
{
	int t;
	read(t);
	std::string s;
	while(t--)
	{
		int n, m;
		read(n, m);
		for(int i = 0; i < n; ++i)
		{
			read(s);
			for(int j = 0; j < m; ++j)
			{
				mat[i][j] = s[j] - '0';
				//print(mat[i][j]);
			}
		}
		ans.clear();
		//print("here");
		for(int i = 0; i < n - 2; ++i)
		{
			for(int j = 0; j < m - 1; ++j)
			{
				if(mat[i][j] == 1)
				{
					//do this transition
					//1.
					//xx
					make_move_except(i, j, i, j + 1);
				}
			}
			if(mat[i][m - 1] == 1)
			{
				//do this transition
				//.1
				//xx
				make_move_except(i, m - 2, i, m - 2);
			}
		}
		for(int i = 0; i < m - 2; ++i)
		{
			if(mat[n - 2][i] == 1 && mat[n - 1][i] == 1)
			{
				//do this transition
				//1x
				//1x
				make_move_except(n - 2, i, n - 2, i + 1);
			}
			if(mat[n - 2][i] == 0 && mat[n - 1][i] == 1)
			{
				//do this transition
				//.x
				//1x
				make_move_except(n - 2, i, n - 2, i);
			}
			if(mat[n - 2][i] == 1 && mat[n - 1][i] == 0)
			{
				//do this transition
				//1x
				//.x
				make_move_except(n - 2, i, n - 1, i);
			}
		}
		get_last_moves(n, m);
		print(ans.size());
		for(move& mv : ans)
		{
			print(mv.x[0] + 1, mv.y[0] + 1, mv.x[1] + 1, mv.y[1] + 1, mv.x[2] + 1, mv.y[2] + 1);
		}
	}
}