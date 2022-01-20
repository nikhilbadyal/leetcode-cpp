//
// Created by nikhi on 02-07-2021.
//

#include "AlienDictionary.h"
#include <map>

std::string AlienDictionary::order(std::vector<std::string> &words) {
    if (words.size() == 0) { return ""; }
    else {
        std::map<char, std::vector<char>> graph;
        std::map<char, int> inDegree;

        for (const auto &word : words) {
            for (auto ch : word) {
                inDegree[ch] = 0;
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            auto k = 0;
            auto l1 = words[i - 1].size();
            auto l2 = words[i].size();
            while (words[i][k] == words[i - 1][k]) {
                k++;
            }
            if (k >= std::min(l1, l2)) {
                continue;
            }
            inDegree[words[i][k]]++;
            graph[words[i - 1][k]].push_back(words[i][k]);
        }

        std::string ans;
        for (auto _ : inDegree) {
            char ch = ' ';
            for (auto val : inDegree) {
                if (!val.second) {
                    ch = val.first;
                    break;
                }
            }
            if (ch == ' ') {
                return "";
            }
            ans += ch;
            inDegree[ch]--;
            for (auto val : graph[ch]) {
                inDegree[val]--;
            }
        }
        return ans;
    }
}
