#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,c=0;
	cin>>n;
	if(n==1)	{
		cout<<"a\na\nb\nb\n";
	}
	else if(n==2)	{
		cout<<"aa\nbb\ncc\ndd\n";
	}
	else	{
		int mat[n][n];
		for(int i=0;i<n;i+=2)	{
			if(i+1<n)	{
				mat[0][i]=c;
				mat[0][i+1]=c;
				c++;
				c=c%7;
				mat[1][i]=c;
				mat[1][i+1]=c;
				c++;
				c=c%7;
			}
			if(i+2<n)	{
				mat[2][i+1]=c;
				mat[2][i+2]=c;
				c++;
				c=c%7;
				mat[3][i+1]=c;
				mat[3][i+2]=c;
				c++;
				c=c%7;
			}
		}
		mat[2][0]=23;
		mat[3][0]=23;
		if(n%2==1)	{
			mat[0][n-1]=24;
			mat[1][n-1]=24;
		}
		else	{
			mat[2][n-1]=24;
			mat[3][n-1]=24;
		}
		for(int i=0;i<n;i++)	{
			cout<<(char)(mat[0][i]+'a');
		}
		cout<<endl;
		for(int i=0;i<n;i++)	{
			cout<<(char)(mat[1][i]+'a');
		}
		cout<<endl;
		for(int i=0;i<n;i++)	{
			cout<<(char)(mat[2][i]+'a');
		}
		cout<<endl;
		for(int i=0;i<n;i++)	{
			cout<<(char)(mat[3][i]+'a');
		}
		cout<<endl;
	}
	return 0;
}