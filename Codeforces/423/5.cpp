#include <bits/stdc++.h>
using namespace std;
int tree[11][11][5][600600];
int arr[100100];
void build(int e,int v,int id,int l,int r)	{
	if(l==r)	{
		if()
		return;
	}
}
int main()	{
	string s;
	for(int i=0;i<s.length();i++)	{
		if(s[i]=='A')	{
			arr[i]=1;
		}
		if(s[i]=='T')	{
			arr[i]=2;
		}
		if(s[i]=='G')	{
			arr[i]=3;
		}
		if(s[i]=='C')	{
			arr[i]=4;
		}
	}
	for(int i=1;i<=10;i++)	{
		for(int j=1;j<=4;j++)	{
			build(i,j,1,0,s.length()-1);
		}
	}
	cin>>s;
	int q,ch,l,r,x,c,e;
	cin>>q;
	while(q--)	{
		cin>>ch;
		if(ch==1)	{
			//update
		}
	}
	return 0;
}