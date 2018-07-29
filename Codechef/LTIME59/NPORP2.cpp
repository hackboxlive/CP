#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
vector<int> g[N];
bool vis[N];
int tVis[N];
 
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    while (cases--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            vis[i] = false;
        }
        for (int i = 1; i <= m; ++i) {
            int v, u;
            cin >> v >> u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        int x = -1;
        for (int i = 1; i <= n; ++i) {
            if (int(g[i].size()) < k) {
                x = i;
                break;
            }
        }
        if (x != -1) {
            cout << "CUT\n";
            cout << "1\n" << x;
        } else {
            vector<int> st;
            int v = 1;
            int timer = 0;
            while (!vis[v]) {
                vis[v] = true;
                st.push_back(v);
                tVis[v] = ++timer;
                int notVisU = -1, minVisU = -1;
                for (size_t j = 0; j < g[v].size(); ++j) {
                    int u = g[v][j];
                    if (!vis[u]) {
                        notVisU = u;
                        break;
                    } else {
                        if (minVisU == -1 || tVis[minVisU] > tVis[u]) {
                            minVisU = u;
                        }
                    }
                }
                if (notVisU != -1) {
                    v = notVisU;
                } else {
                    cout << "CYCLE\n";
                    vector<int> cycle;
                    while (st.back() != minVisU) {
                        cycle.push_back(st.back());
                        st.pop_back();
                    }
                    cycle.push_back(st.back());
                    cout << cycle.size() << "\n";
                    for (size_t i = 0; i < cycle.size(); ++i) {
                        cout << cycle[i] << " ";
                    }
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}