#include "doctor_data.h"

heaven::Vessel::Vessel(std::string n, int g, star_map::System s) {
    name = n;
    generation = g;
    current_system = s;
};

heaven::Vessel heaven::Vessel::replicate(std::string name) {
    return heaven::Vessel(name, generation + 1, current_system);
};

void heaven::Vessel::make_buster() { busters += 1; }

bool heaven::Vessel::shoot_buster() {
    if (busters <= 0) {
        return false;
    } else {
        busters -= 1;
        return true;
    }
}

bool heaven::in_the_same_system(heaven::Vessel first_vessel,
                                heaven::Vessel second_vessel) {
    return first_vessel.current_system == second_vessel.current_system;
}

std::string heaven::get_older_bob(heaven::Vessel first_vessel,
                                  heaven::Vessel second_vessel) {
    if (first_vessel.generation < second_vessel.generation) {
        return first_vessel.name;
    } else {
        return second_vessel.name;
    };
}
