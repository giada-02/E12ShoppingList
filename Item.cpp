//
// Created by Giada on 25/11/2023.
//

#include "Item.h"

Item::Item(const std::string &n, int q, bool b) : name(n), qty(q), bought(b) {
    if (q <= 0) {
        throw std::out_of_range("NEGATIVE or ZERO item quantity");
    }
}
