//15:30
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

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

ull brute(int len,ull mask,int depth)
{

//	printf("in lenn = %d, mask = %llu\n",len,mask);
//	for(int i=0;i<10;i++)
//		printf("%d ",a[i]);
//	printf("\n");
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
		int bitsetcnt=0;
		
		
		for(int j=0;j<10;j++)
			if((i>>j)&1) {sum += a[j];}
		
		if(sum > len) continue;

		for(int j=0;j<10;j++)
			if((i>>j)&1)
			{
				mul *= choose(tl,a[j]);
				tl -= a[j];
			}
			printf("depth= %d i = %d, sum = %d, mul = %llu\n",depth,i,sum,mul);
			ull masked=mask|i;
			bitsetcnt=0;
			for(int k=0;k<10;k++)	{
				if((masked>>k)&1)	{
					bitsetcnt++;
				}
			}
			ull an = mul* (pow((10- bitsetcnt),len-sum) - brute(len-sum,mask | i,depth+1));
			printf("depth= %d Ans for len = %d and mask = %llu and masked= %llu is = %llu\n",depth,len,mask,mask|i,an); 
 			getchar();			
			ans += an;
	}
	
	dp[len][mask] = ans;
	return ans;
}
ull solve(ull num,int len,bool flag = true)
{
	
	printf("In len = %d\n",len);
	if(len == 0) return 0;

	int dig = num%10;
	ull ans = 0;
	
	int st = flag ? 1:0;
	for(int i=st;i<dig;i++)
	{
		memset(dp,-1,sizeof(dp));
		printf("i = %d\n",i);
		getchar();
		a[i]--;
		ull mask = 0;

		for(int j=0;j<10;j++)
			if(a[j] < 0)
				mask |= (ull)1<<j;

//		ull an = (ull)pow(10,len-1);
//			cout<<an<<endl;
	for(int i=0;i<10;i++)	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
		cout<<"len-1 = "<<len-1<<" mask="<<mask<<endl;
		ull an;
		//an =brute(len-1,mask); 
		printf("For %d , ans = %llu\n",i,an);
		ans += an;
		getchar();
		a[i]++;
	}

	
	a[dig]--;
	ans += solve(num/10,len-1,false);
	a[dig]++;	
	return ans;
}

int main()
{
	
	ull lim;
	scanf("%llu",&lim);
	
//	cout<<choose(7,3)<<endl;
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
	memset(dp,-1,sizeof(dp));
	printf("%llu\n",brute(lim,0,0));
//	ans = solve(num,len);
//	printf("%llu\n",ans);
	
}