//
// Created by nikhi on 02-07-2021.
//

#include "CourseSchedule2.h"
#include <algorithm>


std::vector<int> CourseSchedule::findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<int> solution;
    std::vector<bool> visited(numCourses, false);
    std::map<int, std::vector<int> > graph;
    for (auto i : prerequisites) {
        graph[i[1]].push_back(i[0]);
    }

    for (int i = 0; i < numCourses; ++i) {
        if (!visited[i]) {
            helper(i, solution, visited, graph);
        }
    }
    std::reverse(solution.begin(), solution.end());
    return solution;
}

void CourseSchedule::helper(int node, std::vector<int> &solution, std::vector<bool> &visited,
                            std::map<int, std::vector<int>> &graph) {
    visited[node] = true;
    auto adj = graph[node];
    for (auto x: adj) {
        if (!visited[x]) {
            helper(x, solution, visited, graph);
        }
    }
    solution.push_back(node);
}
