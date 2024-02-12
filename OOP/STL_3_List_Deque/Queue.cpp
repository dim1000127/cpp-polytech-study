#include "Queue.h"
#include <stdexcept>

Queue::Queue() = default;

Queue::~Queue() = default;

void Queue::PutElementToQueue(const QueueElement &element, ElementPriority priority) {
    switch (priority) {
        case LOW:
            queueLow_.push_back(element);
            break;
        case NORMAL:
            queueNormal_.push_back(element);
            break;
        case HIGH:
            queueHigh_.push_back(element);
            break;
    }
}

QueueElement Queue::GetElementFromQueue() {
    if (!queueHigh_.empty())
    {
        auto front = queueHigh_.front();
        queueHigh_.pop_front();
        return front;
    }

    if (!queueNormal_.empty())
    {
        auto front = queueNormal_.front();
        queueNormal_.pop_front();
        return front;
    }

    if (!queueLow_.empty())
    {
        auto front = queueLow_.front();
        queueLow_.pop_front();
        return front;
    }

    throw std::runtime_error("Error!");
}

void Queue::Accelerate() {
    if (!queueLow_.empty())
    {
        auto firstIterator = queueLow_.begin();
        auto lastIterator = queueLow_.end();

        for (auto i = firstIterator; i < lastIterator; i++)
        {
            queueHigh_.push_back(*i);
        }
    }
}
