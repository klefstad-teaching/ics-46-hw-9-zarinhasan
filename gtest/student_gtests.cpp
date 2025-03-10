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

TEST(Ladder, SameWordEditDistAndAdjacent) {
  bool edit_dist = edit_distance_within("hello", "hello", 1);
  bool is_adj = is_adjacent("hello", "hello");
  
  EXPECT_EQ(edit_dist, true);
  EXPECT_EQ(is_adj, true);
}

TEST(Ladder, SubstitutionEditDistanceWithin) {
  bool edit_dist = edit_distance_within("cat", "car", 1);
  bool is_adj = is_adjacent("cat", "car");

  EXPECT_EQ(edit_dist, true);
  EXPECT_EQ(is_adj, true);
}

TEST(Ladder, InsertionEditDistanceWithin) {
  bool edit_dist = edit_distance_within("cat", "cart", 1);
  bool is_adj = is_adjacent("cat", "cart");

  EXPECT_EQ(edit_dist, true);
  EXPECT_EQ(is_adj, true);
}

TEST(Ladder, DeletionEditDistanceWithin) {
  bool edit_dist = edit_distance_within("later", "late", 1);
  bool is_adj = is_adjacent("later", "late");

  EXPECT_EQ(edit_dist, true);
  EXPECT_EQ(is_adj, true);
}

TEST(Ladder, MoreThanOneEditDistanceWithin) {
  bool edit_dist = edit_distance_within("leetcode", "letcoe", 1);
  bool is_adj = is_adjacent("leetcode", "letcoe");

  EXPECT_EQ(edit_dist, false);
  EXPECT_EQ(is_adj, false);
}