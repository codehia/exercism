#include "rotational_cipher.h"

#include <cctype>
#include <cstddef>

namespace rotational_cipher {

std::string rotate(std::string plain_string, int key) {
    std::string final_string;

    for (std::size_t i = 0; i < plain_string.size(); ++i) {
        char character = plain_string[i];
        if (!std::isalpha(character)) {
            final_string += character;
        } else if (std::isupper(character)) {
            final_string += 'A' + ((character - 'A') + key) % 26;
        } else {
            final_string += 'a' + ((character - 'a') + key) % 26;
        }
    }
    return final_string;
}

}  // namespace rotational_cipher
