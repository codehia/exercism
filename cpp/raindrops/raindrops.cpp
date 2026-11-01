#include "raindrops.h"

#include <string>

namespace raindrops {
std::string convert(int number) {
    std::string rain_sound{};
    if (number % 3 == 0) rain_sound += "Pling";
    if (number % 5 == 0) rain_sound += "Plang";
    if (number % 7 == 0) rain_sound += "Plong";
    if (rain_sound == "") rain_sound = std::to_string(number);
    return rain_sound;
}

}  // namespace raindrops
