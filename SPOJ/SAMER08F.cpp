#include <bits/stdc++.h>
using namespace std;
long long int arr[110];
void precompute()	{
	memset(arr,0,sizeof(arr));
	for(int i=1;i<=100;i++)	{
		for(int j=1;j<=i;j++)	{
			int row=i-j+1;
			arr[i]+=row*row;
		}
	}
	return;
}
int main()	{
	precompute();
	int n;
	scanf("%d",&n);
	while(n!=0)	{
		printf("%lld\n",arr[n]);
		scanf("%d",&n);
	}
	return 0;
}