#include <bits/stdc++.h>
using namespace std;

int ans[1010];
pair<int,int> arr[1010];

struct node	{
	vector<int> pos;
}store[1010][1010];

int lll[1010], rrr[1010];

int main()	{
	int n;
	cin >> n;
	int cur=n;
	vector<int> temp;
	for(int i=0;i<n;i++)	{
		cin >> lll[i];
	}
	for(int i=0;i<n;i++)	{
		cin >> rrr[i];
	}
	for(int i=0;i<n;i++)	{
		arr[i].first = lll[i];
		arr[i].second = rrr[i];
		store[arr[i].first][arr[i].second].pos.push_back(i);
	}
	if(store[0][0].pos.size() == 0)	{
		cout << "NO\n";
		return 0;
	}
	for(int i=0;i<store[0][0].pos.size();i++)	{
		temp.push_back(store[0][0].pos[i]);
		ans[store[0][0].pos[i]]=cur;
	}
	cur--;
	int ppr=0, qqr=temp.size();
	int check=qqr-ppr;
	while(qqr-ppr < n)	{
		int l=0, r=qqr-ppr;
		int prev=0, next;
		for(int i=ppr;i<qqr;i++)	{
			next=temp[i]-1;
			for(int j=0;j<store[l][r].pos.size();j++)	{
				if(store[l][r].pos[j] < prev || store[l][r].pos[j] > next)	{
					cout << "NO\n";
					return 0;
				}
				else	{
					ans[store[l][r].pos[j]] = cur;
					temp.push_back(store[l][r].pos[j]);
				}
			}
			temp.push_back(temp[i]);
			l++;
			r--;
			prev=next+2;
		}
		next=n-1;
		for(int j=0;j<store[l][r].pos.size();j++)	{
			if(store[l][r].pos[j] < prev || store[l][r].pos[j] > next)	{
				cout << "NO\n";
				return 0;
			}
			else	{
				ans[store[l][r].pos[j]] = cur;
				temp.push_back(store[l][r].pos[j]);
			}
		}
		ppr=qqr;
		qqr=temp.size();
		if(qqr-ppr==check)	{
			cout << "NO\n";
			return 0;
		}
		check=qqr-ppr;
		cur--;
	}
	cout << "YES\n";
	for(int i=0;i<n;i++)	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}