#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <chrono>
#include "graph.h"
#include "dijkstra.h"

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (argc < 2)
    {
        std::cerr << "Usar: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return 1;
    }

    int V, E;
    in >> V >> E;

    int start, target;
    in >> start >> target;

    Graph g(V);

    for (int i = 0; i < V; i++) {
        int v;
        in >> v;  // ignorado
    }

    for (int i = 0; i < E; i++) {
        int a, b, w;
        in >> a >> b >> w;
        g.add_edge(a, b, w);
    }

    // ---------- Medición del tiempo ----------
    auto t1 = std::chrono::high_resolution_clock::now();

    auto dist = dijkstra(g, start, target);   // ← con early stop

    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = t2 - t1;
    std::cout << "Tiempo Dijkstra (µs): " << elapsed.count() << "\n";
    // -----------------------------------------

    long long ans = dist[target];
    if (ans == std::numeric_limits<long long>::max()) {
        std::cout << "No existe camino\n";
    } else {
        std::cout << ans << "\n";
    }

    return 0;
}
