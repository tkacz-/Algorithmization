#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "include/PriorityQueue.h"
#include "include/PriorityQueueArr.h"

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

    PriorityQueue<int> queue;
    PriorityQueueArr::Queue queueArr;
    PriorityQueueArr::creat(&queueArr);

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

        queue.push(priority, val);

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
    while ( !queue.isEmpty() ) {
        val = queue.shift();
        cout << setw(7) << val << endl;
    }

/** Work with array **/
    PriorityQueueArr::Queue queueArr2;
    PriorityQueueArr::creat(&queueArr2);

    clock_t timeBegin, timeEnd;
    double delta;
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

/** Work with list **/
    PriorityQueue<int> queue2;

    timeBegin = clock();
    for ( int i = 0; i < 100000; i++ ) {
        val = i;
        str += genRandom();
        priority = 1 + rand() % 10;

        queue2.push(priority, val);
    }
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << endl << "Enqueue into list: " << delta << endl;

    timeBegin = clock();
    while ( !queue2.isEmpty() ) {
        val = queue2.shift();
    }
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << "Dequeue into list: " << delta << endl;
    return 0;
}
