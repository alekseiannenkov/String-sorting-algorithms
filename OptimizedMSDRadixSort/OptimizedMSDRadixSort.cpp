#include "OptimizedMSDRadixSort.h"


std::vector<std::pair<int, int>> OptimizedCountingSort(std::vector<std::string> &v,
                                              int left, int right, int len,
                                              long long &comparisons) {
  comparisons += right - left;
  int m = 123;  // Наибольшее ascii-значение равно 122.
  std::vector<std::pair<int, int>> count(m, {0, 0});
  for (int i = left; i <= right; ++i) {
    count[v[i][len]].first += 1;
    count[v[i][len]].second += 1;
  }

  int sum = left;
  for (int i = 1; i < m; ++i) {
    int temp = count[i].first;
    count[i].first = sum;
    count[i].second = sum;
    sum += temp;
  }

  auto out = std::vector<std::string>(right - left + 1);
  for (int i = left; i <= right; ++i) {
    out[count[v[i][len]].second - left] = v[i];
    count[v[i][len]].second++;
  }

  std::copy(out.begin(), out.end(), v.begin() + left);

  return count;
}

void OptimizedMSDRadixSort(
    std::vector<std::string> &v, int left, int right, int len,
    long long &comparisons) {
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
    OptimizedMSDRadixSort(v, pair.first, pair.second - 1, len + 1, comparisons);
  }

}

