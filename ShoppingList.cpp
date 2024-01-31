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

void ShoppingList::addItem(const std::string &ctyName, const std::string &itemName, int itemQty, bool bought) {
    auto itr = categories.find(ctyName);
    if(itr != categories.end()) { //category is already in the shopping list, must find item and add
        itr->second.addItem(itemName, itemQty, bought);
    } else { //category is not in the shopping list, it must be created, put the item in and added to the shopping list
        Category category(ctyName);
        category.addItem(itemName, itemQty, bought);
        categories.insert(std::make_pair(ctyName, category));
    }
    notify();
}

void ShoppingList::removeItem(const std::string &ctyName, const std::string &itemName) {
    auto itr = categories.find(ctyName);
    if(itr != categories.end()) { //category found, item removed
        try{
            itr->second.removeItem(itemName);
            if(itr->second.getSize() == 0){ //if the category is empty it must be erased
                categories.erase(ctyName);
            }
        } catch (std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    notify();
}

void ShoppingList::setItemBought(const std::string &ctyName, const std::string &itemName) {
    auto itr = categories.find(ctyName);
    if(itr != categories.end()) {
        try{
            itr->second.setItemBought(itemName);
        } catch (std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    notify();
}

void ShoppingList::setItemToBuy(const std::string &ctyName, const std::string &itemName) {
    auto itr = categories.find(ctyName);
    if(itr != categories.end()) {
        try{
            itr->second.setItemToBuy(itemName);
        } catch (std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    notify();
}

void ShoppingList::printList() const {
    std::cout << "List: " << name << std::endl;
    for(const auto& category : categories){
            category.second.printItems();
    }
    std::cout << "Total items in " << name << " : " << getNumItemsList()[0] << std::endl;
}

std::array<int, 3> ShoppingList::getNumItemsList() const {
    std::array<int, 3> result = {0, 0, 0};
    for (const auto& category : categories){
        std::array<int, 3> resultCty = category.second.getNumItems();
        result[1] += resultCty[1];
        result[2] += resultCty[2];
    }
    result[0] = result[1]+result[2];
    return result;
}

bool ShoppingList::findItem(const std::string &itemName) const {
    bool found = false;
    auto category = categories.begin();
    while(category != categories.end() && found == false){
        try {
            const Item& foundItem = category->second.findItem(itemName); //if item not found in the category it throws exception
            found = true; //if item found bool value found is set to true
        } catch (std::invalid_argument &e){}
        category++;
    }
    return found;
}

bool ShoppingList::findCategory(const std::string &ctyName) const {
    auto cty = categories.find(ctyName);
    if (cty != categories.end())
        return true;
    else
        return false;
}