//
// Created by Giada on 27/01/2024.
//
#include "gtest/gtest.h"

#include "../Category.h"

class CategorySuite : public ::testing::Test {
protected:
    void SetUp() override{
        c->addItem("item0");
        c->addItem("item1", 0);
        c->addItem("item2", 7);
        c->addItem("item3", -3);
    }

    Category *c = new Category("c");

    void TearDown() override{
        delete c;
    }
};

TEST_F(CategorySuite, TestGetNumItems) {
    ASSERT_EQ(10, c->getNumItems());
}

TEST_F(CategorySuite, TestRemoveItemOne) {
    c->removeItem("item0");
    ASSERT_FALSE(c->findItem("item0"));
}

TEST_F(CategorySuite, TestRemoveItemMore) {
    c->removeItem("item2", 4); //7>4 now 3 left
    ASSERT_TRUE(c->findItem("item2"));
    c->removeItem("item2", 5); //3<=5 all removed, no more left
    ASSERT_FALSE(c->findItem("item2"));
}