#include "dijkstras.h"

int main() {
    Graph G;
    file_to_graph("/home/zhasan1/ICS46/HW8/src/small.txt", G);

    int source = 0;
    vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    for (int i = 0; i < G.numVertices; i++) {
        vector<int> path = extract_shortest_path(distances, previous, i);
        int total = distances[i];
        print_path(path, total);
    }
    return 0;
}
