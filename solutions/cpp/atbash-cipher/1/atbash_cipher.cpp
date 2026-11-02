#include "atbash_cipher.h"

#include <array>
#include <cctype>
#include <iostream>
#include <string>

namespace atbash_cipher {

int find_idx(char character) {
    std::array<char, 26> character_array{
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (long unsigned int i{0}; i < character_array.size(); ++i) {
        if (character_array[i] == std::tolower(character)) return i;
    }

    return -1;
}

std::string encode(std::string str_to_encode) {
    std::array<char, 26> character_array{
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    std::string encoded_string{""};
    int space_counter{0};

    for (long unsigned int i{0}; i < str_to_encode.size(); ++i) {
        char character = str_to_encode[i];
        int character_idx = find_idx(character);

        if (std::isalnum(character)) {
            if (space_counter == 5) {
                encoded_string += " ";
                space_counter = 0;
            }

            if (std::isdigit(character)) {
                encoded_string += character;
            } else {
                encoded_string += character_array[25 - character_idx];
            }

            space_counter += 1;
        }
    }
    return encoded_string;
}

std::string decode(std::string str_to_decode) {
    std::string decoded_with_spaces = encode(str_to_decode);
    std::string decoded_string_without_spaces = {""};

    for (long unsigned int i = 0; i < decoded_with_spaces.size(); ++i) {
        char character = decoded_with_spaces[i];
        if (character != ' ') {
            decoded_string_without_spaces += character;
        }
    }

    return decoded_string_without_spaces;
}

}  // namespace atbash_cipher
