#include "dijkstra.h"
#include <queue>
#include <limits>

std::vector<long long> dijkstra(const Graph& g, int start) {
    const long long INF = std::numeric_limits<long long>::max();

    std::vector<long long> dist(g.size(), INF);
    dist[start] = 0;

    using State = std::pair<long long,int>; 
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : g.neighbors(u)) {
            int v = edge.first;
            int w = edge.second;

            long long nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    return dist;
}