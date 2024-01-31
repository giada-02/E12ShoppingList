//
// Created by Giada on 25/11/2023.
//

#include "User.h"

User::User(const std::string &userId) : userID(userId){
    numItems = {0,0,0};
}

User::~User() {
    for (const auto list : lists){
        list->unsubscribe(this);
    }
}

void User::update() {
    //std::cout << "User " << userID << " has been notified of changes to their lists" << std::endl;
    numItems = {0,0,0};
    for(const auto list : lists){
        std::array<int, 3> numItemsList = list->getNumItemsList();
        numItems[0] += numItemsList[0];
        numItems[1] += numItemsList[1];
        numItems[2] += numItemsList[2];
    }
}

void User::addList(std::shared_ptr<ShoppingList> list) {
    lists.push_back(list);
    lists.back()->subscribe(this);
}

void User::removeList(std::shared_ptr<ShoppingList> list) {
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
    std::cout << "TOT: " << numItems[0]  << " of which BOUGHT: " << numItems[1] << " - TO BUY: " << numItems[2] << std::endl;
}