#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
private:
    std::string name;
    int value;

    public:
        Item() {}
        Item(const std::string &name, const int &value) {
            this->name = name;
            this->value = value;
        }
        ~Item() {

        }

        std::string getName() const {
            return name;
        }

        int getValue() const {
            return value;
        }
};

#endif // ITEM_H
