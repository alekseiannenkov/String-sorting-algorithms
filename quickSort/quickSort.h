//
// Created by Алексей on 22.05.2025.
//

#ifndef QUICKSORT
#define QUICKSORT

#include "..\Utils\Utils.h"
#include <vector>
#include <iostream>

int partition(std::vector<std::string> &arr, int left, int right,
              long long &comparisons);

void quickSort(std::vector<std::string> &arr, int left, int right,
               long long &comparisons);

void QuickSort(std::vector<std::string> &arr, int left, int right, int len,
               long long &comparisons);

#endif //QUICKSORT
