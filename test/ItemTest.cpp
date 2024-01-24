//
// Created by Giada on 19/01/2024.
//
#include "gtest/gtest.h"

#include "../Item.h"

TEST(Item, DefaultConstructor){
    Item item("item");
    ASSERT_EQ(1, item.getQty());
}

TEST(Item, out_of_range){
    try{
        Item itemNegative("itemNegative", -2);
        FAIL();
    } catch(std::out_of_range &e){
        EXPECT_STREQ("NEGATIVE or ZERO item quantity", e.what());
    } catch(...){
        FAIL();
    }

    try{
        Item itemZero("itemZero", 0);
        FAIL();
    } catch(std::out_of_range &e) {
        EXPECT_STREQ("NEGATIVE or ZERO item quantity", e.what());
    } catch(...){
        FAIL();
    }
}
