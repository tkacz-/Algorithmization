#ifndef PRIORITYQUE_H_INCLUDED
#define PRIORITYQUE_H_INCLUDED

#include <iostream>
namespace PriorityQue {
    struct Node {
        int priority;
        int item;
        Node* next;
    };

    struct Queue {
        Node* pHead;
        Node* pTail;
        long int size;
    };

    void create(Queue *q) {
        q->pHead = q->pTail = nullptr;
        q->size = 0;
    }

    void deleteQueue(Queue *q) {
        while ( q->pHead ) {
            q->pTail = q->pHead->next;
            delete q->pHead;
            q->pHead = q->pTail;
        }
    }

    bool isEmpty (Queue *q) {
        return ! q->pHead;
    }

    void push (const int& key, const int& item, Queue* q) {
        Node* pNode = new Node;
        pNode->priority = key;
        pNode->item = item;
        pNode->next = nullptr;

        int i = 0;
        if ( isEmpty(q) )
            q->pHead = q->pTail = pNode;
        else {
            Node* next_cell = q->pHead;
            Node* cell = q->pHead;

            while ( next_cell != nullptr ) {
                if ( i == 1 ) {
                    if ( key > next_cell->priority ) {
                        pNode->next = next_cell;
                        cell->next = pNode;
                        return;
                    }
                    cell = cell->next;
                } else {
                    if ( key > next_cell->priority ) {
                        pNode->next = next_cell;
                        q->pHead = pNode;
                        return;
                    }
                }
                next_cell = next_cell->next;
                i = 1;
            }
            if ( next_cell == nullptr ) {
                q->pTail->next = pNode;
                q->pTail = pNode;
            }
        }
    }

    int shift(Queue* q) {

        int ret = q->pHead->item;
        Node* pNext = q->pHead->next;

        delete q->pHead;
        q->pHead = pNext;

        return ret;
    }

};

#endif // PRIORITYQUE_H_INCLUDED
