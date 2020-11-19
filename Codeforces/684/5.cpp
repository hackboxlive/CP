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

long long tree[800800];

void update(int id, int st, int en, int pos, long long val)
{
	if(st == pos && en == pos)
	{
		tree[id] = std::max(val, tree[id]);
		return;
	}
	if(st > pos || en < pos)
	{
		return;
	}
	update(2 * id, st, (st + en) / 2, pos, val);
	update(2 * id + 1, (st + en) / 2 + 1, en, pos, val);
	tree[id] = tree[2 * id] + tree[2 * id + 1];
}

std::pair<int, long long> query(int id, int st, int en, int l, int r, long long val)
{
	if(st > r || en < l || val == 0)
	{
		//print("zero", id, st, en, l, r, val, tree[id]);
		return std::make_pair<int, long long>(0, 0);
	}
	if(st == en && tree[id] > val)
	{
		//print("zero", id, st, en, l, r, val, tree[id]);
		return std::make_pair<int, long long>(0, 0);
	}
	if(st >= l && en <= r && tree[id] <= val)
	{
		//print("returning", id, st, en, l, r, val, tree[id]);
		return std::make_pair<int, long long>(en - st + 1, (long long)tree[id]);
	}
	//print("going", id, st, en, l, r, val, tree[id]);
	std::pair<int, long long> left_ans = query(2 * id, st, (st + en) / 2, l, r, val);
	//print("left: ", id, left_ans.first, left_ans.second);
	std::pair<int, long long> right_ans = query(2 * id + 1, (st + en) / 2 + 1, en, l, r, val - left_ans.second);
	//print("right: ", id, right_ans.first, right_ans.second);
	return std::make_pair<int, long long>(left_ans.first + right_ans.first, left_ans.second + right_ans.second);
}

int main()
{
	int n, q;
	read(n, q);
	long long x;
	for(int i = 0; i < n; ++i)
	{
		read(x);
		update(1, 0, n - 1, i, x);
	}
	int type, pos;
	std::pair<int, long long> ans;
	for(int i = 0; i < q; ++i)
	{
		read(type, pos);
		read(x);
		if(type == 1)
		{
			update(1, 0, n - 1, pos - 1, x);
		}
		else
		{
			ans = query(1, 0, n - 1, pos - 1, n - 1, x);
			print(ans.first);
		}
	}
}