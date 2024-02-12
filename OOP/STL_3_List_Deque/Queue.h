#ifndef STL_3_LIST_DEQUE_QUEUE_H
#define STL_3_LIST_DEQUE_QUEUE_H

#include <string>
#include <deque>

typedef enum
{
    LOW,
    NORMAL,
    HIGH
} ElementPriority;

typedef struct
{
    std::string name;
} QueueElement;

class Queue
{
public:
    // Конструктор, создает пустую очередь
    Queue();

    // Деструктор
    ~Queue();

    // Добавить в очередь элемент element с приоритетом priority
    void PutElementToQueue(const QueueElement& element, ElementPriority priority);

    // Получить элемент из очереди
    // метод должен возвращать элемент с наибольшим приоритетом, который был
    // добавлен в очередь раньше других
    QueueElement GetElementFromQueue();

    // Выполнить акселерацию
    void Accelerate();

private:
    std::deque<QueueElement> queueLow_;
    std::deque<QueueElement> queueNormal_;
    std::deque<QueueElement> queueHigh_;
};


#endif
