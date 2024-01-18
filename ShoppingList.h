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

    void addItem(const std::string &ctyName, const std::string &itemName, int itemQty = 1);
    void removeItem(const std::string &ctyName, const std::string& itemName, int itemQty = 1); //removes selected item from selected category
    void removeItem(const std::string& itemName, int itemQty = 1); //removes selected item from all categories
    void printList() const;
    int getNumItemsList() const;

private:
    std::string name;
    std::map<std::string, Category> categories;
    std::list<Observer*> observers;
};


#endif //LISTASPESA_SHOPPINGLIST_H
