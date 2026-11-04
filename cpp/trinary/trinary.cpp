#include "trinary.h"

#include <cctype>
#include <cmath>
#include <cstddef>
#include <iostream>

namespace trinary {
bool isnum(std::string s) {
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

int to_decimal(std::string numeral_str) {
    if (!isnum(numeral_str)) return 0;
    int decimal_res{};

    for (std::size_t i = 0; i < numeral_str.size(); ++i) {
        int d = numeral_str[i] - '0';
        decimal_res += (d * std::pow(3, (numeral_str.size() - 1 - i)));
    }
    return decimal_res;
}

}  // namespace trinary
