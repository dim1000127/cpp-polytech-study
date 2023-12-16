#include <iostream>
#include <fstream>
#include <istream>
#include <vector>

char *insertNumbersAsChars(char *newStr, const char *first, const char *second);

std::string insertNumbersAsString(const std::string &first, const std::string &second);

bool isContainsAsChar(const char *source, char ch);

bool isContainsAsString(const std::string &source, char ch);

int main() {
    std::ifstream in("file.txt");
    if (!in.is_open()) {
        std::cout << "File can't be opened!\n";
        return 1;
    } else {
        while (!in.eof()) {
            char *strFirstAsChar = nullptr;
            char *strSecondAsChar = nullptr;
            char *strDestAsChar = nullptr;
            try {
                int firstLength = {};
                in >> firstLength;
                in.ignore();
                if (firstLength <= 0) {
                    continue;
                }

                strFirstAsChar = new char[firstLength + 1];
                in.getline(strFirstAsChar, firstLength + 1);

                int secondLength = {};
                in >> secondLength;
                in.ignore();

                if (secondLength <= 0) {
                    continue;
                }

                strSecondAsChar = new char[secondLength + 1];
                strDestAsChar = new char[firstLength + secondLength + 1];

                in.getline(strSecondAsChar, secondLength + firstLength + 1);

                std::string strFirst = strFirstAsChar;
                std::string strSecond = strSecondAsChar;

                std::cout << "\nChar *" << std::endl;
                std::cout << insertNumbersAsChars(strDestAsChar, strFirstAsChar, strSecondAsChar) << std::endl;

                std::cout << "\nString" << std::endl;
                std::cout << insertNumbersAsString(strFirst, strSecond) << std::endl;

                delete[] strFirstAsChar;
                delete[] strSecondAsChar;
                delete[] strDestAsChar;
            }
            catch (const std::bad_alloc &) {
                delete[] strFirstAsChar;
                delete[] strSecondAsChar;
                delete[] strDestAsChar;
                return 1;
            }
        }
    }

    in.close();
    return 0;
}

char *insertNumbersAsChars(char *newStr, const char *first, const char *second) {
    int k = 0;
    for (; first[k] != '\0'; k++) {
        newStr[k] = first[k];
    }

    for (int i = 0; second[i] != '\0'; i++) {
        if (std::isdigit(second[i]) && isContainsAsChar(first, second[i])) {
            *(newStr + k) = second[i];
            k++;
        }
    }

    *(newStr + k) = '\0';
    return newStr;
}

std::string insertNumbersAsString(const std::string &first, const std::string &second) {
    std::string resultStr = first;

    for (char i: second) {
        if (std::isdigit(i) && isContainsAsString(first, i)) {
            resultStr += i;
        }
    }

    return resultStr;
}

bool isContainsAsChar(const char *source, char ch) {
    bool isContains = false;

    for (int i = 0; source[i] != '\0'; i++) {
        if (ch == source[i]) {
            isContains = true;
            break;
        }
    }
    return isContains;
}

bool isContainsAsString(const std::string &source, char ch) {
    bool isContains = false;

    for (int i = 0; source[i] != '\0'; i++) {
        if (ch == source[i]) {
            isContains = true;
            break;
        }
    }
    return isContains;
}