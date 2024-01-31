//
// Created by Giada on 30/01/2024.
//

#include "gtest/gtest.h"

#include "../ShoppingList.h"

class ShoppingListSuite : public ::testing::Test {
protected:
    void SetUp() override{
        sl->addItem("cty0", "item00");
        sl->addItem("cty0", "item01", 4, true);
        sl->addItem("cty0", "item02", 7);
        sl->addItem("cty0", "item03", 2, true);
        sl->addItem("cty1", "item10", 8, true);
        sl->addItem("cty1", "item11", 2);
        sl->addItem("cty2", "item20", 10);
        sl->addItem("cty2", "item21");
        sl->addItem("cty3", "item30", -1, true);
    }

    ShoppingList *sl = new ShoppingList("sl");

    void TearDown() override{
        delete sl;
    }
};

TEST_F(ShoppingListSuite, TestGetNumItems){
    ASSERT_EQ(4, sl->getSize());
    ASSERT_EQ(36, sl->getNumItemsList()[0]);
    ASSERT_EQ(15, sl->getNumItemsList()[1]);
    ASSERT_EQ(21, sl->getNumItemsList()[2]);
}

TEST_F(ShoppingListSuite, TestRemoveItem){
    sl->removeItem("cty0", "item01");
    ASSERT_FALSE(sl->findItem("item01"));
    ASSERT_TRUE(sl->findCategory("cty0"));
    ASSERT_EQ(32, sl->getNumItemsList()[0]);
    ASSERT_EQ(11, sl->getNumItemsList()[1]);
    ASSERT_EQ(21, sl->getNumItemsList()[2]);

    sl->removeItem("cty3", "item30");
    ASSERT_FALSE(sl->findItem("item30"));
    ASSERT_FALSE(sl->findCategory("cty3"));
}