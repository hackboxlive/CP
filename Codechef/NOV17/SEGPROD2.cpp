#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;  // limit for array size
int n;  // array size
long long tree[2 * N];
int b[1001000];
long long p;
int dp[1001000][12];
int zero[1001000];
vector<pair<int,int> > factors;
void precompute() {
  long long temp = p;
  int ctr=0;
  if(temp%2==0) {
    ctr=0;
    while(temp%2==0)  {
      temp/=2;
      ctr++;
    }
    factors.push_back(make_pair(2,ctr));
  }
  for(int i=3;i<=sqrt(temp);i+=2) {
    if(temp%i==0) {
      ctr=0;
      while(temp%i==0)  {
        temp/=i;
        ctr++;
      }
      factors.push_back(make_pair(i,ctr));
    }
  }
  if(temp>2)  {
    factors.push_back(make_pair(temp,1));
  }
}
void build_dp(int pos,int v)  {
  int ctr;
  for(int i=0;i<factors.size();i++) {
    if(v%factors[i].first==0) {
      ctr=0;
      while(v%factors[i].first==0)  {
        v/=factors[i].first;
        ctr++;
      }
      dp[pos][i]=ctr;
    }
    else  {
      dp[pos][i]=0;
    }
  }
  if(v==0)  {
    zero[pos]=1;
  }
}
void build_again() {
  for(int i=0;i<factors.size();i++) {
    for(int j=1;j<n;j++)  {
      dp[j][i]+=dp[j-1][i];
    }
  }
  for(int i=1;i<n;i++)  {
    zero[i]+=zero[i-1];
  }
  // for(int i=0;i<n;i++)  {
  //   for(int j=0;j<factors.size();j++) {
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
}
void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) tree[i] = (tree[i<<1] * tree[i<<1|1]) % p;
}

int query(int l, int r) {  // sum on interval [l, r)
  long long res = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      res *= tree[l++];
      res%=p;
    }
    if (r&1) {
      res *= tree[--r];
      res%=p;
    }
  }
  return res;
}

int main()  {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)  {
    int q;
    cin>>n>>p>>q;
    precompute();
    for(int i=0;i<n;i++)  {
      cin>>tree[n+i];
      build_dp(i,tree[n+i]);
    }
    build_again();
    build();
    int bs=q/64+2;
    for(int i=0;i<bs;i++) {
      cin>>b[i];
    }
    long long x=0;
    int l,r;int v;
    for(int i=0;i<q;i++)  {
      if(i%64==0) {
        l=(b[i/64]+x)%n;
        r=(b[i/64+1]+x)%n;
      }
      else  {
        l=(l+x)%n;
        r=(r+x)%n;
      }
      if(l>r) {
        swap(l,r);
      }
      if(l==0)  {
        v=0;
        if(zero[r]>0) {
          break;
        }
        for(int j=0;j<factors.size();j++) {
          if(dp[r][j]>=factors[j].second) {
            v++;
          }
        }
      }
      else  {
        v=0;
        if(zero[r]-zero[l-1]>0) {
          break;
        }
        for(int j=0;j<factors.size();j++) {
          if(dp[r][j]-dp[l-1][j]>=factors[j].second)  {
            v++;
          }
        }
      }
      if(v<factors.size())  {
        x=query(l,r+1);
      }
      else  {
        x=0;
      }
      x++;
      x%=p;
    }
    cout<<x<<endl;
  }
  return 0;
}