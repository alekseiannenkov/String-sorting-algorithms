#include "MSDRadixQuickSort.h"

void MSDRadixQuickSort(
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

  auto boundaries = countingSort(v, curMin, right, len, comparisons);
  for (auto pair : boundaries) {
    MSDRadixQuickSort(v, pair.first, pair.second - 1, len + 1, comparisons);
  }

}

//int main() {
//  int n;
//  std::cin >> n;
//  std::vector<std::string> v(n);
//  for (int i = 0; i < n; ++i) {
//    std::cin >> v[i];
//  }
//
//  MSDRadixQuickSort(v, 0, v.size() - 1, 0);
//  printVector(v);
//}
