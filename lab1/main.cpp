/**
    Разработать подпрограммы работы с приоритетной очередью.
    Постановка запросов в очередь выполняется по приоритету,
    снятие - подряд из младших адресов (начало очереди).
    Очередь организована на массиве с циклическим заполнением и списка.
    Приоритет: мах значения числового параметра, при совпадении параметров - FIFO.
**/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

#include "include/Item.h"
#include "include/PriorityQueue.h"
#include "include/PriorityQueueArr.h"

using namespace std;

/**
    TODO:
    1. Структуры.

    Отчет:
    Постановка задачи.
    Краткие теор. сведенья: термины.
    Исходный код
    Результат. Оценка времени
    Вывод

    Генерить приоритет, значения.
**/

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{
    return alphanum[rand() % stringLength];
}

int main()
{
    cout << "Write numbers of rows: ";
    int n;
    cin >> n;

    PriorityQueue<Item> queue;
    PriorityQueueArr::Queue queueArr;

    PriorityQueueArr::creat(&queueArr);

    cout << "Generated: " << endl;
    srand(time(NULL));
    int priority;
    int val;
    std::string str;
    cout << setw(6) << "Name" << setw(7) << "Value" << setw(10) << "Priority" << endl;
    for ( auto i = 0; i < n; i++ ) {
        val = i;
        str += genRandom();

        priority = 1 + rand() % 10;
        Item item(str, val);

        PriorityQueueArr::push(&queueArr, priority, val);

        cout << setw(6) << item.getName() << setw(7) << item.getValue() << setw(10)
                << priority << endl;

        queue.push(priority, item);
    }

    cout << endl << "In queue with array:" << endl;
    int value;
    cout << setw(13) << "Value" << endl;
    while ( !PriorityQueueArr::isEmpty(&queueArr) ) {
        value = PriorityQueueArr::pop(&queueArr);
        cout << setw(13) << value << endl;
    }

    cout << endl << "In queue with list:" << endl;
    Item item;
    cout << setw(6) << "Name" << setw(7) << "Value" << endl;
    while ( !queue.isEmpty() ) {
        item = queue.shift();
        cout << setw(6) << item.getName() << setw(7) << item.getValue() << endl;
    }

    return 0;
}
