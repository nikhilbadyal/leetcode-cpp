#include <algorithm>
#include <array>
#include <cstring>
#include <random>
#include <string>
#include <iostream>
#include <chrono>
#include <cassert>
#include <vector>

//#include "01/TwoSum.h"
//#include "02/AddTwoNumbers.h"
//#include "03/BruteLengthOfLongestSubstring.h"
//#include "04/MedianOfTwoSortedArrays.h"
//#include "05/LongestPalindromicSubstring.h"
//#include "06/ZigzagConversion.h"
#include "07/reverseInteger.h"
#include "11/ContainerWithMostWater.h"
//#include "08/StringToIntegerAtoi.h"
//#include "10/RegularExpressionMatching.h"
#include "338/CountingBits.h"
#include "1025/DivisorGame.h"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

std::string getRandomString(int);

std::string getPureRandomString(int);

std::string getRandomPalindrome(int);

int getRandomNumber(int start = 0, int length = 20);

void getRandomVector(std::vector<int> &nums, int length = 20, int start = INT_MIN, int end = INT_MAX);

long long getRandomLong(long long length = LONG_LONG_MAX);

//ListNode *getRandomList(int);

int main() {
    int noOfTimesToRun = 100;
    int curRun = 0;
    bool verbrose = false;
    while (curRun != noOfTimesToRun) {
        auto start = std::chrono::high_resolution_clock::now();
        int n = getRandomNumber(0, 1000);
        std::cout << n << std::endl;
        DivisorGame divisorGame = DivisorGame();
        auto x = divisorGame.divisorGame(624);
        std::cout << x << std::endl;
        if (verbrose) {
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            std::cout << "Time taken by function: "
                      << duration.count() << " nanosecond\n" << std::endl;
        }
        curRun++;
    }
    std::cout << "Done";
    return 0;
}

/*
ListNode *getRandomList(int number) {
    auto *myList = new ListNode();
    ListNode *temp = myList;
    string str = to_string(number);
    reverse(str.begin(), str.end());
    for (char c : str) {
        temp->next = new ListNode(c - '0');
        temp = temp->next;
    }
    return myList->next;
}*/

std::string getRandomString(int length) {
    static constexpr auto chars =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    std::random_device r;
    thread_local auto rng = std::default_random_engine(r());
    auto dist = std::uniform_int_distribution{{}, std::strlen(chars) - 1};
    std::string result = std::string(length, '\0');
    (void) std::generate_n(begin(result), length, [&]() { return chars[dist(rng)]; });
    return result;
}

std::string getPureRandomString(int length) {
    static constexpr auto chars =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    std::random_device r;
    thread_local auto rng = std::default_random_engine(r());
    auto dist = std::uniform_int_distribution{{}, std::strlen(chars) - 1};
    std::string result = std::string(length, '\0');
    (void) std::generate_n(begin(result), length, [&]() { return chars[dist(rng)]; });
    return result;
}

std::string getRandomPalindrome(int length) {
    std::string firstHalf = getRandomString(length / 2);
    std::string secondHalf = std::string(firstHalf.rbegin(), firstHalf.rend());

    return firstHalf + secondHalf;
}

int getRandomNumber(int start, int length) {
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^(
            static_cast<int>(
                    std::chrono::duration_cast<std::chrono::seconds>(
                            std::chrono::system_clock::now().time_since_epoch()
                    ).count()) +
            static_cast<int>(
                    std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::high_resolution_clock::now().time_since_epoch()
                    ).count())
    );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(start, length);
    return static_cast<int>(distrib(gen));
}

long long getRandomLong(long long length) {
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^(
            static_cast<int>(
                    std::chrono::duration_cast<std::chrono::seconds>(
                            std::chrono::system_clock::now().time_since_epoch()
                    ).count()) +
            static_cast<int>(
                    std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::high_resolution_clock::now().time_since_epoch()
                    ).count()));

    std::mt19937 gen(seed);
    std::uniform_int_distribution<long long> distrib(LONG_LONG_MIN, length);
    return distrib(gen);
}

void getRandomVector(std::vector<int> &nums, int length, int start, int end) {
    for (int i = 0; i < length; ++i) {
        nums.push_back(getRandomNumber(start, end));
    }
}