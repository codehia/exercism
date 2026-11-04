#include "difference_of_squares.h"

namespace difference_of_squares {
int square_of_sum(int range_of_numbers) {
    int total = 0;
    for (int i = 0; i <= range_of_numbers; ++i) {
        total += i;
    }
    return total * total;
}

int sum_of_squares(int range_of_numbers) {
    int total = 0;
    for (int i = 0; i <= range_of_numbers; ++i) {
        total += (i * i);
    }
    return total;
}

int difference(int range_of_numbers) {
    return square_of_sum(range_of_numbers) - sum_of_squares(range_of_numbers);
};
}  // namespace difference_of_squares
