//
// Created by Giada on 27/01/2024.
//

#include "gtest/gtest.h"

#include "../Category.h"

TEST(Category, TestAddItem) {
    Category c("c");
    c.addItem("item");
    ASSERT_TRUE(c.findItem("item"));
}