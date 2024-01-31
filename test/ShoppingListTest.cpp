//
// Created by Giada on 30/01/2024.
//

#include "gtest/gtest.h"

#include "../ShoppingList.h"

TEST(ShoppingList, TestItemNotFound){
    ShoppingList sl("sl");
    ASSERT_FALSE(sl.findItem("item"));
}

TEST(ShoppingList, TestAddItem){
    ShoppingList sl("sl");
    sl.addItem("category", "item");
    ASSERT_TRUE(sl.findCategory("category"));
    ASSERT_TRUE(sl.findItem("item")); //the right characteristics of the added Item are guaranteed
    // through the test carried out in CategoryTest
}