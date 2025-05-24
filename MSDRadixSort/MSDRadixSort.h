//
// Created by Алексей on 22.05.2025.
//

#ifndef MSDRADIXSORT
#define MSDRADIXSORT

#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> countingSort(std::vector<std::string> &v,
                                              int left, int right, int len,
                                              long long &comparisons);

void MSDRadixSort(
    std::vector<std::string> &v, int left, int right, int len,
    long long &comparisons);

#endif //MSDRADIXSORT
