#include <bits/stdc++.h>
using namespace std;
long long int mat[100100][3];
long long int ans[100100][3];
int main()	{
	int t=0;
	int n;
	scanf("%d",&n);
	while(n!=0)	{
		for(int i=0;i<n;i++)	{
			scanf("%lld %lld %lld",&mat[i][0],&mat[i][1],&mat[i][2]);
		}
		ans[0][0]=10000000000000000;
		ans[0][1]=mat[0][1];
		ans[0][2]=mat[0][1]+mat[0][2];
		for(int i=1;i<n;i++)	{
			ans[i][0]=mat[i][0]+min(ans[i-1][0],ans[i-1][1]);
			ans[i][1]=mat[i][1]+min(min(ans[i][0],ans[i-1][0]),min(ans[i-1][1],ans[i-1][2]));
			ans[i][2]=mat[i][2]+min(ans[i][1],min(ans[i-1][1],ans[i-1][2]));
		}
		printf("%d. %lld\n",++t,ans[n-1][1]);
		scanf("%d",&n);
	}
	return 0;
}