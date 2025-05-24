//
// Created by Алексей on 22.05.2025.
//

#include "Utils.h"


//void printVector(const std::vector<std::string> &v) {
//  for (auto &el : v) {
//    std::cout << el << '\n';
//  }
//}

// Сравнивает строки, начиная с n-ого символа.
// Выводит число: -1 если x < y, 0 если x = y и 1 если x > y.
// К параметру comparisons прибавляется количество сравнений.
int compareStrings(const std::string &x,
                   const std::string &y,
                   long long &comparisons) {
  for (int i = 0; i < std::min(x.size(), y.size()); ++i) {
    ++comparisons;
    if (x[i] < y[i]) {
      return -1;
    } else if (x[i] > y[i]) {
      return 1;
    }
  }

  if (x.size() < y.size()) {
    return -1;
  } else if (x.size() == y.size()) {
    return 0;
  } else {
    return 1;
  }
}