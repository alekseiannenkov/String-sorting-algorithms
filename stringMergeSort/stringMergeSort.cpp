#include "stringMergeSort.h"

// Сравнивает строки, начиная с n-ого символа (предполагается равенство всех
// пред*ыдущих символов).
// Выводит пару: первое число -1 если x < y, 0 если x = y и 1 если x > y.
// Второе число равно длине наибольшего общего префикса.
std::pair<int, int> LCPCompare(const std::string &x,
                               const std::string &y,
                               int n,
                               long long &comparisons) {
  for (int i = n; i < std::min(x.size(), y.size()); ++i) {
    ++comparisons;
    if (x[i] < y[i]) {
      return {-1, i};
    } else if (x[i] > y[i]) {
      return {1, i};
    }
  }

  if (x.size() < y.size()) {
    return {-1, x.size()};
  } else if (x.size() == y.size()) {
    return {0, x.size()};
  } else {
    return {1, y.size()};
  }
}

void stringMerge(
    std::vector<std::pair<std::string, int>> &v,
    int left, int mid, int right,
    long long &comparisons) {

  std::vector<std::pair<std::string, int>> firstVector;
  std::vector<std::pair<std::string, int>> secondVector;
  for (int i = left; i <= mid; ++i) {
    firstVector.push_back(v[i]);
  }
  for (int i = mid + 1; i <= right; ++i) {
    secondVector.push_back(v[i]);
  }

  int first = 0;
  int second = 0;
  int element = left;

  while (first < firstVector.size() && second < secondVector.size()) {
    int k = firstVector[first].second - secondVector[second].second;
    if (k > 0) {
      v[element++] = firstVector[first++];
    } else if (k < 0) {
      v[element++] = secondVector[second++];
    } else {
      auto res = LCPCompare(firstVector[first].first,
                            secondVector[second].first,
                            firstVector[first].second,
                            comparisons);
      if (res.first == -1) {
        v[element++] = firstVector[first++];
        secondVector[second].second = res.second;
      } else {
        v[element++] = secondVector[second++];
        firstVector[first].second = res.second;
      }

    }
  }

  while (first < firstVector.size()) {
    v[element++] = firstVector[first++];
  }

  while (second < secondVector.size()) {
    v[element++] = secondVector[second++];
  }
}

void stringMergeSort(
    std::vector<std::pair<std::string, int>> &v,
    int left, int right,
    long long &comparisons) {
  if (left == right) {
    return;
  }

  int mid = (left + right) / 2;

  stringMergeSort(v, left, mid, comparisons);
  stringMergeSort(v, mid + 1, right, comparisons);

  stringMerge(v, left, mid, right, comparisons);
}

void StringMergeSort(
    std::vector<std::string> &v,
    int left, int right, int len,
    long long &comparisons) {
  int n = v.size();
  std::vector<std::pair<std::string, int>> vect(n);

  for (int i = 0; i < n; ++i) {
    vect[i] = std::make_pair(v[i], 0);
  }

  stringMergeSort(vect, 0, v.size() - 1, comparisons);

  for (int i = 0; i < n; ++i) {
    v[i] = vect[i].first;
  }
}
