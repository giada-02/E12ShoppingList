//
// Created by Giada on 25/11/2023.
//

#ifndef LISTASPESA_ITEM_H
#define LISTASPESA_ITEM_H

#include <iostream>
#include <string>

class Item {
public:
    explicit Item(const std::string& n, int q = 1, bool bought = false);

    const std::string& getName() const{
        return name;
    }

    int getQty() const{
        return qty;
    }

    void setQty(int q){ //quantity must be > 0
        if (q<=0)
            throw std::out_of_range("NEGATIVE or ZERO item quantity");
        qty = q;
    }

    bool isBought() const{
        return bought;
    }

    void setBought(bool b){
        bought = b;
    }

private:
    std::string name;
    int qty;
    bool bought;
};


#endif //LISTASPESA_ITEM_H
