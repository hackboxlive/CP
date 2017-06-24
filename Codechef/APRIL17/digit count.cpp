//15:30
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
#define mp make_pair
int cnt,cl,m,calls;

#define getval(mask,pos) ((mask>>(pos*5)) & (ull)31)

int a[10];
ull dp[19][(1<<10)+1];


ull choose(int n,int r)
{
	if(r > n/2) r = n-r;
	
	ull ans = 1;
	for(int i=1;i<=r;i++)
		ans *= (n-r+i) , ans /= i;
	return ans;
}

ull brute(int len,ull mask)
{

	printf("in lenn = %d, mask = %llu\n",len,mask);
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	//getchar();
	if(len == 0) return 0;
	if(dp[len][mask] != -1) return dp[len][mask];

	ull ans = 0;
	for(int i=1;i<1<<10;i++)
	{
		
		if((mask & i) != 0) continue;
		
		ull mul = 1; 
		int tl = len;
		int sum = 0;
		
		
		for(int j=0;j<10;j++)
			if((i>>j)&1) sum += a[j];
		
		if(sum > len) continue;

		for(int j=0;j<10;j++)
			if((i>>j)&1)
			{
				mul *= choose(tl,a[j]);
				tl -= a[j];
			}
			printf("i = %d, sum = %d, mul = %llu\n",i,sum,mul);
			ans += mul* (pow(10,len-sum) - brute(len-sum,i));
	}
	
	dp[len][mask] = ans;
	return ans;
}
ull solve(ull num,int len)
{
	//getchar();
	printf("In len = %d\n",len);
	if(len == 0) return 0;

	memset(dp,-1,sizeof(dp));

	int dig = num%10;
	ull ans = 0;
	for(int i=1;i<dig;i++)
	{
		a[i]--;
		ull mask = 0;

		for(int j=0;j<10;j++)
			if(a[j] < 0)
				mask |= (ull)1<<j;

		ans += brute(len-1,mask);
		getchar();
		a[i]++;
	}
	
	a[dig]--;
	ans += solve(num/10,len-1);
	a[dig]++;	
	return ans;
}

int main()
{
	
	ull lim;
	scanf("%llu",&lim);
	
	for(int i=0;i<10;i++)
		scanf("%d",&a[i]);
	
	ull dup = lim, len = 0,num = 0;
	while(dup)
	{
		len++;
		int lst = dup%10;
		num = num*10 + lst;
		dup /= 10;
	}
	ull ans = 0;

	ans = solve(num,len);
	printf("%llu\n",ans);
	
}
