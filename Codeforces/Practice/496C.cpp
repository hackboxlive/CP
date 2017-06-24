#include <bits/stdc++.h>
using namespace std;
string words[110];
bool legit[110];
bool checkhistory(int row,int col)	{
	int checkcol=col-1;
	while(checkcol!=-1 && legit[checkcol]==true)	{
		checkcol--;
	}
	if(checkcol==-1)	{
		return false;
	}
	if(words[row][checkcol]>words[row-1][checkcol])	{
		return true;
	}
	return checkhistory(row,checkcol);
}
int main()	{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)	{
		cin>>words[i];
	}
	char prev;
	bool flag;
	int ctr=0;
	for(int i=0;i<m;i++)	{
		for(int j=1;j<n;j++)	{
			if(words[j][i]<words[j-1][i])	{
				if(!checkhistory(j,i))	{
					legit[i]=true;
					ctr++;
					break;
				}
			}
		}
	}
	cout<<ctr<<endl;
}