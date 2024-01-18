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

    void addItem(const std::string &itemName, int itemQty = 1);
    void removeItem(const std::string &itemName, int itemQty = 1);
    void printItems() const;

    int getSize() const{
        return items.size();
    }

    int getNumItems() const{
        int sum = 0;
        for (const auto& item : items){
            sum += item.second.getQty();
        }
        return sum;
    }

private:
    std::string name;
    std::map<std::string, Item> items;
};


#endif //LISTASPESA_CATEGORY_H
