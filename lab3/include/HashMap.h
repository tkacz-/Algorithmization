#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <iomanip>
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

    void put( std::string key, T value ) {
        int hashCode = hash( key );

        Node *temp = new Node(key, value);
        if ( table[hashCode] != nullptr ) {
            temp->setNext(table[hashCode]);
            table[hashCode] = temp;
        } else {
            table[hashCode] = temp;
        }
    }

    T find( std::string key, T value ) {
        int hashCode = hash( key );
        bool isFound = false;
        Node* temp = table[hashCode];
        while ( temp != nullptr ) {
            if ( temp->getValue() == value ) {
                isFound = true;
                break;
            }
            temp = temp->getNext();
        }
        if ( isFound )
            return "Found!";
        if ( isFound == false )
            return "Not Found!";
    }

    void show( int hashCode ) {
        std::cout << std::setw(20);
        if ( table[hashCode] == nullptr ) {
            std::cout << "" << std::endl;
        } else {
            Node* temp = table[hashCode];
            while ( temp != nullptr ) {
                std::cout << temp->getValue() << ", ";
                temp = temp->getNext();
            }
            std::cout << std::endl;
        }
    }
private:
    class Node {
    private:
        std::string key_;
        T value_;
        Node* next_;
    public:
        Node(const std::string& key, const T& value):
            key_(key),
            value_(value),
            next_(nullptr)
        {}
        Node() {}
        T getValue() const {
            return value_;
        }
        std::string getKey() const {
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

    int hash( std::string key ) {
        int hashCode = accumulate( key.begin(), key.end(), 0);
        return (hashCode % TABLE_SIZE);
    }
};

#endif // HASHMAP_H
