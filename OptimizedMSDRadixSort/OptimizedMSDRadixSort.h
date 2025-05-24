//
// Created by Алексей on 24.05.2025.
//

#ifndef OPTIMIZEDMSDRADIXSORT
#define OPTIMIZEDMSDRADIXSORT

#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> OptimizedCountingSort(std::vector<std::string> &v,
                                              int left, int right, int len,
                                              long long &comparisons);

void OptimizedMSDRadixSort(
    std::vector<std::string> &v, int left, int right, int len,
    long long &comparisons);

#endif //OPTIMIZEDMSDRADIXSORT
