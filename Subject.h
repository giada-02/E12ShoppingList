//
// Created by Giada on 25/11/2023.
//

#ifndef LISTASPESA_SUBJECT_H
#define LISTASPESA_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    virtual void notify() = 0;
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
};


#endif //LISTASPESA_SUBJECT_H
