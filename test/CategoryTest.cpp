//
// Created by Giada on 27/01/2024.
//

#include "gtest/gtest.h"

#include "../Category.h"

TEST(Category, TestItemNotFound){
    Category c("c");
    ASSERT_THROW(c.findItem("item"), std::invalid_argument);
}

TEST(Category, TestAddItem){
    Category c("c");
    c.addItem("item", 6, true);
    ASSERT_EQ("item", c.findItem("item").getName());
    ASSERT_EQ(6, c.findItem("item").getQty());
    ASSERT_TRUE(c.findItem("item").isBought());
}

TEST(Category, TestAddItemWithNegativeQuantity){
    Category c("c");
    c.addItem("itemNegative", -3);
    ASSERT_EQ(1, c.findItem("itemNegative").getQty());
}

TEST(Category, TestAddItemWithZeroQuantity){
    Category c("c");
    c.addItem("itemZero", 0);
    ASSERT_EQ(1, c.findItem("itemZero").getQty());
}