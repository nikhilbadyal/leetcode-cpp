//
// Created by Nikhil on 29-04-2021.
//

#include <string>
#include <algorithm>
#include "LongestPalindromicSubstring.h"

/*
std::string LongestPalindromicSubstring::longestPalindrome(const std::string &s) {

    return std::string();
}*/

std::string LongestPalindromicSubstring::slowLongestPalindrome(const std::string &s) {
    if (s.empty() || s.length() <= 0) { return ""; }
    int start = 0;
    int end = 0;
    for (int i = 0; i < s.length(); ++i) {
        int len1 = expandCentre(s, i, i);
        int len2 = expandCentre(s, i, i + 1);
        int maxLength = std::max(len1, len2);
        if (maxLength > end - start) {
            start = i - (maxLength - 1) / 2;
            end = i + maxLength / 2;
        }
    }
    return s.substr(start, end - start + 1);
}



int LongestPalindromicSubstring::expandCentre(const std::string &basicString, int low, int high) {
    if (basicString.empty() || low > high) { return 0; }
    while (low >= 0 && high < basicString.length() && basicString[high] == basicString[low]) {
        --low;
        ++high;
    }
    return high - low - 1;
}


//Alternative Solution

/*
 *   if (s.length() <= 1) return s;
     const int length = (int) s.length();
     int maxLength = 1;
     int start = 0;

     for (int i = 0; i < length - 1; ++i) {
         int l = i;
         int r = i;
         while (l >= 0 && r < length && s[l] == s[r]) {
             l--;
             r++;
         }
         int cur_length = r - l - 1;
         if (cur_length > maxLength) {
             maxLength = cur_length;
             start = l + 1;
         }
     }
     for (int i = 0; i < length - 1; ++i) {
         int l = i;
         int r = i + 1;
         while (l >= 0 && r < length && s[l] == s[r]) {
             l--;
             r++;
         }
         int cur_length = r - l - 1;
         if (cur_length > maxLength) {
             maxLength = cur_length;
             start = l + 1;
         }
     }


Some test cases
"7E9eOzflwE0idArS1gXyVwzfibbifzwV4odvQMq6gb"
"tWKxdW0M4Vzoj9Z3IrMkB2Xw2442wX2BN8bSXskBvz"
"1Y1V9LaVVAsSrZiLYwhJzLQLhIIhLQLzwgyDUVTyjM"
"9tVy8mi9VsUTMP5qlJGE1CLwrHHrwLC1oMITFECPjn"
"aXDPMIslSUqwiKKX9auxJCi1ecce1iCJEKkZXPbyX0"
"OUTYD2HEL6x2g6lUS3wNS7x994499x7SGtxZC4TgQP"
"7bjg2MPrkjRQZWVQ0Iz8WOY0PYYP0YOWUecP7djytN"
"ZwJqlp2Pldh3XZjJRoxFnm6RfTTfR6mnriF60L7NRp"
"rX4GZkr7qMIq1h0RM3c3cHrlZjjZlrHcQSHTyDcnQr"
"0FCIyGvmXpBqnatGC0RqfDYI0990IYDfGsIgsqEdWZ"
"QVKA5YRUZKZwpm33Iisf9bPi0ss0iPb9sT3QHMwWyj"
"t42bTzP15oqJB0Pug0J8LXL4u22u4LXLse29FIKLeH"
"XRRWafHe1YnMyRr1lICaDk7qmPPmq7kD30aXkI9hip"
"iI2jxUPQtfocR0ae617c3opm9DD9mpo3hwXmopJWsh"
"BU4FYj1tV7Puc44WWqiXihQdoJJodQhiFu3ls7yyPc"
"mms8ZnhHeCCqBDbbzpVNEhzirEErizhE9UKXhJ7tJH"
"yjEExeVk7YK2Qmb9u3vUVmCTimmiTCmVqso1OdcDg7"
"3XBEOVF8G6bJhR47sPrffTJSaRRaSJTfvVWpVQIZnc"
"SdGHjxsetzRZasz6zF06cAW2XhhX2WAcRyuBeP7fdb"
"pqpe2rsZmxG7eOYArvYJ8AgJ0XX0JgA82aqjL2EUaH"
"W0uvGK8zYLd158MHCrS8z1eNyllyNe1z9UxBzvdJ3n"
"RuUw2ERQ8s7acKCTqD5xuahuh55huhauIa2pPXRBtt"
"DvAPUetE62Ust0C9Cg3a2XtGJwwJGtX2TMcf8ZKdiR"
"50ZjpbxVZBkfjckq7YFIf3ib0VV0bi3f1nkZPAaY0Y"
"9OjakBKS1S5A0bnIQDLMW6hh2VV2hh6WXCWRvArat4"
"5ji7Vnpq0zBgLNT3mvwHec1RQTTQR1ceAWVdpd2p41"
"aJ5WAuPD9ijGJYZBGVbWueFbnssnbFeuU8GON0Gm8i"
"vquSFQwP2QSfZyGdhn78vIgOWZZWOgIvtcXNiE0sKW"
"Jxjbkco5xna7gJG4K643STCL8YY8LCTSp68Z5FCZuk"
"gnDegYIEsZMg0hWwFjDdNovpvppvpvoNwJxNYdwTR5"


 Running conditions

 int no_of_times_to_run = 30;
    int i = 0;
    const int palindrome_len = getRandomNumber();
    const int string_len = getRandomNumber();
    std::cout << palindrome_len << " is the palindrome length\n";
    std::cout << string_len << " is the String length\n\n";

    while (i != no_of_times_to_run) {
        const string palindrome = getRandomPalindrome(palindrome_len);
        const string randomStr  = getRandomString(string_len);
        string input;
        input = input.append(randomStr).append(palindrome).append(randomStr);
        auto start = std::chrono::high_resolution_clock::now();

        cout << input << " is the input\n";

        string answer = LongestPalindromicSubstring::slowLongestPalindrome(input);
        std::cout << answer << " is the longest palindrome substring with length " << answer.length()<<endl;

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        std::cout << "Time taken by function: "
                  << duration.count() << " nanosecond\n" << endl;
        i++;
    }
 */