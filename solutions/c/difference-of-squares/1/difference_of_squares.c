#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number) {
  if (number == 0) {
    return 0;
  };
  return number * number + sum_of_squares(number - 1);
}

unsigned int sum_test(unsigned int num) {
  if (num == 0) {
    return 0;
  };
  return num + sum_test(num - 1);
}

unsigned int square_of_sum(unsigned int number) {
  if (number == 0) {
    return 0;
  };
  return sum_test(number) * sum_test(number);
}

unsigned int difference_of_squares(unsigned int number) {
  return square_of_sum(number) - sum_of_squares(number);
}
