//
// Created by Nikhil on 30-04-2021.
//

#include "RegularExpressionMatching.h"

bool RegularExpressionMatching::isMatch(const std::string &string, const std::string &pattern) {
    if(pattern.empty()){
        return string.empty();
    }

    return false;
}
/*bool RegularExpressionMatching::isMatch(const std::string &string, const std::string &pattern) {
    if (!pattern.find('.') && !pattern.find('*')) {
        return string == pattern;
    }
    int pointer1 =  0;
    int pointer2= 0 ;
    while (pointer1 != string.length() && pointer2 != pattern.length()){
        char c1 = string[pointer1];
        char c2 = string[pointer2];

    }
    return false;
}*/
