//
// Created by Giada on 27/01/2024.
//
#include "gtest/gtest.h"

#include "../Category.h"

class CategorySuite : public ::testing::Test {
protected:
    void SetUp() override{
        c->addItem("item0");
        c->addItem("item1", 0, true);
        c->addItem("item2", 7);
        c->addItem("item3", -3, true);
    }

    Category *c = new Category("c");

    void TearDown() override{
        delete c;
    }
};

TEST_F(CategorySuite, TestGetNumItems) {
    ASSERT_EQ(4, c->getSize());
    ASSERT_EQ(10, c->getNumItems()[0]);
    ASSERT_EQ(2, c->getNumItems()[1]);
    ASSERT_EQ(8, c->getNumItems()[2]);
}

TEST_F(CategorySuite, TestRemoveItem) {
    c->removeItem("item0");
    ASSERT_THROW(c->findItem("item0"), std::invalid_argument);
    ASSERT_EQ(9, c->getNumItems()[0]);
    ASSERT_EQ(2, c->getNumItems()[1]);
    ASSERT_EQ(7, c->getNumItems()[2]);
    ASSERT_THROW(c->removeItem("item"), std::invalid_argument);
}

TEST_F(CategorySuite, TestSetItemBought){
    c->setItemBought("item1");
    ASSERT_TRUE(c->findItem("item1").isBought());
    c->setItemBought("item2");
    ASSERT_TRUE(c->findItem("item2").isBought());
    ASSERT_THROW(c->setItemBought("item"), std::invalid_argument);
}

TEST_F(CategorySuite, TestSetItemToBuy){
    c->setItemToBuy("item2");
    ASSERT_FALSE(c->findItem("item2").isBought());
    c->setItemToBuy("item3");
    ASSERT_FALSE(c->findItem("item3").isBought());
    ASSERT_THROW(c->setItemToBuy("item"), std::invalid_argument);
}