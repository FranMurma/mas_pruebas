#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>
#include <stdexcept>

std::vector<int> PmergeMe::parseInputToList(const std::string& input) {
    std::vector<int> result;
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        if (num >= 0)
            result.push_back(num);
        else
            throw std::runtime_error("Negatives are not allowed");
    }
    if (!iss.eof()) {
        throw std::runtime_error("Invalid expression");
    }
    return result;
}

std::vector<std::vector<int> > PmergeMe::splitIntoSubsequences(const std::vector<int>& elements, size_t numSubsets) {
    std::vector<std::vector<int> > subsets;
    size_t subsetSize = elements.size() / numSubsets;
    size_t remainingElements = elements.size() % numSubsets;

    std::vector<int>::const_iterator it = elements.begin();
    for (size_t i = 0; i < numSubsets; ++i) {
        size_t subsetLength = subsetSize;
        if (remainingElements > 0) {
            subsetLength++;
            remainingElements--;
        }
        std::vector<int> subset(it, it + subsetLength);
        subsets.push_back(subset);
        it += subsetLength;
    }
    return subsets;
}

void PmergeMe::insertionSort(std::vector<int>& subset) {
    std::sort(subset.begin(), subset.end());
}

void PmergeMe::insertionSort(std::list<int>& subset) {
    subset.sort();
}

std::vector<int> PmergeMe::mergeSubsets(const std::vector<int>& subset1, const std::vector<int>& subset2) {
    std::vector<int> mergedSubset;
    mergedSubset.reserve(subset1.size() + subset2.size());
    
    std::merge(subset1.begin(), subset1.end(), subset2.begin(), subset2.end(), std::back_inserter(mergedSubset));
    return mergedSubset;
}

