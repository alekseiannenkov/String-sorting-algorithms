//
// Created by Алексей on 22.05.2025.
//

#ifndef MERGESORT
#define MERGESORT
#include "..\Utils\Utils.h"
#include <vector>
#include <iostream>

void merge(std::vector<std::string> &vector,
           int leftBound, int mid, int rightBound,
           long long &comparisons);

void mergeSort(std::vector<std::string> &vect,
               int leftBound, int rightBound, long long& comparisons);

void MergeSort(std::vector<std::string> &vect,
               int leftBound, int rightBound, int len, long long& comparisons);

#endif //MERGESORT
