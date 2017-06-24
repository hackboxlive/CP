#include <bits/stdc++.h>
using namespace std;
long long inv(int a)
{

	long long res = 1;
    long long cur = a;
    int k=1000000005;

  while (k) {
    if (k%2) {
      res = (res * cur)%1000000007;
    }
    k /= 2;
    cur = (cur * cur) % 1000000007;
  }
  return res;
}

int main() {
	int t,n1,n,r;
	scanf("%d",&t);
	long long ans;
	long long *A=new long long[2000000];
	A[0]=1;
	for(int i=1;i<2000000;i++)
	A[i]=(A[i-1]*(i+1))%1000000007;
	while(t--)
	{
		scanf("%d",&n1);
		if(n1==0)
		{
			printf("1\n");
			continue;
		}
		ans=A[2*n1-2];
		ans=(ans*inv(A[n1-2]))%1000000007;
		ans=(ans*inv(A[n1-1]))%1000000007;
		ans=(ans*n1)%1000000007;
		printf("%llu\n",ans);
	}
}