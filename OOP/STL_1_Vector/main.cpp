//Автор: Лебедев Дмитрий
//Группа: b5130904/20021

//1)	Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя оператор operator[].

//2)	Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя метод at().

//3)	Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя для доступа
// к содержимому вектора только итераторы. Для работы с итераторами допустимо использовать только операторы получения
//текущего элемента и перехода в следующему (подсказка, можно сохранять копию итератора указывающего на некоторый элемент).

//4)	Прочитайте во встроенный массив С содержимое текстового файлы,
// скопируйте данные в вектор одной строкой кода (без циклов и алгоритмов STL)

//5)	Напишите программу, сохраняющую в векторе числа, полученные из стандартного ввода
// (окончанием ввода является число 0). Удалите все элементы, которые делятся на 2 (не используете стандартные
// алгоритмы STL), если последнее число 1. Если последнее число 2, добавьте после каждого числа которое
// на 3 три единицы.

//6)	Напишите функцию void fillRandom(double* array, int size) заполняющую массив случайными значениями
// в интервале от -1.0 до 1.0. Заполните с помощью заданной функции вектора размером 5,10,25,50,100 и отсортируйте
// его содержимое (с помощью любого разработанного ранее алгоритма модифицированного для сортировки действительных чисел)

#include <random>
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <algorithm>
#include <chrono>

void printVector(const std::vector<int> &vector) {
    for (int i: vector)
        std::cout << i << ' ';

    std::cout << std::endl;
}

void printVector(const std::vector<double> &vector) {
    for (double i: vector)
        std::cout << i << ' ';

    std::cout << std::endl;
}

void printVector(const std::vector<char> &vector) {
    for (int i: vector)
        std::cout << i << ' ';

    std::cout << std::endl;
}

void fillRandom(double *array, int size){
    std::srand(std::time(nullptr));

    for (int i = 0; i < size; ++i) {
        array[i] = (std::rand() % 20 - 10) * 0.1;
    }
}

