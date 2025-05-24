//
// Created by Алексей on 22.05.2025.
//

#include "StringSortTester.h"

double StringSortTester::measureTime(
    const std::vector<std::string> &v,
    std::function<void(std::vector<std::string>&, int, int, int, long long&)> F,
    long long &comparisons) {
  auto v_copy = v;
  auto start = std::chrono::high_resolution_clock::now();
  F(v_copy, 0, v.size() - 1, 0, comparisons);
  auto end = std::chrono::high_resolution_clock::now();
  return std::chrono::duration<double, std::milli>(end - start).count();
}

std::pair<double, int> StringSortTester::getTimeAndComparisons(
    const std::vector<std::string> &v,
    std::function<void(std::vector<std::string>&, int, int, int, long long&)> f) {
  std::vector<double> times(10);
  long long comparisons;
  for (int i = 0; i < 10; ++i){
    comparisons = 0;
    times[i] = measureTime(v, f, comparisons);
  }

  std::sort(times.begin(), times.end());

  return {(times[4] + times[5] + times[6]) / 3, comparisons};
}

void StringSortTester::Experiment(const std::string &algorithm) {
  std::ofstream reversedFile("..\\results\\" + algorithm + "_reversed.csv");
  std::ofstream randomFile("..\\results\\" + algorithm + "_random.csv");
  std::ofstream almostSortedFile("..\\results\\" + algorithm + "_almostSorted.csv");

  reversedFile << "Size,Time(ms),Comparisons\n";
  randomFile << "Size,Time(ms),Comparisons\n";
  almostSortedFile << "Size,Time(ms),Comparisons\n";

  std::function<void(std::vector<std::string>&, int, int, int, long long&)> sort;

  if (algorithm == "QuickSort") {
    sort = QuickSort;
  }
  else if (algorithm == "MergeSort") {
    sort = MergeSort;
  }
  else if (algorithm == "StringMergeSort") {
    sort = StringMergeSort;
  }
  else if (algorithm == "TernaryQuickSort") {
    sort = ternarySort;
  }
  else if (algorithm == "MSDRadixSort") {
    sort = MSDRadixSort;
  }
  else if (algorithm == "MSDRadixQuickSort") {
    sort = MSDRadixQuickSort;
  }
  else if (algorithm == "OptimizedMSDRadixSort") {
    sort = OptimizedMSDRadixSort;
  }
  else if (algorithm == "OptimizedMSDRadixQuickSort") {
    sort = OptimizedMSDRadixQuickSort;
  }


  auto stringGenerator = StringGenerator();
  for (int i = 100; i <= 3000; i += 100){
    std::cout << algorithm << ' ' << i << '\n';
    auto v = stringGenerator.getAlmostSortedVector(i);
    auto pair = getTimeAndComparisons(v, sort);
    almostSortedFile << i << ',' << pair.first << ',' << pair.second << '\n';

    v = stringGenerator.getReversedVector(i);
    pair = getTimeAndComparisons(v, sort);
    reversedFile << i << ',' << pair.first << ',' << pair.second << '\n';

    v = stringGenerator.getRandomVector(i);
    pair = getTimeAndComparisons(v, sort);
    randomFile << i << ',' << pair.first << ',' << pair.second << '\n';
  }

  reversedFile.close();
  randomFile.close();
  almostSortedFile.close();
}

void StringSortTester::ConductExperiments() {
  std::vector<std::string> algorithms = {"QuickSort",
                                         "MergeSort",
                                         "StringMergeSort",
                                         "TernaryQuickSort",
                                         "MSDRadixSort",
                                         "MSDRadixQuickSort"};

//  std::vector<std::string> algorithms = {"OptimizedMSDRadixSort",
//                                         "OptimizedMSDRadixQuickSort"};

  for (auto alg : algorithms){
    Experiment(alg);
  }
}