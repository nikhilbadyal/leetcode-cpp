//
// Created by Nikhil on 01-05-2021.
//

#ifndef LEETCODE_ADDTWONUMBERS_H
#define LEETCODE_ADDTWONUMBERS_H

#include <ostream>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class AddTwoNumbers {
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};

#endif //LEETCODE_ADDTWONUMBERS_H
