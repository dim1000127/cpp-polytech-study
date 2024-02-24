//Автор: Лебедев Дмитрий
//Группа: b5130904/20021


//1.	Прочитать содержимое текстового файла. Файл может содержать:
//        a.	Слова – состоят из латинских строчных и заглавных букв, а также цифр, длинна слова должна быть не
//        более 20 символов
//        b.	Знаки препинания – «.», «,» «!» «?» «:» «;»
//        c.	Пробельные символы – пробел, табуляция, символ новой строки.

//2.	Отформатировать текст следующим образом:
//      a.	Не должно быть  пробельных символов отличных от пробела
//      b.	Не должно идти подряд более одного пробела
//      c.	Между словом и знаком препинания не должно быть пробела
//      d.	После знака препинания всегда должен идти пробел
//      e.	Слова длиной более 10 символов заменяются на слово «Vau!!!»

//3.	Преобразовать полученный текст в набор строка, каждая из которых содержит целое количество строк (слово должно
// целиком находиться в строке) и ее длинна не превышает 40 символов.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

void removeWhitespaces(std::string &str) {
    //remove whitespaces
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) {
        return c == '\n' || c == '\t';
    }), str.end());
}

void removeDuplicateSpace(std::string &str) {
    str.erase(std::unique(str.begin(), str.end(), [](char c, char b) {
        return std::isspace(c) && std::isspace(b);
    }), str.end());
}

void removeSpaceBetweenWordAndPunctuationMarks(std::string &str) {
    const std::string marks = ",.!?:;";

    std::size_t position{};

    while ((position = str.find_first_of(marks, position)) != std::string::npos) {
        if (position > 0 && str[position - 1] == ' ') {
            str.erase(position - 1, 1);
        }
        position++;
    }
}

void insertSpaceAfterPunctuationMarks(std::string &str) {
    const std::string marks = ",.!?:;";

    for (char mark: marks) {
        auto position = str.find_first_of(mark);
        while (position != std::string::npos) {
            str.insert(position + 1, " ");
            position = str.find_first_of(marks, position + 2);
        }
    }
}

void replaceWords(std::string &str) {
    const int MAX_WORD_LENGTH = 10;
    std::string separators = " ,.!?:;";
    std::string replacement = "Vau!!!";

    size_t from = 0, to;
    size_t length;
    while (from < str.length()) {
        to = str.find_first_of(separators, from);
        if (to == std::string::npos) {
            to = str.length() - 1;
        }
        length = to - from;
        if (length > MAX_WORD_LENGTH) {
            str.replace(from, length, replacement);
            from += replacement.length() + 1;
        } else {
            from = to + 1;
        }
    }
}

std::vector<std::string> transformIntoLines(const std::string &str) {
    const int MAX_LINE_LENGTH = 40;

    std::istringstream stream{str};
    std::vector<std::string> lines;
    std::string line;
    std::string word;
    size_t lineLength = 0;

    while (stream >> word) {
        if (lineLength + word.size() + 1 > MAX_LINE_LENGTH) {
            lines.push_back(line);
            line = word + " ";
        } else {
            line += word + " ";
        }
        lineLength = line.length();
    }

    lines.push_back(line);

    return lines;
}

int main() {
    std::ifstream in("file.txt");
    if (!in.is_open()) {
        std::cout << "File can't be opened!\n";
        in.close();
        return 1;
    } else {
        std::string fileContent;

        getline(in, fileContent, '\0');

        std::cout << "Source string" << std::endl;
        std::cout << fileContent << std::endl;
        std::cout << std::endl;

        std::cout << "String after remove whitespaces" << std::endl;
        removeWhitespaces(fileContent);
        std::cout << fileContent << std::endl;

        std::cout << "String after insert space after marks" << std::endl;
        insertSpaceAfterPunctuationMarks(fileContent);
        std::cout << fileContent << std::endl;
        std::cout << std::endl;

        std::cout << "String after remove duplicate spaces" << std::endl;
        removeDuplicateSpace(fileContent);
        std::cout << fileContent << std::endl;
        std::cout << std::endl;

        std::cout << "String after remove space between word and marks" << std::endl;
        removeSpaceBetweenWordAndPunctuationMarks(fileContent);
        std::cout << fileContent << std::endl;
        std::cout << std::endl;

        std::cout << "String after replace long words" << std::endl;
        replaceWords(fileContent);
        std::cout << fileContent << std::endl;
        std::cout << std::endl;

        std::vector<std::string> lines = transformIntoLines(fileContent);
        for(const std::string &line : lines){
            std::cout << line << std::endl;
        }
        std::cout << std::endl;
    }
    in.close();

    return 0;
}
