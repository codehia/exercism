#pragma once

#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers, int avg_time = 2);

amount quantities(std::vector<std::string> layers);

void addSecretIngredient(std::vector<std::string>& my_list,
                         const std::vector<std::string>& friends_list);

std::vector<double> scaleRecipe(const std::vector<double> two_portion_amounts,
                                int number_of_portions);

void addSecretIngredient(std::vector<std::string>& my_list,
                         const std::string secret_ingredient);

}  // namespace lasagna_master
