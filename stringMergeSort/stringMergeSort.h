//
// Created by Алексей on 22.05.2025.
//

#ifndef STRINGMERGESORT
#define STRINGMERGESORT

#include "..\Utils\Utils.h"
#include <vector>
#include <iostream>

// Сравнивает строки, начиная с n-ого символа (предполагается равенство всех
// предыдущих символов).
// Выводит пару: первое число -1 если x < y, 0 если x = y и 1 если x > y.
// Второе число равно длине наибольшего общего префикса.
std::pair<int, int> LCPCompare(const std::string &x,
                               const std::string &y,
                               int n,
                               long long &comparisons);

void stringMerge(
    std::vector<std::pair<std::string, int>> &v,
    int left, int mid, int right,
    long long &comparisons);

void stringMergeSort(
    std::vector<std::pair<std::string, int>> &v,
    int left, int right,
    long long &comparisons);

void StringMergeSort(
    std::vector<std::string> &v,
    int left, int right, int len,
    long long &comparisons);

#endif //STRINGMERGESORT
