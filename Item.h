//
// Created by Giada on 25/11/2023.
//

#ifndef LISTASPESA_ITEM_H
#define LISTASPESA_ITEM_H

#include <iostream>
#include <string>

class Item {
public:
    explicit Item(const std::string& n, int q = 1);

    std::string getName() const{
        return name;
    }
    int getQty() const{
        return qty;
    }
    void setQty(int q){
        qty = q;
    };

private:
    std::string name;
    int qty;
};


#endif //LISTASPESA_ITEM_H
