#ifndef MSDRADIXQUICKSORT
#define MSDRADIXQUICKSORT

#include <iostream>
#include <vector>
#include "..\ternaryQuickSort\ternaryQuickSort.h"
#include "..\MSDRadixSort\MSDRadixSort.h"

void MSDRadixQuickSort(
    std::vector<std::string> &v, int left, int right, int len,
    long long &comparisons);

#endif //MSDRADIXQUICKSORT
