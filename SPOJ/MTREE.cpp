#include <bits/stdc++.h>
using namespace std;
long long MOD = (long long) 1e9 + 7;
long long DIV = (long long) 5e8 + 4;
vector<vector<pair<int,int> > > adj;
int vis[100003];
int par[100003];
long long path[100003];
long long weight[100003];
int N;
void dfs(int u){
    if(vis[u]) return;
    long long ret = 0;
    long long sum = 0;
    long long square = 0;
    for(int i=0;i<adj[u].size();++i){
        int v = adj[u][i].first;
        long long w = adj[u][i].second;
        if(par[u] != v) {
            par[v] = u;
            dfs(v);
            long long tmp = ((path[v] + 1LL) * w) % MOD;
            sum += tmp;
            sum %= MOD;
            square += (tmp * tmp) % MOD;
            square %= MOD;
            ret += weight[v];
            ret %= MOD;
        }
    }
    ret += sum;
    ret %= MOD;
    ret += (((sum * sum - square) % MOD) * DIV) % MOD;
    ret %= MOD;
    vis[u] = 1;
    path[u] = sum;
    weight[u] = ret;
}
void solve(){
    for(int i=1;i<=N;++i){
        vis[i] = 0;
        par[i] = -1;
    }
    dfs(1);
    printf("%lld\n", weight[1]);
}
int main(){
    int u, v, w;
    scanf("%d", &N);
    adj = vector<vector<pair<int,int> > >(N+3);
    for(int i=0;i<N-1;++i){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    solve();
    return 0;
}