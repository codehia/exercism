#include "raindrops.h"

#include <string>

namespace raindrops {
std::string convert(int number) {
    std::string rain_sound{};
    bool divisible_by_three = (number % 3 == 0);
    bool divisible_by_five = (number % 5 == 0);
    bool divisible_by_seven = (number % 7 == 0);

    if (!divisible_by_three && !divisible_by_five && !divisible_by_seven) {
        rain_sound = std::to_string(number);
    } else {
        if (divisible_by_three) {
            rain_sound += "Pling";
        }
        if (divisible_by_five) {
            rain_sound += "Plang";
        }
        if (divisible_by_seven) {
            rain_sound += "Plong";
        }
    }
    return rain_sound;
}

}  // namespace raindrops
