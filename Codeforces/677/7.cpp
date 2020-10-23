#include <iostream>
#include <bits/stdc++.h>

template<typename T>
void read(T& _val)
{
    std::cin >> _val;
}

template<typename T>
void print(const T& _val)
{
    std::cout << _val << std::endl;
}

typedef std::pair<int, int> iPair;
int dist[1010][1010];
std::vector<iPair> gp[1010];

void dijkstra(int src) 
{ 
    for(int i = 0; i < 1010; ++i)
    {
        dist[src][i] = 1e9;
    }
    std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq; 
    pq.push(std::make_pair(0, src)); 
    dist[src][src] = 0; 
  
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        std::vector<iPair>::iterator i;
        for (i = gp[u].begin(); i != gp[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            if (dist[src][v] > dist[src][u] + weight) 
            { 
                dist[src][v] = dist[src][u] + weight; 
                pq.push(std::make_pair(dist[src][v], v)); 
            } 
        } 
    } 
} 

int main()
{
    int n, m, k;
    read(n);
    read(m);
    read(k);
    int a, b, w;
    std::vector<iPair> couriers;
    for(int i = 0; i < m; ++i)
    {
        read(a);
        read(b);
        read(w);
        gp[a].push_back(std::make_pair(b, w));
        gp[b].push_back(std::make_pair(a, w));
    }
    for(int i = 0; i < k; ++i)
    {
        read(a);
        read(b);
        couriers.push_back(std::make_pair(a, b));
    }
    for(int i = 1; i <= n; ++i)
    {
        dijkstra(i);
    }
    int ans = 1e9;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < gp[i].size(); j++)
        {
            int v = gp[i][j].first;
            int this_ans = 0;
            for(int k = 0; k < couriers.size(); ++k)
            {
                int c1 = couriers[k].first;
                int c2 = couriers[k].second;
                this_ans += std::min(dist[c1][c2], std::min(dist[c1][i] + dist[v][c2], dist[c1][v] + dist[i][c2]));
            }
            ans = std::min(this_ans, ans);
        }
    }
    print(ans);
}