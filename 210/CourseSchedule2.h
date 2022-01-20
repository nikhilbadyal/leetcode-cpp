//
// Created by nikhi on 02-07-2021.
//

#ifndef LEETCODE_COURSESCHEDULE2_H
#define LEETCODE_COURSESCHEDULE2_H


#include <vector>
#include <map>

class CourseSchedule {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites);

    void helper(int node , std::vector<int> & solution, std::vector<bool> & visited, std::map<int , std::vector<int>>& graph);

};

#endif //LEETCODE_COURSESCHEDULE2_H
