#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <string>
#include <vector>
#include <list>

class PmergeMe {
public:
    std::vector<int> parseInputToList(const std::string& input);
    std::vector<std::vector<int> > splitIntoSubsequences(const std::vector<int>& elements, size_t numSubsets);
    void insertionSort(std::vector<int>& subset);
    void insertionSort(std::list<int>& subset); // Nueva sobrecarga
    std::vector<int> mergeSubsets(const std::vector<int>& subset1, const std::vector<int>& subset2);
};

#endif

