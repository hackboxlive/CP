#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
# define ll long long int

typedef pair<ll, ll> iPair;

// int visited[100001];

class Graph{
    int V;

    list< pair<ll, ll> > *adj;

public:
    Graph(int V);

    void addEdge(int u, int v, ll w);

    void shortestPath(int s, int k, int x);
    void shortestPath2(int s, int k, int x);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, ll w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src, int k, int x){
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<ll> dist(V, INF);

    for(int i=0;i<k;i++){
        dist[i]=x;
        pq.push(make_pair(dist[i], i));
    }

    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();


        // if(visited[u]==1){
        //     continue;
        // }
        // visited[u]=1;

        list< pair<ll, ll> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            ll weight = (*i).second;

            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; ++i)
        printf("%lld ", dist[i]);
    printf("\n");
}


void Graph::shortestPath2(int src, int k, int x){
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<ll> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    bool flag=true;
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(flag && u<k){
            flag=false;
            for(int i=0;i<k;i++){
                if(dist[i]>dist[u]+x){
                    dist[i] = dist[u]+x;
                    pq.push(make_pair(dist[i], i));
                }
            }
        }


        // if(visited[u]==1){
        //     continue;
        // }
        // visited[u]=1;

        list< pair<ll, ll> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            ll weight = (*i).second;

            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; ++i)
        printf("%lld ", dist[i]);
    printf("\n");
}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n, k, x, m, s;

        scanf("%d%d%d%d%d", &n, &k, &x, &m, &s);

        Graph g(n);
        // memset(visited, 0, sizeof(int)*100001);

        for(int i=0;i<k;i++){
            for(int j=0;j<i;j++){
                g.addEdge(i, j, x);
            }
        }
        int a, b, c;
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &a, &b, &c);
            --a;
            --b;
            g.addEdge(a, b, c);
        }
        s--;

        if(s<k){
            g.shortestPath(s, k, x);
        } else{
            g.shortestPath2(s, k ,x);
        }
    }

    return 0;
}