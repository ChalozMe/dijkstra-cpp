#include "graph.h"

Graph::Graph(std::size_t n) : adj(n + 1) {}

void Graph::add_edge(int u, int v, int w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u, w});
}

const std::vector<std::pair<int,int>>& Graph::neighbors(int u) const
{
    return adj[u];
}

std::size_t Graph::size() const
{
    return adj.size();
}