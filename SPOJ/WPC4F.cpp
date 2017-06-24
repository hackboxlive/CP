#include <bits/stdc++.h>
using namespace std;
int mat[25][3];
int ans[25][3];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d%d%d",&mat[i][0],&mat[i][1],&mat[i][2]);
		}
		ans[0][0]=mat[0][0];
		ans[0][1]=mat[0][1];
		ans[0][2]=mat[0][2];
		for(int i=1;i<n;i++)	{
			ans[i][0]=mat[i][0]+min(ans[i-1][1],ans[i-1][2]);
			ans[i][1]=mat[i][1]+min(ans[i-1][0],ans[i-1][2]);
			ans[i][2]=mat[i][2]+min(ans[i-1][0],ans[i-1][1]);			
		}
//		for(int i=0;i<n;i++)	{
//			printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
//		}
		int totans=min(ans[n-1][0],min(ans[n-1][1],ans[n-1][2]));
		printf("%d\n",totans);
	}
}