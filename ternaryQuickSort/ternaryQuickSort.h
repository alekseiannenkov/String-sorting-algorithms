//
// Created by Алексей on 22.05.2025.
//

#ifndef TERNARYQUICKSORT
#define TERNARYQUICKSORT
#include <iostream>
#include <vector>
std::pair<int, int> partition(std::vector<std::string> &v,
                              int left, int right, int len,
                              long long &comparions);

void ternarySort(
    std::vector<std::string> &v, int left, int right, int len,
    long long &comparions);

#endif //TERNARYQUICKSORT
