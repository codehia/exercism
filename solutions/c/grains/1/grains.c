#include "grains.h"
#include <stdint.h>

uint64_t square(uint8_t index) {
  if (index == 0) {
    return 0;
  }
  if (index == 1) {
    return 1;
  }
  return 2 * square(index - 1);
}

uint64_t sum_till_idx(uint8_t idx, uint64_t sq) {
  if (idx == 0) {
    return sq;
  }
  return sum_till_idx(idx - 1, (square(idx) + sq));
}

uint64_t total(void) { return sum_till_idx(64, 0); }
