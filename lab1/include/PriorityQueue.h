#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdexcept>
#include <iostream>

template <class Item>
class PriorityQueue
{
private:
    class Node {
    private:
        int priority;
        Item item;
        Node* next;
    public:
        Node(const int& key, const Item& i): item(i), next(0), priority(key) {}
        Node() {}
        Item getItem() const {
            return item;
        }
        int getPriority() const {
            return priority;
        }
        Node* getNext() const {
            if (next != nullptr)
                return next;
            else
                return nullptr;
        }
        void setNext(Node* node) {
            next = node;
        }
    };

    Node* pHead;
    Node* pTail;
    long int queue_size;

    public:
        PriorityQueue() : pHead(0), pTail(0), queue_size(0) {}
        ~PriorityQueue() {
            while ( pHead ) {
                pTail = pHead->getNext();
                delete pHead;
                pHead = pTail;
            }
        }

        int size() const {
            return size;
        }

        bool isEmpty() const {
            return ! pHead;
        }

        void push (const int& key, const Item& item) {
            Node *pNode = new Node(key, item);

            int i = 0;                      /** flag - insert the item between items **/
            if ( isEmpty() )
                pHead = pTail = pNode;
            else {
                Node *next_cell = pHead;    /** point to next item **/
                Node *cell = pHead;         /** point to previous item **/

                while ( next_cell != nullptr ) {
                    if ( i == 1 ) {
                        if ( key > next_cell->getPriority() ) {
                            pNode->setNext(next_cell);
                            cell->setNext(pNode);
                            return;
                        }
                        cell = cell->getNext();
                    } else {
                        if ( key > next_cell->getPriority() ) {
                            pNode->setNext(next_cell);
                            pHead=pNode;
                            return;
                       }
                    }
                    next_cell = next_cell->getNext();
                    i = 1;
                }
                if ( next_cell == nullptr ) {
                    pTail->setNext(pNode);
                    pTail = pNode;
                }
            }
        }

        Item shift() {
            if ( isEmpty() )
                throw std::runtime_error("Empty queue!");

            Item ret = pHead->getItem();
            Node* pNext = pHead->getNext();

            delete pHead;
            pHead = pNext;

            return ret;
        }
};

#endif // PRIORITYQUEUE_H
