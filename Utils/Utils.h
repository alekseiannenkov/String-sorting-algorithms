//
// Created by Алексей on 22.05.2025.
//

#ifndef UTILS
#define UTILS
#include <iostream>
#include <vector>

void printVector(const std::vector<std::string> &v);


  // Сравнивает строки, начиная с n-ого символа.
  // Выводит число: -1 если x < y, 0 если x = y и 1 если x > y.
  // К параметру comparisons прибавляется количество сравнений.
int compareStrings(const std::string &x,
                     const std::string &y,
                   long long &comparisons);

#endif //UTILS