void sort(double *array, int size)
{
    double temp{};

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (array[j + 1] < array[j]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int VECTOR_SIZE = 5000;

    std::vector<int> vectorOfInt(VECTOR_SIZE);

    // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine{rnd_device()};  // Generates random integers
    std::uniform_int_distribution<int> dist{-52, 52};

    auto gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };

    generate(begin(vectorOfInt), end(vectorOfInt), gen);

    std::vector<int> vectorOfIntForAt(vectorOfInt.begin(), vectorOfInt.end());
    std::vector<int> vectorOfIntForIterator(vectorOfInt.begin(), vectorOfInt.end());
    std::vector<int> vectorOfIntBySort(vectorOfInt.begin(), vectorOfInt.end());

    int temp{};

    //1. Sort by using operator[]
    temp = 0;

    //std::cout << std::endl;
    //std::cout << "Before: sort by using operator[]" << std::endl;
    //printVector(vectorOfInt);

    auto startTimeSortByOperator = std::chrono::steady_clock::now();

    for (int i = 0; i < vectorOfInt.size(); ++i) {
        for (int j = 0; j < vectorOfInt.size() - 1; ++j) {
            if (vectorOfInt[j + 1] < vectorOfInt[j]) {
                temp = vectorOfInt[j];
                vectorOfInt[j] = vectorOfInt[j + 1];
                vectorOfInt[j + 1] = temp;
            }
        }
    }

    auto endTimeSortByOperator = std::chrono::steady_clock::now();
    auto elapsedNsSortByOperator = std::chrono::duration_cast<std::chrono::nanoseconds>(
            endTimeSortByOperator - startTimeSortByOperator);

    //std::cout << std::endl;
    //std::cout << "After: sort by using operator[]" << std::endl;
    //printVector(vectorOfInt);

    //2. Sort by using at()
    temp = 0;

    //std::cout << std::endl;
    //std::cout << "Before: sort by using at" << std::endl;
    //printVector(vectorOfIntForAt);

    auto startTimeSortByAt = std::chrono::steady_clock::now();

    for (int i = 0; i < vectorOfIntForAt.size(); ++i) {
        for (int j = 0; j < vectorOfIntForAt.size() - 1; ++j) {
            if (vectorOfIntForAt.at(j + 1) < vectorOfIntForAt.at(j)) {
                temp = vectorOfIntForAt.at(j);
                vectorOfIntForAt.at(j) = vectorOfIntForAt.at(j + 1);
                vectorOfIntForAt.at(j + 1) = temp;
            }
        }
    }

    auto endTimeSortByAt = std::chrono::steady_clock::now();
    auto elapsedNsSortByAt = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeSortByAt - startTimeSortByAt);

    //std::cout << std::endl;
    //std::cout << "After: sort by using at" << std::endl;
    //printVector(vectorOfIntForAt);

    //3. Sort by using iterator()

    //std::cout << std::endl;
    //std::cout << "Before: sort by using at" << std::endl;
    //printVector(vectorOfIntForIterator);

    auto tempIterator = vectorOfIntForIterator.begin();
    auto firstIterator = vectorOfIntForIterator.begin();
    auto lastIterator = vectorOfIntForIterator.end();

    auto startTimeSortByIterator = std::chrono::steady_clock::now();

    while (firstIterator < --lastIterator) {
        for (auto i = firstIterator; i < lastIterator; i++) {
            if (*(i + 1) < *i) {
                tempIterator = i;
                i = i + 1;
                i + 1 = tempIterator;
                //std::iter_swap(i, i + 1);
            }
        }
    }

    auto endTimeSortByIterator = std::chrono::steady_clock::now();
    auto elapsedNsSortByIterator = std::chrono::duration_cast<std::chrono::nanoseconds>(
            endTimeSortByIterator - startTimeSortByIterator);

    //std::cout << std::endl;
    //std::cout << "After: sort by using at" << std::endl;
    //printVector(vectorOfIntForIterator);

    //Sort by built-in function
    auto startTimeSortBySort = std::chrono::steady_clock::now();
    std::sort(vectorOfIntBySort.begin(), vectorOfIntBySort.end());

    auto endTimeSortBySort = std::chrono::steady_clock::now();
    auto elapsedNsSortBySort = std::chrono::duration_cast<std::chrono::nanoseconds>(
            endTimeSortBySort - startTimeSortBySort);

    std::cout << "Sort by operator[] time : " << elapsedNsSortByOperator.count() << " ns" << std::endl;
    std::cout << "Sort by at time : " << elapsedNsSortByAt.count() << " ns" << std::endl;
    std::cout << "Sort by iterator time : " << elapsedNsSortByIterator.count() << " ns" << std::endl;
    std::cout << "Sort by sort built-in function : " << elapsedNsSortBySort.count() << " ns" << std::endl;


    //4. Read from file
    std::ifstream in("file.txt");
    if (!in.is_open()) {
        std::cout << "File can't be opened!\n";
        in.close();
        return 1;
    } else {
        char charArr[VECTOR_SIZE];

        in.read(charArr, VECTOR_SIZE);

        //std::cout << charArr;

        std::vector<char> charVector(charArr, &charArr[sizeof(charArr) - 1]);
        //printVector(charVector);
    }
    in.close();

    //5. Input in vector
    std::vector<int> values;
    std::cout << "Enter number:\t";
    int value{};
    while ((std::cin >> value) && value != 0) {
        values.push_back(value);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    auto lastValue = values.end() - 1;

    if (*lastValue == 1) {
        for (int i = 0; i < values.size();) {
            if (values[i] % 2 == 0) {
                values.erase(values.begin() + i);
            } else {
                i++;
            }
        }
    }

    if (*lastValue == 2) {
        for (int i = 0; i < values.size(); i++) {
            if (values[i] % 3 == 0) {
                values.insert(values.begin() + i + 1, 3, 1);
            }
        }
    }

    printVector(values);

    //6. fillRandom
    std::vector<double> vector5(5);
    std::vector<double> vector10(10);
    std::vector<double> vector25(25);
    std::vector<double> vector50(50);
    std::vector<double> vector100(100);

    fillRandom(&vector5[0], vector5.size());
    fillRandom(&vector10[0], vector10.size());
    fillRandom(&vector25[0], vector25.size());
    fillRandom(&vector50[0], vector50.size());
    fillRandom(&vector100[0], vector100.size());

    sort(&vector5[0], vector5.size());
    sort(&vector10[0], vector10.size());
    sort(&vector25[0], vector25.size());
    sort(&vector50[0], vector50.size());
    sort(&vector100[0], vector100.size());

    printVector(vector5);

    return 0;
}
