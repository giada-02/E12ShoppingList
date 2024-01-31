//
// Created by Giada on 26/11/2023.
//

#include "Category.h"

Category::Category(const std::string &n) : name(n){}

void Category::addItem(const std::string &itemName, int itemQty, bool bought) {
    auto itr = items.find(itemName);
    if (itr != items.end()){
        try {
            int quantity = itr->second.getQty();
            itr->second.setQty(itemQty); //throws exception if itemQty <= 0
            itr->second.setQty(quantity + itemQty);
        } catch (std::out_of_range& e){
            std::cerr << e.what() << " is not an acceptable quantity" << std::endl;
        }
    } else {

        try {
            Item item(itemName, itemQty, bought);
            items.insert(std::make_pair(itemName, item));
        } catch (std::out_of_range& e) {
            std::cerr << e.what() << " is set to default (1)" << std::endl;
            Item item(itemName, 1, bought);
            items.insert(std::make_pair(itemName, item));
        }

    }
}

void Category::removeItem(const std::string &itemName) {
    auto itr = items.find(itemName);
    if(itr != items.end())
        items.erase(itr->first);
    else
        throw std::invalid_argument(itemName + " not found");
}

void Category::setItemBought(const std::string &itemName) {
    auto itr = items.find(itemName);
    if(itr != items.end())
        itr->second.setBought(true);
    else
        throw std::invalid_argument(itemName + " not found");
}

void Category::setItemToBuy(const std::string &itemName) {
    auto itr = items.find(itemName);
    if(itr != items.end())
        itr->second.setBought(false);
    else
        throw std::invalid_argument(itemName + " not found");
}

std::array<int, 3> Category::getNumItems() const {
    std::array<int, 3> result  = {0, 0, 0};
    for (const auto& item : items){
        if(item.second.isBought()){
            result[1] += item.second.getQty(); //number of items bought
        } else {
            result[2] += item.second.getQty(); //number of items to buy
        }
    }
    result[0] = result[1] + result[2]; //total number of items
    return result;
}

void Category::printItems() const {
    std::cout << "Category: " << name << std::endl;
    for (const auto& item : items){
        std::string boughtCheck = "x";
        if (item.second.isBought()){
                boughtCheck = "v";
        }
        std::cout << "Item: " << item.first << " - " << item.second.getQty() << " " << boughtCheck << std::endl;
    }
}

const Item& Category::findItem(const std::string &itemName) const {
    auto itr = items.find(itemName);
    if(itr != items.end())
        return itr->second;
    else
        throw std::invalid_argument(itemName + " not found");
}