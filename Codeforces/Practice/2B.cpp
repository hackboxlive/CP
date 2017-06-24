#include <bits/stdc++.h>
using namespace std;
int two[1100][1100];
int five[1100][1100];
int dp2[1100][1100];
int dp5[1100][1100];
int main()	{
	int n;
	int num1,num2;
	//set to zero
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n;j++)	{
			scanf("%d",&num1);
			num2=num1;
			while(num1%2 == 0)	{
				two[i][j]++;
				num1/=2;
			}
			while(num2%5 == 0)	{
				five[i][j]++;
				num2/=5;
			}
		}
	}
	dp2[0][0]=two[0][0];
	dp5[0][0]=five[0][0];
	for(int i=1;i<n;i++)	{
		dp2[0][i] += two[0][i];
		dp2[i][0] += two[i][0];

		dp5[0][i] += five[0][i];
		dp5[i][0] += five[i][0];
	}
	for(int i=1;i<n;i++)	{
		for(int j=1;j<n;j++)	{
			dp2[i][j] = min(dp2[i-1][j],dp2[i][j-1]) + two[i][j];
			
			dp5[i][j] = min(dp5[i-1][j],dp5[i][j-1]) + five[i][j];
		}
	}
	if(dp2[n-1][n-1] < dp5[n-1][n-1])	{
		cout<<dp2[n-1][n-1]<<endl;
		int r=n-1;
		int c=n-1;
		vector<char> dir;
		while(r!=0 && c!=0)	{
			if(dp2[r-1][c] < dp2[r][c-1])	{
				dir.push_back('D');
				r--;
			}
			else	{
				dir.push_back('R');
				c--;
			}
		}
		for(int i=dir.size()-1;i>=0;i--)	{
			cout<<dir[i];
		}
		cout<<endl;
	}
	else	{
		cout<<dp5[n-1][n-1]<<endl;
		int r=n-1;
		int c=n-1;
		vector<char> dir;
		while(r!=0 && c!=0)	{
			if(dp5[r-1][c] < dp5[r][c-1])	{
				dir.push_back('D');
				r--;
			}
			else	{
				dir.push_back('R');
				c--;
			}
		}
		for(int i=dir.size()-1;i>=0;i--)	{
			cout<<dir[i];
		}
		cout<<endl;
	}
	return 0;
}