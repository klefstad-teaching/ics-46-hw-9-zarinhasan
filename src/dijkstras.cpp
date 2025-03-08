#include "dijkstras.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
constexpr int UNDEFINED = -1;



vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int numVerts = G.size();
    vector<int> distances(numVerts, INF);
    vector<bool> visited(numVerts, false);
    distances[source] = 0;
    previous[source] = UNDEFINED;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});  // (distance, vertex)

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (Edge edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}


vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path_result;
    int current = destination;
    while (current != UNDEFINED) {
        path_result.push_back(current);
        current = previous[current];
    }
    reverse(path_result.begin(), path_result.end());
    return path_result;
}


void print_path(const vector<int>& v, int total) {
    if (!v.empty()) {
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}