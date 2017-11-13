//accepted code
#include <bits/stdc++.h>
using namespace std;
const int size = 1000001;
typedef long long int lli;

lli a[size], b[size * 10];
lli n, p ,q, x, d;
lli buckp[1001];
lli rangep[1001][1001];
lli pre[1001][1001], suf[1001][1001];
lli bsize, nbuck;
lli segp[4*size];

void buildsegtree(int s, int e, int nodenum)
{
	segp[nodenum] = 0;
	if(s == e)
	{
		segp[nodenum] = a[s - 1];
	}
	else
	{
		int mid = (s + e) / 2;
		buildsegtree(s, mid, nodenum*2);
		buildsegtree(mid + 1, e, nodenum*2 + 1);
		segp[nodenum] = (segp[nodenum * 2] * segp[nodenum*2 + 1]) % p;
	}
}

lli query(int l, int r, int s, int e, int node_num)
{
    if(s>r || e<l) return 1;
    else if(s>=l && e<=r) return segp[node_num];
    else 
    {
        int m = (s+e)/2;
        return (query(l,r,s,m,node_num*2) * query(l,r,m+1,e,node_num*2+1)) % p;
    }
}

void compute()
{
	for(int i = 0; i <= nbuck; i++)
	{
		buckp[i] = 1;
		int ind;
		for(int j = 0; j < bsize; j++)
		{
			ind = i * bsize + j;
			if(ind >= n) break;

			buckp[i] *= a[ind];
			if(buckp[i] >= p) buckp[i] %= p;
		}
		if(ind >= n) break;
	}
}

void computerangep()
{
	int start = 0, end = nbuck;
	for(int i = 0; i <= end; i++)
	{
		for(int j = i; j <= end; j++)
		{
			if(i == j) rangep[i][j] = buckp[i];
			else
			{
				rangep[i][j] = (rangep[i][j - 1] * buckp[j]);
				if(rangep[i][j] >= p) rangep[i][j] %= p;
			}
		}
	}
}

void computepre()
{
	for(int i = 0; i <= nbuck; i++)
	{
		int ind;
		for(int j = 0; j < bsize; j++)
		{
			ind = i * bsize + j;
			if(ind >= n) break;
			if(j == 0) pre[i][j] = a[ind];
			else pre[i][j] = (pre[i][j - 1] * a[ind]);
			if(pre[i][j] >= p) pre[i][j] %= p;
		}
		if(ind >= n) break;
	}
}

void computesuf()
{
	for(int i = 0; i <= nbuck; i++)
	{
		int ind;
		for(int j = bsize - 1; j >= 0; j--)
		{
			ind = i * bsize + j;
			if(ind >= n) continue;
			
			if(j == (bsize - 1) || ind == (n - 1)) 
				suf[i][j] = a[ind];
			else suf[i][j] = (suf[i][j + 1] * a[ind]);
			if(suf[i][j] >= p) suf[i][j] %= p;
		}
	}
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld\n",&n, &p, &q);
		for(int i = 0; i < n; i++)
		{
			scanf("%lld",&a[i]);
			a[i] %= p;
		}
		lli bval = q/64 + 2;
		for(int i = 0; i < bval; i++)
		{
			scanf("%lld",&b[i]);
		}
		bsize = sqrt(n);
		nbuck = (n - 1) / bsize;
		buildsegtree(1, n, 1);
		compute(); computerangep();
		computepre(); computesuf();
		x = 0;
		lli l, r;
		for(int i = 0; i < q; i++)
		{
			if(i % 64 == 0)
			{
				l = (b[(i/64)] + x) % n;
				r = (b[(i / 64 + 1)] + x) % n;
			}
			else 
			{
				l = (l + x) % n; r = (r + x) % n;
			}
			if(l > r) swap(l, r);
			lli ans = 1;
			int lbuck = l / bsize, rbuck = r / bsize;
			int lpos = l % bsize, rpos = r % bsize;
			//cout << l << " " << r << endl;
			if(lbuck == rbuck)
			{
				ans = query(l+1, r+1, 1, n, 1);
			}
			else
			{
				if((rbuck - lbuck) > 1)
					ans = rangep[lbuck + 1][rbuck - 1];
				ans = (ans * suf[lbuck][lpos]) % p;
				ans = (ans * pre[rbuck][rpos]) % p;
			}
			//cout << "ans = " << ans << endl;
			x = (ans + 1) % p;
		}
		printf("%lld\n",x);
	}

	return 0;
}