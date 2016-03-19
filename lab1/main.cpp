#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

#include "include/Item.h"
#include "include/PriorityQueue.h"

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

    cout << "Generated: " << endl;
    srand(time(NULL));
    int priority;
    int val;
    std::string str;
    cout << setw(6) << "Name" << setw(7) << "Value" << setw(10) << "Priority" << endl;
    for ( auto i = 0; i < n; i++ ) {
        val = 1 + rand() % 10;
        str += genRandom();

        priority = 1 + rand() % 10;
        Item item(str, val);

        cout << setw(6) << item.getName() << setw(7) << item.getValue() << setw(10)
                << priority << endl;

        queue.push(priority, item);
    }

    cout << endl << "In queue:" << endl;
    Item item;
    cout << setw(6) << "Name" << setw(7) << "Value" << endl;
    while ( !queue.isEmpty() ) {
        item = queue.shift();
        cout << setw(6) << item.getName() << setw(7) << item.getValue() << endl;
    }

    return 0;
}
