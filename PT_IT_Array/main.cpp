#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <ctime>


bool hasEqualElements(const int *array, int firstIndex, int secondIndex);

int main() {
    const int N_FOO_ARRAY = 10;
    int foo[N_FOO_ARRAY]{1, 2, 4, 4, 4};
    int bar[]{1, 1, 0, 0};

    std::cout << "Static array #1:";
    if (hasEqualElements(foo, 0, 3)) {
        std::cout << "\tHas duplicates" << std::endl;
    } else {
        std::cout << "\tNo duplicates" << std::endl;
    }

    std::cout << "Static array #2:";
    if (hasEqualElements(bar, 0, 1)) {
        std::cout << "\tHas duplicates" << std::endl;
    } else {
        std::cout << "\tNo duplicates" << std::endl;
    }

    std::cout << std::endl;

    int nDynArray;

    std::cout << "Enter number of elements of future array:";
    while (!(std::cin >> nDynArray) || nDynArray < 1) {
        std::cout << "Enter number of elements of future array:";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::srand(std::time(nullptr));

    int *dynArray = new int[nDynArray];

    int min = 0;
    int max = 10;

    for (int i = 0; i < nDynArray; ++i) {
        dynArray[i] = min + std::rand() % (max - min + 1);
    }

    std::cout << "Elements of dynamic array:";
    for (int i = 0; i < nDynArray; ++i) {
        std::cout << " " << dynArray[i];
    }
    std::cout << std::endl << std::endl;

    int firstIndex;

    std::cout << "Enter valid first index:\t";
    while (!(std::cin >> firstIndex) || firstIndex < 0 || firstIndex > nDynArray - 1) {
        std::cout << "Enter valid first index:\t";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << std::endl;

    int secondIndex;

    std::cout << "Enter valid second index:\t";
    while (!(std::cin >> secondIndex) || secondIndex < 0 || secondIndex > nDynArray - 1) {
        std::cout << "Enter valid second index:\t";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "Dynamic array:";
    if (hasEqualElements(dynArray, firstIndex, secondIndex)) {
        std::cout << "\tHas duplicates" << std::endl;
    } else {
        std::cout << "\tNo duplicates" << std::endl;
    }

    delete[] dynArray;
}

bool hasEqualElements(const int *array, int firstIndex, int secondIndex) {

    bool hasDuplicate = false;

    if (firstIndex > secondIndex) {
        int temp = firstIndex;
        firstIndex = secondIndex;
        secondIndex = temp;
    }

    for (int i = firstIndex; i <= secondIndex; i++) {
        for (int j = i + 1; j <= secondIndex; j++) {
            if (array[i] == array[j]) {
                hasDuplicate = true;
                break;
            }
        }
        if (hasDuplicate) {
            break;
        }
    }

    return hasDuplicate;
}
