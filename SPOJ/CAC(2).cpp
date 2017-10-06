#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
 
int n,e;
 
vector<int> nbs[101];
int height[101];
int par[101];
vector<int> cycles;
 
void clear() {
    for (int i = 0; i<100; ++i) {
        nbs[i].clear();
        cycles.clear();
        height[i] = 0;
        par[i] = 0;
    }
}
 
 
 
int dfs(int vertex, int parent) {
    if (height[vertex] > 0) {
        if (par[parent]==vertex || height[parent]-height[vertex] <= 0)return 0;
        return 1+height[parent]-height[vertex];
    }
    height[vertex] = height[parent]+1;
    par[vertex] = parent;
    int ans = 0;
    int sz = nbs[vertex].size();
    for (int i = 0; i < sz; ++i) {
        int val = dfs(nbs[vertex][i], vertex);
        if (val>0) cycles.push_back(val);
    }
    return ans;
}
 
int main() {
    int t;
    scanf("%d", &t);
    for (int k = 1;  k <= t; ++k) {
        scanf("%d%d", &n,&e);
        clear();
        for (int i = 0; i < e; ++i) {
            int a,b;
            scanf("%d%d",&a,&b);
            nbs[a].push_back(b);
            nbs[b].push_back(a);
        }
        dfs(1,0);
        unsigned long long ans = 0;
        if(cycles.size() > 0) {
            ans = 1;
 
            for (int i = 0; i < cycles.size(); ++i) {
                    ans*=cycles[i];
            }
        }
        printf("Case %d: %llu\n", k, ans);
    }
    return 0;
}