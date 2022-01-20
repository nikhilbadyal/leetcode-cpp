//
// Created by nikhi on 01-07-2021.
//

#ifndef LEETCODE_COURSESCHEDULE_H
#define LEETCODE_COURSESCHEDULE_H

#include <vector>
#include <map>

class CourseSchedule {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites);

    bool hasCycle(int v, std::vector<bool> &visited, std::vector<bool> &stack, std::map<int, std::vector<int>> &map);

};
#endif //LEETCODE_COURSESCHEDULE_H
