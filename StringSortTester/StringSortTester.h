#ifndef STRINGSORTTESTER
#define STRINGSORTTESTER


#include "..\quickSort\quickSort.h"
#include "..\mergeSort\mergeSort.h"
#include "..\stringMergeSort\stringMergeSort.h"
#include "..\ternaryQuickSort\ternaryQuickSort.h"
#include "..\MSDRadixSort\MSDRadixSort.h"
#include "..\MSDRadixQuickSort\MSDRadixQuickSort.h"

#include "..\OptimizedMSDRadixSort\OptimizedMSDRadixSort.h"
#include "..\OptimizedMSDRadixQuickSort\OptimizedMSDRadixQuickSort.h"

#include "..\StringGenerator\StringGenerator.h"

#include <functional>
#include <fstream>
#include <chrono>

class StringSortTester {
 public:
  // Замеряет время сортировки на одном массиве
  double measureTime(const std::vector<std::string> &v,
                     std::function<void(std::vector<std::string>&, int, int, int, long long&)> f,
                     long long &comparisons);

  std::pair<double, int> getTimeAndComparisons(
      const std::vector<std::string> &v, std::function<void(std::vector<std::string>&, int, int, int, long long&)> f);

  void Experiment(const std::string &algorythm);

  void ConductExperiments();
};

#endif //STRINGSORTTESTER
