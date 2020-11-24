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

int tree[4 * 200200][2];
int arr[200200];

void build(int id, int l, int r)
{
	if(l == r)
	{
		tree[id][0] = arr[l];
		tree[id][1] = arr[l];
		return;
	}
	build(2 * id, l, (l + r) / 2);
	build(2 * id + 1, (l + r) / 2 + 1, r);
	tree[id][0] = std::min(tree[2 * id][0], tree[2 * id + 1][0]);
	tree[id][1] = std::max(tree[2 * id][1], tree[2 * id + 1][1]);
}

int query1(int id, int st, int en, int l, int r, int val)
{
	if(st > r || en < l)
	{
		return 1e9;
	}
	int mid = (st + en) / 2;
	if(st >= l && en <= r)
	{
		if(tree[id][0] >= val)
		{
			return st;
		}
		if(st == en)
		{
			return 1e8;
		}
	}
	int v1 = query1(2 * id + 1, mid + 1, en, l, r, val);
	if(v1 == mid + 1 || v1 == 1e9)
	{
		int v2 = query1(2 * id, st, mid, l, r, val);
		if(v2 == 1e9)
		{
			return v1;
		}
		if(v2 != 1e8 || v1 == 1e9)
		{
			return v2;
		}
	}
	return v1;
}

int query2(int id, int st, int en, int l, int r, int val)
{
	if(st > r || en < l)
	{
		return 1e9;
	}
	int mid = (st + en) / 2;
	if(st >= l && en <= r)
	{
		if(tree[id][0] >= val)
		{
			return en;
		}
		if(st == en)
		{
			return 1e8;
		}
	}
	int v1 = query2(2 * id, st, mid, l, r, val);
	if(v1 == mid || v1 == 1e9)
	{
		int v2 = query2(2 * id + 1, mid + 1, en, l, r, val);
		if(v2 == 1e9)
		{
			return v1;
		}
		if(v2 != 1e8 || v1 == 1e9)
		{
			return v2;
		}
	}
	return v1;
}

int query3(int id, int st, int en, int l, int r)
{
	if(st > r || en < l)
	{
		return -1;
	}
	if(st >= l && en <= r)
	{
		return tree[id][1];
	}
	int mid = (st + en) / 2;
	return std::max(query3(2 * id, st, mid, l, r),
		query3(2 * id + 1, mid + 1, en, l, r));
}


int main(int argc, char const *argv[])
{
	int t;
	read(t);
	while(t--)
	{
		int n;
		read(n);
		for(int i = 0; i < n; ++i)
		{
			read(arr[i]);
		}
		build(1, 0, n - 1);
		bool got_ans = false;
		for(int i = 1; i < n - 1; ++i)
		{
			int minn = arr[i];
			int span1 = query1(1, 0, n - 1, 0, i - 1, minn);
			int l = span1 > n ? i : span1;
			int span2 = query2(1, 0, n - 1, i + 1, n - 1, minn);
			int r = span2 > n ? i : span2;
			if(l == 0 || (l < i && arr[l] == arr[i]))
				l++;
			if(r == n - 1 || (r > i && arr[r] == arr[i]))
				r--;
			int max1 = query3(1, 0, n - 1, 0, l - 1);
			int max2 = query3(1, 0, n - 1, r + 1, n - 1);
			if(max1 == max2 && max2 == minn)
			{
				print("YES");
				print(l, r + 1 - l, n - 1 - r);
				got_ans = true;
				break;
			}
		}
		if(!got_ans)
		{
			print("NO");
		}
	}
	return 0;
}