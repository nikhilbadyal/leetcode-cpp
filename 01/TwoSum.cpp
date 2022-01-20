//
// Created by Nikhil on 30-04-2021.
//

#include "TwoSum.h"
#include <map>

std::vector<int> TwoSum::twoSum(const std::vector<int> &nums, int target) {
    const size_t size = nums.size();
    std::map<int, int> table;

    for (int i = 0; i < size; ++i) {
        int complement = target - nums[i];
        if (auto itr = table.find(complement); itr != table.end()) {
            std::vector<int> result = {itr->second, i};
            return result;
        }
        (void) table.insert({nums[i], i});
    }
    return {};

    //Other solution
    /*
     * std::map<int, int> table;
    for(int i = 0; i < ``nums.size(); i++)
    {
        if(!table.empty())
        {
            if(table.count(nums[i]))
                return {table.at(nums[i]), i};
        }
        table.insert({target-nums[i], i});
    }
    return {};
    }
};
     */
}

/*
 * Helper
 *int main() {
    int no_of_times_to_run = 1000;
    int i = 0;
    bool verbrose = false;
    while (i != no_of_times_to_run) {
        auto start = std::chrono::high_resolution_clock::now();
        int vector_length = getRandomNumber(2, 100);
        vector<int> nums;
        getRandomVector(nums, vector_length);
        int first_pos = getRandomNumber(1, vector_length - 1);
        int second_pos = getRandomNumber(1, vector_length - 1);
        if (first_pos == second_pos) {
            second_pos--;
        }
        auto ans = TwoSum::twoSum(nums, nums[first_pos] + nums[second_pos]);
        assert(nums[first_pos] + nums[second_pos] == nums[ans[0]] + nums[ans[1]]);
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
