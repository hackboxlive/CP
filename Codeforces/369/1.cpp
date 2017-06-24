#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	scanf("%d",&n);
	string s;
	char mat[2000][5];
	for(int i=0;i<n;i++)	{
		cin>>s;
		mat[i][0]=s[0];
		mat[i][1]=s[1];
		mat[i][2]=s[2];
		mat[i][3]=s[3];
		mat[i][4]=s[4];
	}
	bool flag=false;
	for(int i=0;i<n;i++)	{
		if(mat[i][0]=='O' && mat[i][1]=='O')	{
			mat[i][0]='+';
			mat[i][1]='+';
//			cout<<"HERE";
			flag=true;
			break;
		}
		if(mat[i][3]=='O' && mat[i][4]=='O')	{
			mat[i][3]='+';
			mat[i][4]='+';
			flag=true;
//			cout<<"HERE@";
			break;
		}
	}
	if(flag==true)	{
		cout<<"YES\n";
		for(int i=0;i<n;i++)	{
			for(int j=0;j<5;j++)	{
				printf("%c",mat[i][j]);
			}
			printf("\n");
		}
	}
	else	{
		cout<<"NO\n";
	}
	return 0;
}