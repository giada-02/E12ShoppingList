//
// Created by Giada on 25/11/2023.
//

#include "Item.h"

Item::Item(const std::string &n, int q) : name(n), qty(q) {
    if (q <= 0) {
        // q is set to default (1)
        q = 1;
    }
}