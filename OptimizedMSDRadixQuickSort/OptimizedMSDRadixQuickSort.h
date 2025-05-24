//
// Created by Алексей on 24.05.2025.
//

#ifndef OPTIMIZEDMSDRADIXQUICKSORT
#define OPTIMIZEDMSDRADIXQUICKSORT

#include <iostream>
#include <vector>
#include "..\ternaryQuickSort\ternaryQuickSort.h"
#include "..\OptimizedMSDRadixSort\OptimizedMSDRadixSort.h"

void OptimizedMSDRadixQuickSort(
    std::vector<std::string> &v, int left, int right, int len,
    long long &comparisons);

#endif //OPTIMIZEDMSDRADIXQUICKSORT
