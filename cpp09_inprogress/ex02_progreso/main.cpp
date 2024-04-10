#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib> // para atoi

#include "PmergeMe.hpp" // Incluye el encabezado de tu clase PmergeMe

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive_integer_sequence>" << std::endl;
        return 1;
    }

    std::string input;
    for (int i = 1; i < argc; ++i) {
        input += argv[i];
        if (i < argc - 1) {
            input += " ";
        }
    }

    PmergeMe pmergeMe; // Crea una instancia de la clase PmergeMe

    // Parsea la entrada y obtiene el vector de elementos
    std::vector<int> sequenceList = pmergeMe.parseInputToList(input);

    // Copia los elementos a una lista
    std::list<int> sequenceListCopy(sequenceList.begin(), sequenceList.end());

    // Medición del tiempo de procesamiento usando vector
    clock_t startVector = clock();
    pmergeMe.insertionSort(sequenceList);
    clock_t endVector = clock();
    double durationVector = double(endVector - startVector) / CLOCKS_PER_SEC * 1000000; // En microsegundos

    // Medición del tiempo de procesamiento usando lista
    clock_t startList = clock();
    pmergeMe.insertionSort(sequenceListCopy);
    clock_t endList = clock();
    double durationList = double(endList - startList) / CLOCKS_PER_SEC * 1000000; // En microsegundos

    // Imprime los elementos antes de ordenarlos
    std::cout << "Before: " << input << std::endl;

    // Imprime los elementos ordenados usando vector
    std::cout << "After (Vector): ";
    for (std::vector<int>::iterator it = sequenceList.begin(); it != sequenceList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Imprime los elementos ordenados usando lista
    std::cout << "After (List): ";
    for (std::list<int>::iterator it = sequenceListCopy.begin(); it != sequenceListCopy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Imprime el tiempo de procesamiento usando vector
    std::cout << "Time to process a range of " << sequenceList.size() << " elements with vector: " << durationVector << " us" << std::endl;

    // Imprime el tiempo de procesamiento usando lista
    std::cout << "Time to process a range of " << sequenceList.size() << " elements with list: " << durationList << " us" << std::endl;

    return 0;
}

