//accepted
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct cof
{
	lli a0, a1, a2,a3;
};
lli l = 1, r = 100000, mina0;
lli minval[100002], ansid[100002];
lli big = 2 * 1e18;
int n, q;
vector<cof> v;

void print(vector<cof> v)
{
	cout << "vector \n";
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i].a0 << " " << v[i].a1 << endl;
	}
}

lli compute(int id, lli x)
{
	lli ans = v[id].a0 + v[id].a1 * x;
	ans = ans + v[id].a2 * (x * x) + v[id].a3 * (x * x * x);
	return ans;
}

void binarySearch(lli l, lli r)
{
	if(l <= r)
	{
		int minid = -1, minid2 = -1, midid = -1;
		lli mini = big, mini2 = mini, midmini = mini;
		lli mid = (l + r) / 2;
		for(int i = 0; i < v.size(); i++)
		{
			lli val = compute(i, l);
			lli val2 = compute(i, r);
			lli midval = compute(i, mid);
			if(val < mini) mini = val, minid = i;
			if(val2 < mini2) mini2 = val2, minid2 = i;
			if(midval < midmini) midmini = midval, midid = i;
		}
		if(minid == minid2)
		{
			for(int i = l; i <= r; i++)
			{
				ansid[i] = minid;
			}
		}
		else
		{
			//ansid[mid] = midid;
			binarySearch(l, mid);
			binarySearch(mid + 1, r);
		}
	}
}

void solve()
{
	l = 1001; r = 100000;
	binarySearch(l, r);
	for(lli i = 1; i <= r; i++)
	{
		minval[i] = compute(ansid[i], i);
	}
}

void pre()
{
	for(lli i = 1; i <= 1000; i++)
	{
		lli tempid = -1, tempmin = big;
		for(int j = 0; j < v.size(); j++)
		{
			lli val = compute(j, i);
			if(val < tempmin) tempmin = val, tempid = j;
		}	
		ansid[i] = tempid;
	}
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{

		scanf("%d",&n);
		mina0 = big;
		v.clear();
		for(int i = 0; i < n; i++)
		{
			struct cof temp;
			scanf("%lld%lld%lld%lld",&temp.a0,&temp.a1,&temp.a2,&temp.a3);
			v.push_back(temp);
			if(temp.a0 < mina0) mina0 = temp.a0;
		}
		minval[0] = mina0;
		scanf("%d",&q);
		pre();
		solve();
		//for(int i = 0; i <= r; i++)
		{
		//	cout << i << " " << minval[i] << endl;
		}
		//q = 0;
		while(q--)
		{
			int x; scanf("%d",&x);
			printf("%lld\n", minval[x]);
		}
	}
	return 0;
}