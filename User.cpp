//
// Created by Giada on 25/11/2023.
//

#include "User.h"

User::User(const std::string &userId) : userID(userId){
    numItems = 0;
}

void User::update() {
    //std::cout << "User " << userID << " has been notified of changes to their lists" << std::endl;
    numItems = 0;
    for(const auto list : lists){
        numItems += list->getNumItemsList();
    }
}

void User::addList(ShoppingList* list) {
    lists.push_back(list);
    lists.back()->subscribe(this);
}

void User::removeList(ShoppingList* list) {
    auto itr = std::find(lists.begin(), lists.end(), list);
    if (itr!=lists.end()) {
        list->unsubscribe(this);
        lists.remove(list);
        update();
    }
}

void User::displayAll() const {
    std::cout << '\n' << "ALL SHOPPING LISTS OWNED BY " << userID << std::endl;
    for (const auto list : lists){
        list->printList();
    }
    std::cout << "TOT: " << numItems << std::endl;
}