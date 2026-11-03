#include "power_of_troy.h"

#include <memory>

namespace troy {

void give_new_artifact(human& human_ref, std::string artifact_name) {
    human_ref.possession = std::make_unique<artifact>(artifact_name);
}

void exchange_artifacts(std::unique_ptr<artifact>& possession_one,
                        std::unique_ptr<artifact>& possession_two) {
    possession_one.swap(possession_two);
}

void manifest_power(human& human_ref, std::string power_name) {
    human_ref.own_power = std::make_unique<power>(power_name);
}

void use_power(human& caster, human& target) {
    target.influenced_by = caster.own_power;
}

int power_intensity(human& h) {
    if (h.own_power == nullptr) {
        return 0;
    }
    return h.own_power.use_count();
}

}  // namespace troy
