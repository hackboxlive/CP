#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > rows;
vector<pair<int,int> > columns;
bool comp(const pair<int,int> &a,const pair<int,int> &b)	{
	if(a.first==b.first)	{
		return a.second<b.second;
	}
	return a.first<b.first;
}
int ctr=0;
bool flag=true;
void checkrow(int x,int y)	{
	int i=0;
	int st=x;
	int nst;
	while(st<=y && i<rows.size())	{
		nst=rows[i].second;
		while(rows[i].first<=st && i<rows.size())	{
			if(nst<rows[i].second)	{
				nst=rows[i].second;
			}
			i++;
		}
		if(nst<st)	{
			flag=false;
			return;
		}
		st=nst+1;
		ctr++;
	}
	if(st<=y)	{
		flag=false;
	}
}
void checkcol(int x,int y)	{
	int i=0;
	int st=x;
	int nst;
	while(st<=y && i<columns.size())	{
		nst=columns[i].second;
		while(columns[i].first<=st && i<columns.size())	{
			if(nst<columns[i].second)	{
				nst=columns[i].second;
			}
			i++;
		}
		if(nst<st)	{
			flag=false;
			return;
		}
		st=nst+1;
		ctr++;
	}
	if(st<=y)	{
		flag=false;
	}
}
int main()	{
	int t;
	int n,k,m,a,b,c,d,p1,p2,p3,p4;
	cin>>t;
	while(t--)	{
		rows.clear();
		columns.clear();
		cin>>n>>k>>m;
		p1=(n-k)/2+1;
		p2=(n-k)/2+1;
		p3=p1+k-1;
		p4=p2+k-1;
		for(int i=0;i<m;i++)	{
			cin>>a>>b>>c>>d;
			if(d>=p2 && b<=p4)	{
				b=max(p2,b);
				d=min(p4,d);
				rows.push_back(make_pair(b,d));
			}
			if(c>=p1 && a<=p3)	{
				a=max(p1,a);
				c=min(p3,c);
				columns.push_back(make_pair(a,c));
			}
		}
		sort(rows.begin(),rows.end(),comp);
		sort(columns.begin(),columns.end(),comp);
		flag=true;
		ctr=0;
		checkrow(p1,p3);
		checkcol(p1,p3);
		if(flag==false)	{
			cout<<"-1\n";
		}
		else	{
			cout<<ctr<<endl;
		}
	}
	return 0;
}