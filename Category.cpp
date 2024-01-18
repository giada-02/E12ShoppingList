//
// Created by Giada on 26/11/2023.
//

#include "Category.h"

Category::Category(const std::string &n) : name(n){}

void Category::addItem(const std::string &itemName, int itemQty) {
    auto itr = items.find(itemName);
    if (itr!=items.end()){
        itr->second.setQty(itr->second.getQty() + itemQty);
    } else {
            Item item(itemName, itemQty);
            items.insert(std::make_pair(itemName, item));
    }
}

void Category::removeItem(const std::string &itemName, int itemQty) {
    auto itr = items.find(itemName);
    if(itr != items.end()){
        if (itr->second.getQty() > itemQty) {
            itr->second.setQty(itr->second.getQty() - itemQty);
        } else {
            items.erase(itr->first);
        }
    }
}

void Category::printItems() const {
    std::cout << "Category: " << name << std::endl;
    for (const auto& item : items){
        std::cout << "Item: " << item.first << " - " << item.second.getQty() << std::endl;
    }
}