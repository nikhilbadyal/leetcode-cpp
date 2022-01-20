//
// Created by Nikhil on 29-04-2021.
//

#ifndef LEETCODE_LONGESTPALINDROMICSUBSTRING_H
#define LEETCODE_LONGESTPALINDROMICSUBSTRING_H

class LongestPalindromicSubstring{
public:

    static std::string longestPalindrome(const std::string& s);
    static std::string slowLongestPalindrome(const std::string& s);

    static int expandCentre(const std::string &basicString, int start, int end);
};
#endif //LEETCODE_LONGESTPALINDROMICSUBSTRING_H
