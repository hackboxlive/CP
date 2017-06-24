#include <bits/stdc++.h>
using namespace std;
   int lcm[1000];
   long long small[1000];
 void sieve() {
    int mod=1000000007;
  lcm[0] = 0, lcm[1] = 1;
  for(int i=2; i<3*100; ++i) {
    if(!small[i]) for(int j=i; j<3*100; j+=i) small[j] = i;
    int p = small[i], j;
    for(j=i; j%p==0; j/=p);
    if(j == 1) lcm[i] = (lcm[i-1]*(long long )p) % mod;
    else lcm[i] = lcm[i-1];
  }
}

int main ()
{
    sieve();
    int i,j;
    for(int i=0;i<100;i++)  {
        cout<<i<<" "<<lcm[i]<<endl;
    }
}
