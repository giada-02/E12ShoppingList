//
// Created by Giada on 25/11/2023.
//

#ifndef LISTASPESA_USER_H
#define LISTASPESA_USER_H

#include <iostream>
#include <list>

#include "Observer.h"
#include "ShoppingList.h"

class User : public Observer{
public:
    explicit User(const std::string& userID);
    virtual ~User(){}

    void update() override;

    void addList(ShoppingList* list);
    void removeList(ShoppingList* list);

    void displayAll() const;


private:
    std::string userID;
    int numItems;
    std::list<ShoppingList*> lists;
};


#endif //LISTASPESA_USER_H
