#include <iostream>
#include <list>
#include <ctime>
#include "queue.h"


int main() {
    const int LIST_COUNT = 15;

    auto *queue = new Queue();

    queue->PutElementToQueue({.name = "Dima"},LOW);
    queue->PutElementToQueue({.name = "Dasha"}, NORMAL);
    queue->PutElementToQueue({.name = "Egor"}, HIGH);

    queue->Accelerate();

    std::cout << queue->GetElementFromQueue().name << std::endl;

    std::cout << queue->GetElementFromQueue().name << std::endl;

    queue->PutElementToQueue({.name = "Dima"}, HIGH);

    std::cout << queue->GetElementFromQueue().name << std::endl;

    std::list<int> values;

    std::srand(std::time(nullptr));

    for (int i = 0; i < LIST_COUNT; i++) {
        values.push_back(std::rand() % 20 + 1);
    }

    std::cout << "Source list" << std::endl;

    for (auto value : values){
        std::cout << value << " ";
    }

    std::cout << std::endl;

    std::cout << "List is certain order" << std::endl;
    auto begin = values.begin();
    auto end = values.end();

    while (begin != end){
        std::cout << *begin << " ";
        end--;
        if (begin != end){
            std::cout << *end << " ";
        }else{
            break;
        }
        begin++;
    }

    return 0;
}
