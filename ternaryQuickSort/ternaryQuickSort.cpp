#include "ternaryQuickSort.h"
std::pair<int, int> partition(std::vector<std::string> &v,
                              int left, int right, int len,
                              long long &comparions) {
  if (right - left <= 0) {
    return {left, right};
  }

  int m = (right + left) / 2;

  char pivot = v[m][len];

  std::swap(v[m], v[left]);

  int leftPointer = left;   // Указывает на первый =
  int rightPointer = left + 1;  // Указывает на первый >
  for (int current = left + 1; current <= right; ++current) {
    ++comparions;
    auto k = v[current][len] - pivot;

    if (k < 0) {
      // Символ меньше pivot
      std::swap(v[leftPointer++], v[current]);
      std::swap(v[rightPointer++], v[current]);
    } else if (k == 0) {
      // Символ равен pivot
      std::swap(v[rightPointer++], v[current]);
    }
  }

  return {leftPointer, rightPointer - 1};
}

void ternarySort(
    std::vector<std::string> &v, int left, int right, int len,
    long long &comparions) {
  if (right <= left) {
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

  auto pair = partition(v, curMin, right, len, comparions);

  ternarySort(v, curMin, pair.first - 1, len, comparions);
  ternarySort(v, pair.first, pair.second, len + 1, comparions);
  ternarySort(v, pair.second + 1, right, len, comparions);
}