//
// Created by Nikhil on 01-05-2021.
//

#include "reverseInteger.h"
#include <string>
#include <algorithm>


int reverseInteger::reverse(int x) {
    if (x == INT_MIN) {
        return 0;
    }
    bool isNeg = x < 0;
    x = isNeg ? x * -1 : x;
    auto numLength = std::to_string(x).length();
    int reverse = 0;
    for (int i = 0; i < numLength; i++) {
        if (reverse > INT_MAX / 10) {
            return 0;
        }
        reverse = (reverse * 10) + x % 10;
        x /= 10;
    }
    if (isNeg) {
        reverse *= -1;
    }
    return reverse;
}