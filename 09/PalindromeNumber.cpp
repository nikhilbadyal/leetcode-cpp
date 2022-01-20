//
// Created by Nikhil on 01-05-2021.
//

#include "PalindromeNumber.h"
#include <string>
#include <algorithm>

bool PalindromeNumber::isPalindrome(int num) {
    if (num < 0) { return false; }
    std::string str = std::to_string(num);
    std::string copy = str;
    reverse(str.begin(), str.end());
    return str == copy;
}
