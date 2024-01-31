//
// Created by Giada on 26/11/2023.
//

#ifndef LISTASPESA_CATEGORY_H
#define LISTASPESA_CATEGORY_H

#include <iostream>
#include <string>
#include <map>

#include "Item.h"

class Category {
public:
    explicit Category(const std::string& n);

    void addItem(const std::string &itemName, int itemQty = 1, bool bought = false);
    void removeItem(const std::string &itemName);
    void setItemBought(const std::string &itemName);
    void setItemToBuy(const std::string &itemName);
    std::array<int, 3> getNumItems() const;
    void printItems() const;

    int getSize() const{
        return items.size();
    }

    const Item& findItem(const std::string& itemName) const;

private:
    std::string name;
    std::map<std::string, Item> items;
};


#endif //LISTASPESA_CATEGORY_H
