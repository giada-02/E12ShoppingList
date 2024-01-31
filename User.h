//
// Created by Giada on 25/11/2023.
//

#ifndef LISTASPESA_USER_H
#define LISTASPESA_USER_H

#include <iostream>
#include <list>
#include <memory>

#include "Observer.h"
#include "ShoppingList.h"

class User : public Observer{
public:
    explicit User(const std::string& userID);
    virtual ~User();

    void update() override;

    void addList(std::shared_ptr<ShoppingList> list);
    void removeList(std::shared_ptr<ShoppingList> list);
    void displayAll() const;

    int getNumLists() const{
        return lists.size();
    }

private:
    std::string userID;
    std::array<int, 3> numItems;
    std::list<std::shared_ptr<ShoppingList>> lists;
};


#endif //LISTASPESA_USER_H
