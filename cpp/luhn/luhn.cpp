#include "luhn.h"

#include <cctype>
#include <cstddef>

namespace luhn {
std::string remove_sapces(std::string s) {
    std::string cleaned_string = "";

    for (std::size_t i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            cleaned_string += s[i];
        }
    }
    return cleaned_string;
}

bool valid_string(std::string s) {
    if (s.size() < 2) return false;
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
}

bool valid(std::string s) {
    std::string cleaned_string = remove_sapces(s);
    if (!valid_string(cleaned_string)) return false;

    int len = cleaned_string.size() - 1;
    int total{};

    for (int i = len; i >= 0; i--) {
        int digit = cleaned_string[i] - '0';

        if ((len - i) % 2 == 0) {
            total += digit;
        } else {
            digit *= 2;
            if (digit > 9) digit -= 9;
            total += digit;
        }
    }
    return total % 10 == 0;
}

}  // namespace luhn
