#include <bits/stdc++.h>
using namespace std;
int mat[110][110];
int arr[100100];
int main()	{
	int h,w;
	cin>>h>>w;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	int r=0,c=0;
	int dir=1;
	for(int i=0;i<n;i++)	{
		int j=0;
		while(j<arr[i])	{
			mat[r][c]=i+1;
			if(dir==1)	{
				r++;
			}
			else	{
				r--;
			}
			if(r==h)	{
				c++;
				dir=-1;
				r--;
			}
			if(r==-1)	{
				c++;
				dir=1;
				r++;
			}
			j++;
		}
	}
	for(int i=0;i<h;i++)	{
		for(int j=0;j<w;j++)	{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}