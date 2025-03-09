#include "ladder.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;


void error(string word1, string word2, string msg) {
    cerr << msg << " " << word1 << " " << word2 << endl;
}


bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    if (str1 == str2)
        return true;

    int s1_len = str1.length();
    int s2_len = str2.length();

    if (abs(s1_len - s2_len) > d)
        return false;

    // substitution case
    if (s1_len == s2_len) {
        int count = 0;
        for (int i = 0; i < s1_len; i++) {
            if (str1[i] != str2[i])
                count++;
            if (count > d)
                return false;
        }
        return count == d;
    }

    // insertion/deletion case
    if (abs(s1_len - s2_len) == d) {
        string short_str = str1;
        string long_str = str2;
        if (s1_len > s2_len) {
            short_str = str2;
            long_str = str1;
        }

        for (int i = 0; i < s1_len + 1; i++) {
            if (str1[i] != str2[i])
                return short_str.substr(i) == long_str.substr(i + 1);
        }
        return true;
    }
    return false;
}


bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}


vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (const string& word: word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);

                    if (word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}


void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    if (!in) {
        cerr << "Can't open file" << endl;
        return;
    }

    for (string word; in >> word; ) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_list.insert(word);
    }

    in.close();
    cout << "Done with load_words!" << endl;
}


void print_word_ladder(const vector<string>& ladder) {
    if (!ladder.empty()) {
        cout << "Word ladder found: ";
        for (size_t i = 0; i < ladder.size(); i++) {
            cout << ladder[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No word ladder found." << endl;
    }
}


#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "/home/zhasan1/ICS46/HW9/src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}