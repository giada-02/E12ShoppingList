//
// Created by Giada on 25/11/2023.
//

#include "ShoppingList.h"

ShoppingList::ShoppingList(const std::string &n) : name(n){}

void ShoppingList::notify() {
    for (const auto observer : observers){
        observer->update();
    }
}

void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
    notify();
}

void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
    notify();
}

void ShoppingList::addItem(const std::string &ctyName, const std::string &itemName, int itemQty) {
    auto itr = categories.find(ctyName);
    if(itr != categories.end()) { //category is already in the shopping list, must find item and add
        itr->second.addItem(itemName, itemQty);
    } else { //category is not in the shopping list, it must be created, put the item in and added to the shopping list
        Category category(ctyName);
        category.addItem(itemName, itemQty);
        categories.insert(std::make_pair(ctyName, category));
    }
    notify();
}

void ShoppingList::removeItem(const std::string &ctyName, const std::string &itemName, int itemQty) {
    auto itr = categories.find(ctyName);
    if(itr != categories.end()) { //category found, item removed
        itr->second.removeItem(itemName, itemQty);
        if(itr->second.getSize() == 0){ //if the category is empty it must be erased
            categories.erase(ctyName);
        }
    }
    notify();
}

void ShoppingList::removeItem(const std::string& itemName, int itemQty) {
    for(auto itr = categories.begin(); itr != categories.end(); itr++) {
        itr->second.removeItem(itemName, itemQty);
        if (itr->second.getSize() == 0) { //if the category is empty it must be erased
            categories.erase(itr->first);
        }
    }
    notify();
}

void ShoppingList::printList() const {
    std::cout << "List: " << name << std::endl;
    for(const auto& category : categories){
            category.second.printItems();
    }
    std::cout << getNumItemsList() << " items in " << name << std::endl;
}

int ShoppingList::getNumItemsList() const {
    int result = 0;
    for(const auto& category : categories){
        result += category.second.getNumItems();
    }
    return result;
}