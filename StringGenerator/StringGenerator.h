#ifndef STRINGGENERATOR_H_
#define STRINGGENERATOR_H_

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class StringGenerator {
 public:
  std::mt19937 mt;
  std::vector<char> alf;
  int arraySize;

  std::vector<std::string> base;
  std::vector<std::string> random;
  std::vector<std::string> reversed;
  std::vector<std::string> almostSorted;

  StringGenerator();

  // Создаёт алфавит
  static std::vector<char> getAlf();

  // Генерирует базовый массив, из которого потом будут
  // получены необходимые массивы.
  std::vector<std::string> createBaseArray();

  // Генерирует строку заданного размера
  std::string generateString(int size);

  std::vector<std::string> getRandomVector(int size);
  std::vector<std::string> getReversedVector(int size);
  std::vector<std::string> getAlmostSortedVector(int size);
};

#endif //STRINGGENERATOR_H_
