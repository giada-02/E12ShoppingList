//
// Created by Giada on 25/11/2023.
//

#ifndef LISTASPESA_SHOPPINGLIST_H
#define LISTASPESA_SHOPPINGLIST_H

#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <memory>

#include "Subject.h"
#include "Category.h"
#include "Item.h"

class ShoppingList : public Subject {
public:
    explicit ShoppingList(const std::string& n);
    virtual ~ShoppingList(){}

    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;

    void addItem(const std::string &ctyName, const std::string &itemName, int itemQty = 1, bool bought = false);
    void removeItem(const std::string &ctyName, const std::string &itemName);
    void setItemBought(const std::string &ctyName, const std::string &itemName);
    void setItemToBuy(const std::string &ctyName, const std::string &itemName);
    std::array<int, 3> getNumItemsList() const;
    void printList() const;

    int getSize() const{
        return categories.size();
    }

    bool findItem(const std::string &itemName) const;
    bool findCategory(const std::string &ctyName) const;

private:
    std::string name;
    std::map<std::string, Category> categories;
    std::list<Observer*> observers;
};


#endif //LISTASPESA_SHOPPINGLIST_H
