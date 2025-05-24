//
// Created by Алексей on 22.05.2025.
//

#include "StringGenerator.h"
std::vector<char> StringGenerator::getAlf() {
  std::string spec = "!@#%:;^&*()-.";
  std::vector<char> v;
  for (int i = 1; i <= 130; ++i){
    auto c = char(i);
    if (('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z') ||
        ('0' <= c && c <= '9') ||
        (spec.find(c)) != std::string::npos){
      v.push_back(c);
    }
  }

  return v;
}

StringGenerator::StringGenerator() : mt(333), arraySize(3000) {
  this->alf = getAlf();
  base = createBaseArray();
  std::shuffle(base.begin(), base.end(), mt);
  this->random = base;

  std::sort(base.begin(), base.end(), std::greater<>());
  reversed = base;

  std::reverse(base.begin(), base.end());
  almostSorted = base;
  for (int i = 0; i < arraySize; i += arraySize / 20){
    std::swap(almostSorted[i], almostSorted[mt() % 200]);
  }
}

std::string StringGenerator::generateString(int size) {
  std::string out;
  out.clear();

  for (int i = 0; i < size; ++i){
    out += this->alf[mt() % 74];
  }

  return out;
}

std::vector<std::string> StringGenerator::createBaseArray() {
  std::vector<std::string> v;

  // 1/10 массива - независимые строки случайной длины
  for (int i = 0; i < this->arraySize / 10; ++i){
    v.push_back(generateString(10 + (mt() % 190)));
  }

  // 1/10 массива - повторяющаяся строка длины 50
  auto repeated = generateString(50);
  for (int i = 0; i < this->arraySize / 10; ++i){
    v.push_back(repeated);
  }

  // 4/10 массива - строки, совпадающие в 20 символах
  repeated = generateString(20);
  for (int i = 0; i < this->arraySize * 4 / 10; ++i){
    v.push_back(repeated + generateString(mt() % 180));
  }

  // 4/10 массива - строки, совпадающие в 150 символах
  repeated = generateString(150);
  for (int i = 0; i < this->arraySize * 4 / 10; ++i){
    v.push_back(repeated + generateString(mt() % 50));
  }

  return v;
}

std::vector<std::string> StringGenerator::getRandomVector(int size) {
  std::vector<std::string> v = std::vector<std::string>(size);
  int d = arraySize - size == 0 ? 0 : mt() % (arraySize - size);

  std::copy(random.begin() + d, random.begin() + d + size, v.begin());
  return v;
}

std::vector<std::string> StringGenerator::getReversedVector(int size) {
  std::vector<std::string> v = std::vector<std::string>(size);
  int d = arraySize - size == 0 ? 0 : mt() % (arraySize - size);

  std::copy(reversed.begin() + d, reversed.begin() + d + size, v.begin());
  return v;
}

std::vector<std::string> StringGenerator::getAlmostSortedVector(int size) {
  std::vector<std::string> v = std::vector<std::string>(size);
  int d = arraySize - size == 0 ? 0 : mt() % (arraySize - size);

  std::copy(almostSorted.begin() + d, almostSorted.begin() + d + size, v.begin());
  return v;
}

