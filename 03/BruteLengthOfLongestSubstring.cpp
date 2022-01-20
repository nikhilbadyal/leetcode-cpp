//
// Created by Nikhil on 29-04-2021.
//

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "BruteLengthOfLongestSubstring.h"


int BruteLengthOfLongestSubstring::bruteLengthOfLongestSubstring(const std::string &s) {
    const size_t length = s.length();
    int globalMax = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = i; j < length; ++j) {
            if (isRepeat(s, i, j)) {

                globalMax = std::max(globalMax, j - i + 1);
            }
        }
    }
    return globalMax;
}

bool BruteLengthOfLongestSubstring::isRepeat(const std::string &basicString, int start, int end) {
    std::vector<bool> isAbsent(128, true);
    for (int i = start; i <= end; ++i) {
        if (isAbsent[basicString[i]]) {
            isAbsent[basicString[i]] = false;
        } else {
            return false;
        }
    }
    return true;
}

int BruteLengthOfLongestSubstring::lengthOfLongestSubstring(const std::string &s) {

    //Solution 1
    /*int globalMax = 0;
    int start = 0;
    map<char, int> storage;
    for (int end = 0; end < s.length(); ++end) {
        if (storage.find(s[end]) != storage.end()) {
            start = max(start, storage[s[end]] + 1);
        }
        storage[s[end]] = end;
        globalMax = max(globalMax, end - start + 1);
    }

    return globalMax;*/

    //Better solution
    //Solution 2
    std::vector<char> myvec;
    size_t longestLength = 0;
    for (char i : s) {

        if (auto it = std::find(myvec.begin(), myvec.end(), i);it != myvec.end()) {
            if (longestLength < myvec.size()) {
                longestLength = myvec.size();
            }
            it++;
            (void) myvec.erase(myvec.begin(), it);
        }
        myvec.push_back(i);
    }
    if (longestLength < myvec.size()) {
        longestLength = myvec.size();
    }

    return static_cast<int>(longestLength);
}

/*
 * Q3
 * std::string input = getRandomString(2000);
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << BruteLengthOfLongestSubstring::lengthOfLongestSubstring(input)
              << " is the length of longest substring.\n";

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << "nanosecond" << endl;


    start = std::chrono::high_resolution_clock::now();
    std::cout << BruteLengthOfLongestSubstring::bruteLengthOfLongestSubstring(input)
              << " is the length of longest substring.\n";

    stop = std::chrono::high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    std::cout << "Time taken by function: "
              << duration.count() << " nanosecond" << endl;


 */
