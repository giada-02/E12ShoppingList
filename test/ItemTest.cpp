//
// Created by Giada on 19/01/2024.
//
#include "gtest/gtest.h"

#include "../Item.h"

TEST(Item, DefaultConstructor) {
    try {
        Item item("item");
        ASSERT_EQ(1, item.getQty());
    } catch (...) {
        FAIL();
    }
}

TEST(Item, out_of_range_negative) {
    try {
        Item itemNegative("itemNegative", -2);
        FAIL();
    } catch (std::out_of_range &e) {
        EXPECT_STREQ("NEGATIVE or ZERO item quantity", e.what());
    } catch (...) {
        FAIL();
    }
}

TEST(Item, out_of_range_zero) {
    try{
        Item itemZero("itemZero", 0);
        FAIL();
    } catch(std::out_of_range &e) {
        EXPECT_STREQ("NEGATIVE or ZERO item quantity", e.what());
    } catch(...) {
        FAIL();
    }
}
