#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cstdint>

class Graph
{
public:
    Graph(std::size_t n);

    void add_edge(int u, int v, int w);
    const std::vector<std::pair<int,int>>& neighbors(int u) const;

    std::size_t size() const;

private:
    std::vector<std::vector<std::pair<int,int>>> adj;

};

#endif