#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>

const int TABLE_SIZE = 27;

template <class T>
class HashMap
{
public:
    HashMap() {
        table = new Node* [TABLE_SIZE];
        for ( int i = 0; i < TABLE_SIZE; i++ ) {
            table[i] = nullptr;
        }
    }

    ~HashMap() {
        for ( int i = 0; i < TABLE_SIZE; i++ ) {
            while ( table[i] != nullptr ) {
                Node* temp = table[i]->getNext();
                delete table[i];
                table[i] = temp;
            }
        }
        delete[] table;
    }

    void put( int key, T value ) {
        int hashCode = hash( key );
        while ( table[hashCode] != nullptr && table[hashCode]->getKey() != key ) {
            hashCode = hash( key + 1 );
        }

        Node *temp = new Node(key, value);
        if ( table[hashCode] != nullptr ) {
            temp->setNext(table[hashCode]);
            table[hashCode] = temp;
        } else {
            table[hashCode] = temp;
        }
    }

    T get( int key ) {
        int hashCode = hash( key );
        while ( table[hashCode] != nullptr && table[hashCode]->getKey() != key ) {
            hashCode = hash( key + 1 );
        }
        if ( table[hashCode] == nullptr ) {
            return "Not found";
        } else {
            return table[hashCode]->getValue();
        }
    }
private:
    class Node {
    private:
        int key_;
        T value_;
        Node* next_;
    public:
        Node(const int& key, const T& value):
            key_(key),
            value_(value),
            next_(0)
        {}
        Node() {}
        T getValue() const {
            return value_;
        }
        int getKey() const {
            return key_;
        }
        Node* getNext() const {
            if (next_ != nullptr)
                return next_;
            else
                return nullptr;
        }
        void setNext(Node* node) {
            next_ = node;
        }
    };

    Node **table;

    int hash( int key ) {
        return key % TABLE_SIZE;
    }
};

#endif // HASHMAP_H
