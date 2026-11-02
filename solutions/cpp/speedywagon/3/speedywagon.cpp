#include "speedywagon.h"

namespace speedywagon {

bool connection_check(pillar_men_sensor* sensor) { return sensor != nullptr; }

int activity_counter(pillar_men_sensor* sensor_array_ptr, int capacity) {
    int total_activity{};

    if (sensor_array_ptr == nullptr) {
        return total_activity;
    }

    for (int i = 0; i < capacity; ++i) {
        total_activity += (sensor_array_ptr + i)->activity;
    }
    return total_activity;
}

bool alarm_control(pillar_men_sensor* sensor) {
    return (connection_check(sensor)) && (sensor->activity > 0);
};

bool uv_alarm(pillar_men_sensor* sensor) {
    return (connection_check(sensor)) &&
           (uv_light_heuristic(&sensor->data) > sensor->activity);
}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
