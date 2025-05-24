//
// Created by Алексей on 24.05.2025.
//

#include "OptimizedMSDRadixQuickSort.h"

void OptimizedMSDRadixQuickSort(
    std::vector<std::string> &v, int left, int right, int len,
    long long &comparisons) {
  if (right - left < 74){
    ternarySort(v, left, right, len, comparisons);
    return;
  }

  if (left >= right) {
    return;
  }

  int curMin = left;
  for (int i = left; i <= right; ++i) {
    if (v[i].size() == len) {
      std::swap(v[curMin++], v[i]);
    }
  }

  if (curMin == right) {
    return;
  }

  auto boundaries = OptimizedCountingSort(v, curMin, right, len, comparisons);
  for (auto pair : boundaries) {
    OptimizedMSDRadixQuickSort(v, pair.first, pair.second - 1, len + 1, comparisons);
  }

}