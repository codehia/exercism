#include "reverse_string.h"

#include <cstddef>
#include <utility>

namespace reverse_string {

std::string reverse_string(std::string str) {
    if (str.empty()) return str;

    std::size_t left = 0;
    std::size_t right = str.size() - 1;

    while (left < right) {
        std::swap(str[left++], str[right--]);
    }
    return str;
}

}  // namespace reverse_string
