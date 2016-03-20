#ifndef PRIORITYQUEUEARR_H_INCLUDED
#define PRIORITYQUEUEARR_H_INCLUDED

#include <iostream>

namespace PriorityQueueArr {
    const int n = 8;
    struct Queue {
        int data[n];
        int priority[n] = {-1};
        int head, tail;
    };

    void creat(Queue *q) {
        q->head = q->tail = 1;
    }

    bool isEmpty (Queue *q) {
        if ( q->tail == q->head )
            return true;
        else
            return false;
    }

    void push (Queue *q, int key, int value) {
        if ( ( q->tail % ( n - 1 ) ) + 1 == q->head )
            std::cout << "Error with array: Queue is full!" << std::endl;
        else {
            int i = 0;                      /** flag - insert the item between items **/
            if ( isEmpty(q) ) {
                q->data[q->tail] = value;
                q->priority[q->tail] = key;
                q->tail = ( q->tail % ( n - 1 ) ) + 1;
            } else {
                int next_cell = q->head;    /** point to next item **/
                int cell = q->head;         /** point to previous item **/

                while ( next_cell != q->tail ) {
                    if ( i == 1 ) {
                        if ( key >= q->priority[next_cell] ) {
                            for ( int j = ( q->tail % ( n - 1 ) ) + 1; j > next_cell; j-- ) {
                                q->data[j] = q->data[j - 1];
                                q->priority[j] = q->priority[j - 1];
                            }
                            q->data[next_cell] = value;
                            q->priority[next_cell] = key;
                            q->tail = ( q->tail % ( n - 1 ) ) + 1;
                            return;
                        }
                        cell++;
                    } else {
                        if ( key >= q->priority[next_cell] ) {
                            for ( int j = ( q->tail % ( n - 1 ) ) + 1; j > q->head; j-- ) {
                                q->data[j] = q->data[j - 1];
                                q->priority[j] = q->priority[j - 1];
                            }
                            q->data[q->head] = value;
                            q->priority[q->head] = key;
                            q->tail = ( q->tail % ( n - 1 ) ) + 1;
                            return;
                       }
                    }
                    next_cell++;
                    i = 1;
                }
                if ( next_cell == q->tail ) {
                    q->data[q->tail] = value;
                    q->priority[q->tail] = key;
                    q->tail = ( q->tail % ( n - 1 ) ) + 1;
                }
            }
        }
    }

    int pop(Queue *q) {
        int item = q->data[q->head];
        q->head = ( q->head % ( n - 1 ) ) + 1;
        return item;
    }

    int top(Queue *q) {
        return q->data[q->head];
    }

    int size(Queue *q) {
        if ( q->head > q->tail )
            return ( n - 1 ) - ( q->head - q->tail );
        else
            return q->tail - q->head;
    }
}

#endif // PRIORITYQUEUEARR_H_INCLUDED
