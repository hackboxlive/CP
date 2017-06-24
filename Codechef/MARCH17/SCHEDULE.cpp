#include <bits/stdc++.h>
using namespace std;
string s;
char arr[1001000];
char arr2[1001000];
int n,k;
void solve()	{
	int lo = 1;
	int hi = -1;
	int ctr = 1;
	for(int i = 1 ; i < n ; i++)	{
		if(s[i] != s[i-1])	{
			if(ctr > hi)	{
				hi = ctr;
			}
			ctr = 1;
		}
		else	{
			ctr++;
		}
	}
	if(ctr > hi)	{
		hi = ctr;
	}
	int prevlo=-1,prevhi=-1;
	int mid,op,opflip,ctrflip;
	while(lo < hi)	{
		mid = (lo + hi) / 2;
		if(mid > 1)	{
			ctr = 1;
			op = 0;
			arr[0] = s[0];
			for(int  i = 1 ; i < n ; i++)	{
				arr[i] = s[i];
				if(arr[i] != arr[i-1])	{
					op += ctr / (mid + 1);
					ctr = 1;
				}
				else	{
					ctr++;
				}
			}
			op += ctr / (mid + 1);
		}
		else	{
			op = opflip = 0;
			for(int i = 0 ; i < n ; i++)	{
				if(i&1 && s[i] == '0')	{
					op++;
				}
				if(i&1 && s[i] == '1')	{
					opflip++;
				}
				if(!(i&1) && s[i] == '1')	{
					op++;
				}
				if(!(i&1) && s[i] == '0')	{
					opflip++;
				}
			}
			op = min(op,opflip);
		}
		if(op > k)	{
			lo = mid + 1;
		}
		else	{
			hi = mid;
		}
	}
	printf("%d\n",lo);
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		cin>>n>>k;
		cin>>s;
		solve();
	}
	return 0;
}