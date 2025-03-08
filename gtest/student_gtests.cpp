#include <gtest/gtest.h>

#include "../src/dijkstras.cpp"
#include "../src/ladder.cpp"


TEST(DijkstraTest, SmallTxtDijkstra) {
  Graph G;
  file_to_graph("/home/zhasan1/ICS46/HW9/src/small.txt", G);

  vector<int> previous(G.numVertices, UNDEFINED);
  vector<int> distances = dijkstra_shortest_path(G, 0, previous);

  vector<int> expected_results = {0, 3, 6, 1};
  EXPECT_EQ(distances, expected_results);
}

TEST(DijkstraTest, MediumTxtDijkstra) {
  Graph G;
  file_to_graph("/home/zhasan1/ICS46/HW9/src/medium.txt", G);

  vector<int> previous(G.numVertices, UNDEFINED);
  vector<int> distances = dijkstra_shortest_path(G, 0, previous);

  vector<int> expected_results = {0, 5, 3, 12, 10, 2};
  EXPECT_EQ(distances, expected_results);
}

TEST(DijkstraTest, LargeTxtDijkstra) {
  Graph G;
  file_to_graph("/home/zhasan1/ICS46/HW9/src/large.txt", G);

  vector<int> previous(G.numVertices, UNDEFINED);
  vector<int> distances = dijkstra_shortest_path(G, 0, previous);

  vector<int> expected_results = {0, 7, 15, 5, 14, 11, 12};
  EXPECT_EQ(distances, expected_results);
}

TEST(DijkstraTest, PersonalTestDijkstra) {
  Graph G;
  file_to_graph("/home/zhasan1/ICS46/HW9/src/test.txt", G);

  vector<int> previous(G.numVertices, UNDEFINED);
  vector<int> distances = dijkstra_shortest_path(G, 0, previous);

  vector<int> expected_results = {0, 2, 1, 7, 10};
  EXPECT_EQ(distances, expected_results);
}

