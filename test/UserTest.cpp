//
// Created by Giada on 31/01/2024.
//

#include "gtest/gtest.h"

#include "../User.h"

TEST(User, TestAddList){
    User user("user");
    std::shared_ptr<ShoppingList> sl0 = std::make_shared<ShoppingList>("sl0");
    std::shared_ptr<ShoppingList> sl1 = std::make_shared<ShoppingList>("sl1");
    user.addList(sl0);
    user.addList(sl1);
    ASSERT_EQ(2, user.getNumLists());
}

TEST(User, TestRemoveList){
    User user("user");
    std::shared_ptr<ShoppingList> sl = std::make_shared<ShoppingList>("sl");
    user.addList(sl);
    user.removeList(sl);
    ASSERT_EQ(0, user.getNumLists());
}