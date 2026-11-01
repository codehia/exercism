#include "lasagna_master.h"

#include <string>
#include <vector>

namespace lasagna_master {
int preparationTime(std::vector<std::string> layers, int avg_time) {
    return layers.size() * avg_time;
}

amount quantities(std::vector<std::string> layers) {
    amount final_amount{0, 0.0};

    for (long unsigned int i = 0; i < layers.size(); ++i) {
        if (layers[i] == "noodles") {
            final_amount.noodles += 50;
        } else if (layers[i] == "sauce") {
            final_amount.sauce += 0.2;
        }
    }
    return final_amount;
}

void addSecretIngredient(std::vector<std::string>& my_list,
                         const std::vector<std::string>& friends_list) {
    my_list[my_list.size() - 1] = friends_list[friends_list.size() - 1];
}

std::vector<double> scaleRecipe(const std::vector<double> two_portion_amounts,
                                int number_of_portions) {
    std::vector<double> scaled_amounts{};
    for (long unsigned int i = 0; i < two_portion_amounts.size(); ++i) {
        scaled_amounts.emplace_back((two_portion_amounts.at(i) / 2) *
                                    number_of_portions);
    }
    return scaled_amounts;
}

void addSecretIngredient(std::vector<std::string>& my_list,
                         const std::string secret_ingredient) {
    my_list[my_list.size() - 1] = secret_ingredient;
}

}  // namespace lasagna_master
