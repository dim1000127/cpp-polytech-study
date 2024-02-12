#include <iostream>
#include "queue.h"


int main() {
    auto *queue = new Queue();

    queue->PutElementToQueue({.name = "Dima"},LOW);
    queue->PutElementToQueue({.name = "Dasha"}, NORMAL);
    queue->PutElementToQueue({.name = "Egor"}, HIGH);

    queue->Accelerate();

    std::cout << queue->GetElementFromQueue().name << std::endl;

    std::cout << queue->GetElementFromQueue().name << std::endl;

    queue->PutElementToQueue({.name = "Dima"}, HIGH);

    std::cout << queue->GetElementFromQueue().name << std::endl;

    return 0;
}
