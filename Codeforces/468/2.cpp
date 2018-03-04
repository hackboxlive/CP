#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,a,b;
	cin>>n>>a>>b;
	if(a>b)	{
		swap(a,b);
	}
	vector<int> temp,games;
	for(int i=1;i<=n;i++)	{
		games.push_back(i);
	}
	int round=1;
	while(games.size()>2)	{
		for(int i=0;i<games.size();i+=2)	{
			if(games[i]==a && games[i+1]==b)	{
				cout<<round<<endl;
				return 0;
			}
			else if(games[i]==a || games[i+1]==a)	{
				temp.push_back(a);
			}
			else if(games[i]==b || games[i+1]==b)	{
				temp.push_back(b);
			}
			else	{
				temp.push_back(games[i]);
			}
		}
		games.clear();
		games=temp;
		temp.clear();
		round++;
	}
	cout<<"Final!\n";
	return 0;
}