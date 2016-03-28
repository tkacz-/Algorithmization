#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "include/PriorityQueueArr.h"
#include "include/PriorityQue.h"

using namespace std;

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
    int n;
    cout << "Write numbers of rows: ";
    cin >> n;

    PriorityQue::Queue queue;
    PriorityQue::create(&queue);
    PriorityQueueArr::Queue queueArr;
    PriorityQueueArr::create(&queueArr);

    cout << "Generated: " << endl;
    srand(time(NULL));
    int val, priority;
    std::string str;
    cout << setw(7) << "Value" << setw(10) << "Priority" << endl;
    for ( auto i = 0; i < n; i++ ) {
        val = i;
        str += genRandom();
        priority = 1 + rand() % 10;

        PriorityQueueArr::push(&queueArr, priority, val);
        PriorityQue::push(priority, val, &queue);

        cout << setw(7) << val << setw(10) << priority << endl;
    }

    cout << endl << "In queue with array:" << endl;
    cout << setw(7) << "Value" << endl;
    while ( !PriorityQueueArr::isEmpty(&queueArr) ) {
        val = PriorityQueueArr::pop(&queueArr);
        cout << setw(7) << val << endl;
    }

    cout << endl << "In queue with list:" << endl;
    cout << setw(7) << "Value" << endl;
    while ( !PriorityQue::isEmpty(&queue) ) {
        val = PriorityQue::shift(&queue);
        cout << setw(7) << val << endl;
    }

/** Work with list **/
    PriorityQue::Queue queueList;
    PriorityQue::create(&queueList);

    clock_t timeBegin, timeEnd;
    double delta;
    timeBegin = clock();
    for ( int i = 0; i < 100000; i++ ) {
        val = i;
        str += genRandom();
        priority = 1 + rand() % 10;

        PriorityQue::push(priority, val, &queueList);
    }
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << endl << "Enqueue into list: " << delta << endl;

    timeBegin = clock();
    while ( !PriorityQue::isEmpty(&queueList) ) {
        val = PriorityQue::shift(&queueList);
    }
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << "Dequeue into list: " << delta << endl;

/** Work with array **/
    PriorityQueueArr::Queue queueArr2;
    PriorityQueueArr::create(&queueArr2);

    timeBegin = clock();
    for ( int i = 0; i < 100000; i++ ) {
        val = i;
        str += genRandom();
        priority = 1 + rand() % 10;

        PriorityQueueArr::push(&queueArr2, priority, val);
    }
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << endl << "Enqueue into array: " << delta << endl;

    timeBegin = clock();
    while ( !PriorityQueueArr::isEmpty(&queueArr2) ) {
        val = PriorityQueueArr::pop(&queueArr2);
    }
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << "Dequeue into array: " << delta << endl;
    return 0;
}

/*
    PriorityQue::Queue queueList;
    PriorityQue::create(&queueList);

    cout << setw(7) << "Value" << setw(10) << "Priority" << endl;
    for ( int i = 0; i < n; i++ ) {
        val = i;
        str += genRandom();
        priority = 1 + rand() % 10;

        PriorityQue::push(priority, val, &queueList);
        cout << setw(7) << val << setw(10) << priority << endl;
    }

    cout << endl << "In queue with LIST:" << endl;
    cout << setw(7) << "Value" << endl;
    while ( !PriorityQue::isEmpty(&queueList) ) {
        val = PriorityQue::shift(&queueList);
        cout << setw(7) << val << endl;
    }
*/
