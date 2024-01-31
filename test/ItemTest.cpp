//
// Created by Giada on 19/01/2024.
//
#include "gtest/gtest.h"

#include "../Item.h"

TEST(Item, DefaultConstructor) {
    Item item("item");
    ASSERT_EQ("item", item.getName());
    ASSERT_EQ(1, item.getQty());
    ASSERT_EQ(false, item.isBought());
}

TEST(Item, out_of_range_negative) {
    ASSERT_THROW(Item itemNegative("itemNegative", -2), std::out_of_range);
}

TEST(Item, out_of_range_zero) {
    ASSERT_THROW(Item itemZero("itemZero", 0), std::out_of_range);
}