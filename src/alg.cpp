// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxValue = 1;
  while (num != 1) {
    if (num > maxValue) {
      maxValue = num;
    }
    if (num % 2 == 0) {
      num /= 2;
    }
    else {
      num = num * 3 + 1;
    }
  }
  return maxValue;
}

unsigned int collatzLen(uint64_t num) {
  if (num == 1) return 1;
  else if (num % 2 == 1) return 1 + collatzLen(3 * num + 1);
  else if (num % 2 == 0) return 1 + collatzLen(num / 2);
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int num = 0;
  *maxlen = 0;
  for (lbound; lbound <= rbound; lbound++) {
    uint64_t tlen = collatzLen(lbound);
    if (tlen > *maxlen) {
      *maxlen = tlen;
      num = lbound;
    }
  }
  return num;
}
