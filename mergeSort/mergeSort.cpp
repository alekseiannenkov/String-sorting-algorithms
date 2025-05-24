#include "mergeSort.h"
void merge(std::vector<std::string> &vector,
           int leftBound, int mid, int rightBound,
           long long &comparisons) {

  std::vector<std::string> firstVector;
  std::vector<std::string> secondVector;

  for (int i = leftBound; i <= mid; ++i) {
    firstVector.push_back(vector[i]);
  }

  for (int i = mid + 1; i <= rightBound; ++i) {
    secondVector.push_back(vector[i]);
  }

  int first = 0;
  int second = 0;
  int element = leftBound;

  int firstSize = firstVector.size();
  int secondSize = secondVector.size();
  while (first < firstSize && second < secondSize) {
    if (compareStrings(firstVector[first], secondVector[second], comparisons) <= 0) {
//    if (firstVector[first] <= secondVector[second]) {
      vector[element++] = firstVector[first++];

    } else {
      vector[element++] = secondVector[second++];
    }
  }

  while (first < firstSize) {
    vector[element++] = firstVector[first++];
  }

  while (second < secondSize) {
    vector[element++] = secondVector[second++];
  }
}

void mergeSort(std::vector<std::string> &vect,
               int leftBound, int rightBound, long long& comparisons) {

  if (rightBound - leftBound <= 1) {
    if (compareStrings(vect[rightBound], vect[leftBound], comparisons) < 0) {
//    if (vect[rightBound] < vect[leftBound]) {
      std::swap(vect[rightBound], vect[leftBound]);

    }
    return;
  }

  int middle = (leftBound + rightBound) / 2;

  mergeSort(vect, leftBound, middle, comparisons);
  mergeSort(vect, middle + 1, rightBound, comparisons);

  merge(vect, leftBound, middle, rightBound, comparisons);
}

void MergeSort(std::vector<std::string> &vect,
               int leftBound, int rightBound, int len, long long& comparisons){
  mergeSort(vect, leftBound, rightBound, comparisons);
}
