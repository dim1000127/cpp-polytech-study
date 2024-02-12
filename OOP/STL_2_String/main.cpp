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

std::string remove(std::string &str, std::string const &whitespace) {
    auto start = str.find_first_of(whitespace);
    auto end = str.find_last_of(whitespace);

    while (end < str.size()) {
        if ((start == std::string::npos)
            || (end == std::string::npos))
            return str;

        str = std::string(str, start, end - start + 1);
        start = str.find_first_of(whitespace);
        end = str.find_last_of(whitespace);
    }
    return str;
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
        std::cout << "String after formatting" << std::endl;
        remove(fileContent, "\f\n\r\t\v");
        std::cout << fileContent << std::endl;

    }
    in.close();

    return 0;
}
