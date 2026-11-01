#pragma once
#include <string>

namespace star_map {
enum class System {
    BetaHydri,
    Sol,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani
};
}

namespace heaven {
class Vessel {
   public:
    std::string name{};
    int generation{};
    int busters{};
    star_map::System current_system{};

    Vessel(std::string n, int g, star_map::System s = star_map::System::Sol);
    Vessel replicate(std::string name);
    void make_buster();
    bool shoot_buster();
};

std::string get_older_bob(Vessel first_vessel, Vessel second_vessel);
bool in_the_same_system(Vessel first_vessel, Vessel second_vessel);
}  // namespace heaven
