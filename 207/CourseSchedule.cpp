//
// Created by nikhi on 01-07-2021.
//

#include "CourseSchedule.h"
#include <map>
#include <vector>


bool CourseSchedule::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::map<int , std::vector<int> > graph ;
    for(auto i : prerequisites){
        graph[i[0]].emplace_back(i[1]);
    }
    std::vector<bool> stack(numCourses , false) ;
    std::vector<bool> visited (numCourses , false) ;

    for(int i = 0 ; i < numCourses ; ++i){
        if(hasCycle(i,visited,stack , graph)){
            return false;
        }
    }
    return true;
}

bool CourseSchedule::hasCycle(int v, std::vector<bool> &visited, std::vector<bool> &stack ,  std::map<int, std::vector<int>> &graph ) {
    if(!visited[v]){
        visited[v] = true;
        stack[v] = true;

        for(int i = 0 ; i < graph[v].size() ; ++i){
            if(!visited[i] && hasCycle(i,visited , stack,graph)){
                return true;
            }else if(stack[i]){
                return true;
            }
        }
    }

    stack[v] = false;
    return false ;
}

/*

bool CourseSchedule::canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::map<int, std::vector<int>> map;
    std::vector<bool> visited;
    for (auto &item : prerequisites) {
        map[item[1]].push_back(item[0]);
    }
    for (auto &item: map) {
        if (!visited[item.first]) {
            if (hasCycle(map, item.first, visited)) return false;
        }
    }
    return true;
}

bool
CourseSchedule::hasCycle(std::map<int, std::vector<int>> &map, int node, std::vector<bool> &visited) {
    if (visited[node]) {
        return true;
    } else {
        for (auto &item : map[node]) {
            if(hasCycle(map, item, visited)){
                return true;
            }
        }
    }
    visited[node] = true;
    return false;
}
*/
