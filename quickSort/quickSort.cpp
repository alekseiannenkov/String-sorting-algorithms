#include "quickSort.h"

int partition(std::vector<std::string> &arr, int left, int right,
              long long &comparisons) {
  int m = (right + left) / 2;
  std::swap(arr[m], arr[right]);
  std::string pivot = arr[right];

  int i = left - 1;
  for (int j = left; j < right; ++j) {
    if (compareStrings(arr[j], pivot, comparisons) <= 0) {
//    if (arr[j] <= pivot) {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[right]);

  return i + 1;
}

void quickSort(std::vector<std::string> &arr, int left, int right,
               long long &comparisons) {
  if (left < right) {
    int part = partition(arr, left, right, comparisons);

    quickSort(arr, left, part - 1, comparisons);
    quickSort(arr, part + 1, right, comparisons);
  }
}

void QuickSort(std::vector<std::string> &arr, int left, int right, int len,
               long long &comparisons){
  quickSort(arr, left, right, comparisons);
}