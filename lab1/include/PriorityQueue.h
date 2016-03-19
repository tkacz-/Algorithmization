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

        void push(const int& key, const Item& item) {
            Node* pNode = new Node(key, item);

            if ( !pHead ) {
                pHead = pNode;
            }
            else {
                Node* cell = pHead;
                Node* next_cell = cell->getNext();
                while (next_cell != nullptr && next_cell->getPriority() >= key) {
                    cell = next_cell;
                    next_cell = next_cell->getNext();
                }

                if ( next_cell == nullptr ) {
                    if ( cell->getPriority() >= key ) {
                        cell->setNext(pNode);
                        pNode->setNext(next_cell);
                    } else {
                        pNode->setNext(cell);
                        pHead = pNode;
                    }
                } else {
                    if ( cell == pHead ) {
                        if ( cell->getPriority() >= key ) {
                            cell->setNext(pNode);
                            pNode->setNext(next_cell);
                        } else {
                            pNode->setNext(cell);
                            pHead = pNode;
                        }
                    } else {
                        pNode->setNext(next_cell);
                        cell->setNext(pNode);
                    }
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
