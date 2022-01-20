//
// Created by Nikhil on 01-05-2021.
//

#include "AddTwoNumbers.h"

ListNode *AddTwoNumbers::addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto *myList = new ListNode();
    ListNode *temp = myList;
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    int carry = 0;

    while (temp1 || temp2 || carry) {
        int val1 = 0;
        int val2 = 0;
        if (temp1) {
            val1 = temp1->val;
            temp1 = temp1->next;
        }
        if (temp2) {
            val2 = temp2->val;
            temp2 = temp2->next;
        }
        int val3 = carry + val1 + val2;
        carry = val3 / 10;
        temp->next = new ListNode(val3 % 10);
        temp = temp->next;

    }
    return myList->next;
}

/*
 * Helper
 * int main() {
    int no_of_times_to_run = 1000;
    int i = 0;
    bool verbrose = false;
    int num1 = getRandomNumber(0, 10000);
    int num2 = getRandomNumber(0, 10000);
    while (i != no_of_times_to_run) {
        auto start = std::chrono::high_resolution_clock::now();
        ListNode *l1 = getRandomList(num1);
        ListNode *l2 = getRandomList(num2);
        auto myList = AddTwoNumbers::addTwoNumbers(l1, l2);
        auto temp = myList;
        string ans;
        while (temp != nullptr) {
            ans += std::to_string(temp->val);
            temp = temp->next;
        }
        reverse(ans.begin(), ans.end());
        assert(to_string(num1 + num2) ==ans );
        if (verbrose) {
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            std::cout << "Time taken by function: "
                      << duration.count() << " nanosecond\n" << endl;
        }
        i++;
    }
    std::cout << "Done";
    return 0;
}
 */

